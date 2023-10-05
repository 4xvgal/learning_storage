package stringconv

import (
	"bufio"
	"strings"
)

// 유저정보가 시작되는 곳의 줄 번호를 리턴 (#으로 시작)
func SearchingStartLine(source []string) (int, error) {
	var i int = 0
	for {
		if strings.Contains(source[i], "#") {
			return i, nil
		} else {
			i++
		}
	}
}

// 유저정보가 끝나는 곳의 줄 번호를 리턴
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

// 바이트를 문자열로 변환
func BytesToString(data []byte) string {
	return string(data[:])
}

// String 을 Line으로 변환
func StringToLines(s string) (lines []string, err error) {
	scanner := bufio.NewScanner(strings.NewReader(s))
	for scanner.Scan() {
		lines = append(lines, scanner.Text())
	}
	err = scanner.Err()
	return lines, err
}
