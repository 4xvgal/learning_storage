package main

import (
	"bufio"
	"errors"
	"fmt"
	"io/ioutil"
	"log"
	"strconv"
	"strings"

	"github.com/MrWaggel/gosteamconv"
)

// ErrRange indicates that a value is out of range for the target type.
var ErrRange = errors.New("value out of range")

//struct for dataset
// userid name uniqueid connected ping loss state rate
type Data struct {
	userid    int
	name      string
	uniqueid  string
	steamID   int
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
	dir := "data\\sample.txt"

	txt_byte, err := ioutil.ReadFile(dir)
	checkErr(err)
	txt_string := BytesToString(txt_byte)
	txt_lines, err = StringToLines(txt_string)
	checkErr(err)

	startLine, err := SearchingStartLine(txt_lines)
	checkErr(err)
	endLine, err := SearchingEndLine(txt_lines)
	checkErr(err)

	output_data = StringsToStruct(txt_lines, startLine, endLine)

	fmt.Println(output_data)
}

//func stringToInt
func stringToInt(steamid string) int64 {
	steam64, err := gosteamconv.SteamStringToInt64(steamid)
	checkErr(err)
	return steam64
}

//checkErr is checking err from error
func checkErr(err error) {
	if err != nil {
		log.Fatalln(err)
	}
}

//ReturnRankString is return rank info to string
//example rank := ReturnRankString(13)
//function return "Master Guardian Elite"
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

//ExtractSteamID extract steamID from one string line
func ExtractSteamID(source string) (string, error) {
	var steamID string
	var steamIDlocation int
	var notfound = errors.New("SteamID Not Found")
	if strings.Contains(source, "STEAM") != true {
		return "", notfound
	} else {
		steamIDlocation = strings.Index(source, "STEAM")
		steamID = source[steamIDlocation:18]
	}
	return steamID, nil
}

//유저정보가 시작되는 곳의 줄 번호를 리턴
func SearchingStartLine(source []string) (int, error) {
	var i int = 0
	for {
		if strings.Contains(source[i], "#") == true {
			return i, nil
		} else {
			i++
		}
	}
}
func SearchingEndLine(source []string) (int, error) {
	var i int = 0
	for {
		if strings.Contains(source[i], "end") == true {
			return i, nil
		} else {
			i++
		}
	}
}

func BytesToString(data []byte) string {
	return string(data[:])
}

func StringToLines(s string) (lines []string, err error) {
	scanner := bufio.NewScanner(strings.NewReader(s))
	for scanner.Scan() {
		lines = append(lines, scanner.Text())
	}
	err = scanner.Err()
	return lines, err
}

// StringsToStruct save data into struct line by line
func StringsToStruct(source []string, startLine int, endLine int) (processedString []Data) {

	var num_line = endLine - startLine - 1 //필요한 줄의 총갯수
	var arr = 0
	//var lines []string
	processedString = make([]Data, num_line)
	fmt.Println(len(processedString))
	fmt.Println("make([]Data, num_line) completed")

	for i := startLine + 1; i <= endLine-1; i++ {
		lines := strings.Fields(source[i])
		fmt.Println(len(lines))
		processedString[arr].userid = arr + 1
		processedString[arr].name = lines[3]
		processedString[arr].uniqueid = lines[4]
		//tmp, _ := strconv.Atoi(lines[4])
		//processedString[arr].steamID, _ = gosteamconv.SteamInt64ToString(tmp)
		processedString[arr].connected = lines[5]
		processedString[arr].ping, _ = strconv.Atoi(lines[6])
		processedString[arr].loss, _ = strconv.Atoi(lines[7])
		processedString[arr].state = lines[8]
		processedString[arr].rate, _ = strconv.Atoi(lines[9])
		arr++
	}

	return processedString
}
