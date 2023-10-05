// 에러를 로그에 기록할 수 있도록 합니다.
// 에러가 검출되면 코드가 중단됩니다.
package errorhandling

import (
	"log"
)

func CheckErr(err error) {
	if err != nil {
		log.Fatalln(err)
	}
}
