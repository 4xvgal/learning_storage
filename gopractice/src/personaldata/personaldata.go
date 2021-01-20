package personaldata

//Person 은 개인정보 구조체
type Person struct {
	name string
	age  int
}

//Newperson 은 새로운 사람의 구조체를 생성한다.
func Newperson(newname string, newage int) *Person {
	newperson := Person{name: newname, age: newage}
	return &newperson
}
