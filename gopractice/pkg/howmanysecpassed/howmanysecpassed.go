package howmanysecpassed

import (
	"fmt"
	"time"
)

func Start() time.Time {
	startTime := time.Now()
	return startTime
}

func Print(startTime time.Time) {
	elapsedTime := time.Since(startTime)
	fmt.Printf("ElapsedTime: %s\n", elapsedTime)
}

func End(startTime time.Time) time.Duration {
	elapsedTime := time.Since(startTime)
	return elapsedTime
}
