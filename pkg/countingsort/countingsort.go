package countingsort

func Ints(arr []int) []int {
	var i int
	var length = len(arr)

	var max int = arr[0]
	for i = 0; i < length; i++ {
		if arr[i] >= max {
			max = arr[i]
		}
	}
	counting := make([]int, max+1) //배열에서의 가장 큰 숫자 -> 배열의 크기

	result := make([]int, length) //본배열과 같은 크기
	for i = 0; i < length; i++ {
		counting[arr[i]]++
		//배열에서 숫자의 갯수를 counting에 저장
	}

	for i = 1; i <= max; i++ { //누적합으로 만들기
		counting[i] += counting[i-1]
	}

	for i = length - 1; i >= 0; i-- {
		value := arr[i]
		counting[value]--
		result[counting[value]] = value
	}
	return result
}
