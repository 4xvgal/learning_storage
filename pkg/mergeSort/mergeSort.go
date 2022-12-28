package mergesort

func MergeSort(items []int) []int {
	if len(items) < 2 {
		return items
	}
	first := MergeSort(items[:len(items)/2]) //주어진 배열을 재귀호출을 통하여 절반으로 계속 나눈다.
	second := MergeSort(items[len(items)/2:])
	return merge(first, second)
}

func merge(a []int, b []int) []int {
	final := []int{}
	i := 0
	j := 0
	for i < len(a) && j < len(b) { //오름차순으로 결과 배열에 쌓기
		if a[i] < b[j] {
			final = append(final, a[i])
			i++
		} else {
			final = append(final, b[j])
			j++
		}
	}
	for ; i < len(a); i++ {
		final = append(final, a[i])
	}
	for ; j < len(b); j++ {
		final = append(final, b[j])
	}
	return final
}
