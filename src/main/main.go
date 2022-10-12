package main

import (
	"errors"
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"strconv"
	"strings"

	"github.com/MrWaggel/gosteamconv"
	"github.com/PuerkitoBio/goquery"
	"github.com/davecgh/go-spew/spew"
	"github.com/nixz1337/csgorankviewer/src/errorhandling"
	stringconv "github.com/nixz1337/csgorankviewer/src/stringconverter"
)

// ErrRange indicates that a value is out of range for the target type.
var ErrRange = errors.New("value out of range")

// NotFound indicates that there is no search result
var NotFound = errors.New("SteamID Not Found")

// struct for dataset
// userid name uniqueid connected ping loss state rate
type Data struct {
	userid    int
	name      string
	uniqueid  string
	steamID   int64
	connected string
	ping      int
	loss      int
	state     string
	rate      int
	rank      string
}

func main() {
	var output_data []Data
	var txt_lines []string
	dir := "data/sample.txt"
	//goquery
	//var baseURL string = "https://csgostats.gg/player/"
	txt_byte, err := ioutil.ReadFile(dir)
	errorhandling.CheckErr(err)
	txt_string := stringconv.BytesToString(txt_byte)
	txt_lines, err = stringconv.StringToLines(txt_string)
	errorhandling.CheckErr(err)

	startLine, err := stringconv.SearchingStartLine(txt_lines)
	errorhandling.CheckErr(err)
	endLine, err := stringconv.SearchingEndLine(txt_lines)
	errorhandling.CheckErr(err)

	output_data = StringsToStruct(txt_lines, startLine, endLine)
	AddSteamIDIntoStruct(output_data, startLine, endLine)
	spew.Dump(output_data)

	tmp, _ := ExtractSteamID("# 12 11 \"Zoriss\" STEAM_1:1:189554004 00:25 109 0 active 786432")
	fmt.Println(tmp)
	getPage("https://csgostats.gg/player/76561198082728488#/")
}

// func steamstringToInt
func steamstringToInt(steamid string) (int64, error) {
	steam64, err := gosteamconv.SteamStringToInt64(steamid)
	return steam64, err
}

// ReturnRankString is return rank info to string
// example rank := ReturnRankString(13)
// function return "Master Guardian Elite"
func ReturnRankString(rankInt int) (string, error) {
	rankMap := map[int]string{
		1:  "Silver 1",
		2:  "Silver 2",
		3:  "Silver 3",
		4:  "Silver 4",
		5:  "Silver Elite",
		6:  "Silver Eilte Master",
		7:  "Gold Nova 1",
		8:  "Gold Nova 2",
		9:  "Gold Nova 3",
		10: "Gold Nova Master",
		11: "Master Gurdian 1",
		12: "Master Gurdian 2",
		13: "Master Gurdian Elite",
		14: "Distinguished Master Guardian",
		15: "Legendary Eagle",
		16: "Legendary Eagle Master",
		17: "Supreme Master First Class",
		18: "The Global Elite",
	}
	if rankInt <= 0 || rankInt >= 18 {
		return "0", ErrRange
	}
	return rankMap[rankInt], nil
	//returnRankString = rankMap[rankInt]
	//return returnRankString, err
}

// StringsToStruct save data into struct line by line
func StringsToStruct(source []string, startLine int, endLine int) (processedString []Data) {
	var num_line = endLine - startLine - 1 //필요한 줄의 총갯수
	var arr = 0
	//var lines []string
	processedString = make([]Data, num_line)
	for i := startLine + 1; i <= endLine-1; i++ {
		//lines := strings.Fields(source[i])

		processedString[arr].name, _ = ExtractName(source[i])
		processedString[arr].uniqueid, _ = ExtractSteamID(source[i])
		processedString[arr].steamID, _ = gosteamconv.SteamStringToInt64(processedString[arr].uniqueid)
		/*
			processedString[arr].userid = arr + 1
			processedString[arr].uniqueid = lines[4]
			processedString[arr].connected = lines[5]
			processedString[arr].ping, _ = strconv.Atoi(lines[6])
			processedString[arr].loss, _ = strconv.Atoi(lines[7])
			processedString[arr].state = lines[8]
			processedString[arr].rate, _ = strconv.Atoi(lines[9])
		*/
		arr++
	}
	return processedString
}

// ExtractSteamID extract steamID from one string line
func ExtractSteamID(source string) (string, error) {
	var steamID string
	var steamIDStartlocation int
	var steamIDEndlocation int
	if strings.Contains(source, "STEAM") {
		return "", NotFound
	} else {
		steamIDStartlocation = strings.Index(source, "STEAM_")
		tmp := source[steamIDStartlocation:]
		steamIDEndlocation = strings.IndexAny(tmp, " ")
		steamID = tmp[:steamIDEndlocation]
	}
	return steamID, nil
}
func ExtractName(source string) (string, error) {
	var name string
	var nameStartLocation int
	var nameEndLocation int
	if !strings.Contains(source, "\"") {
		return "", NotFound
	} else {
		nameStartLocation = strings.Index(source, "\"")
		tmp := source[nameStartLocation+1:]
		nameEndLocation = strings.Index(tmp, "\"")
		name = tmp[:nameEndLocation]
	}
	return name, nil
}

func AddSteamIDIntoStruct(source []Data, startLine int, endLine int) (destination []Data) {
	var num_line = endLine - startLine - 1
	destination = make([]Data, num_line)
	for i := 0; i < num_line; i++ {
		steam64, err := gosteamconv.SteamStringToInt64(source[i].uniqueid)
		fmt.Println(steam64)
		errorhandling.CheckErr(err)
		destination[i].steamID = steam64
	}
	return destination
}

// goquery section
func getPage(baseURL string) {
	client := &http.Client{}
	req, err := http.NewRequest("GET", baseURL, nil)
	if err != nil {
		log.Fatalln(err)
	}
	req.Header.Set("User-Agent", "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.181 Safari/537.36")
	resp, err := client.Do(req)
	if err != nil {
		log.Fatalln(err)
	}

	defer resp.Body.Close()
	doc, err := goquery.NewDocumentFromReader(resp.Body)
	errorhandling.CheckErr(err)

	//rankurl := doc.Find("div")
	rankurl := doc.Find("div").Each(func(i int, s *goquery.Selection) {
		fmt.Println(strconv.Itoa(i) + "번째" + s.Text())
	})

	fmt.Println(rankurl)

}

// check code from the http Response
func checkCode(res *http.Response) {
	if res.StatusCode != 200 {
		log.Fatalf("Status code err: %d %s", res.StatusCode, res.Status)
	}
}

// CleanString function
func CleanString(str string) string {
	return strings.Join(strings.Fields(strings.TrimSpace(str)), " ")
}
