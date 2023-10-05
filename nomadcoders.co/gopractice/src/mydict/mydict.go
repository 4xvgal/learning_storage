package mydict

import "errors"

//Dictionary type
type Dictionary map[string]string

//error 변수
var errNotFound = errors.New("Not Found")
var errWordExists = errors.New("That word already exists")
var errCantUpdate = errors.New("Cant update non-existing word")
var errCantDelete = errors.New("Cant Delete non-exsting word")

//Search for a word
func (d Dictionary) Search(word string) (string, error) {
	value, exists := d[word]
	//if word is exists return 1, else return 0
	//if 1, return value
	if exists {
		return value, nil
	}
	return "", errNotFound
}

//Add a word and definition
func (d Dictionary) Add(word, def string) error {
	_, err2 := d.Search(word)
	if err2 != nil {
		d[word] = def
	} else if err2 == nil {
		return errWordExists
	}
	return nil
}

//Update a word
func (d Dictionary) Update(word, definition string) error {
	_, err := d.Search(word)
	switch err {
	case nil:
		d[word] = definition
	case errNotFound:
		return errCantUpdate
	}
	return nil
}

//Delete a word
func (d Dictionary) Delete(word string) error {
	_, err := d.Search(word)
	switch err {
	//Search 함수에서 에러가 없을 경우 => 단어가 있다.
	case nil:
		delete(d, word)
	//단어가 없을경우 에러 리턴
	case errNotFound:
		return errCantDelete
	}
	return nil
}
