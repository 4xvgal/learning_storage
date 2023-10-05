package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	var n int = 5 //입력받을 수 개수
	var tmp int   //입력 버퍼
	var i int
	var counting [10001]int
	var max = 0
	fmt.Fscanln(reader, &n)

	var cnt int = 0
	for i = 0; i < n; i++ {
		cnt++
		fmt.Fscanf(reader, "%d\n", &tmp) //데이터 입력받기
		counting[tmp]++                  //배열에서 숫자의 갯수를 counting에 저장 (1이 몇개인지 2가 몇개인지)

		if tmp >= max {
			max = tmp
		}
	}

	for i = 0; i <= max; i++ {
		if counting[i] != 0 {
			for j := 0; j < counting[i]; j++ { //couning 배열의 갯수만큼 i를 출력
				fmt.Fprintf(writer, "%d\n", i)
			}
		}
	}
}
