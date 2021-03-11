package main

import (
	"errors"
	"fmt"
	"log"

	"github.com/MrWaggel/gosteamconv"
)

// ErrRange indicates that a value is out of range for the target type.
var ErrRange = errors.New("value out of range")

func main() {
	rankInt := 13 //13 = Master Guardian Elite
	rankResult, err := ReturnRankString(rankInt)
	checkErr(err)
	fmt.Println(rankResult)

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
