package banking

import "errors"

//Account 은 개인정보 구조체
type Account struct {
	owner   string
	balance int
}

//Newaccount 은 새로운 사람의 구조체를 생성한다.
func Newaccount(newname string) *Account {
	newaccount := Account{owner: newname, balance: 0}
	return &newaccount
}

//Deposit x amount on your account
func (a *Account) Deposit(amount int) {
	a.balance += amount
}

//Balance of your account
func (a Account) Balance() int {
	return a.balance
}

//Withdraw x amount of your account
func (a *Account) Withdraw(amount int) error {
	if a.balance < amount {
		return errors.New("Can't withdraw you are poor")
	}
	a.balance -= amount
	return nil
}

//ChangeOwner of the account
func (a *Account) ChangeOwner(newOwner string) {
	a.owner = newOwner
}

//Owner of the account
func (a Account) Owner() string {
	return a.owner
}
