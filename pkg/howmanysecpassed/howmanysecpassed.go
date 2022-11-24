package howmanysecpassed

import (
	"fmt"
	"time"
)

func Start() time.Time {
	startTime := time.Now()
	return startTime
}

func End(startTime time.Time) {
	elapsedTime := time.Since(startTime)
	fmt.Printf("ElapsedTime: %s\n", elapsedTime)
}
