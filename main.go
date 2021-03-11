package main

import (
	"fmt"
	"log"

	"github.com/MrWaggel/gosteamconv"
)

func main() {
	rankInt := 13 //13 = Master Guardian Elite
	fmt.Println(returnRankString(rankInt))
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

//retrunRankString is return rank info to string
func returnRankString(rankInt int) (string, error) {
	var err error
	var returnRankString string
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
	returnRankString = rankMap[rankInt]

	return returnRankString, err
}
