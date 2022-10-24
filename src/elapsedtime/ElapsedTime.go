package elapsedtime

import (
	"fmt"
	"time"
)

func ElapsedT_start() time.Time {
	startTime := time.Now()
	return startTime
}

func ElapsedT_end(startTime time.Time) {
	elapsedTime := time.Since(startTime)
	fmt.Printf("ElapsedTime: %s\n", elapsedTime)
}
