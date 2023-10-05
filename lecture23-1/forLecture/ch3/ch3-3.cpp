//ex3-3.cpp
#include<iostream>
using namespace std;
class Account{
private:
    string name;
    int id;
    int balance;
public:
    Account(string name, int id, int balance){ // 계좌 소유주, 계좌번호, 잔액을 입력받는 생성자
        this -> name = name;
        this -> id = id;
        this ->  balance = balance;
    };
    void deposit(int dps){ //balance 멤버 변수에 dps 인자 만큼 더한다.
        balance += dps;
    }
    int withdraw(int with_amount){ //balance 멤버 변수에 with_amount 만큼 뺀다. with_amount를 반환한다.
        balance -= with_amount;
        return with_amount;
    }
    int inquiry(){ // 현재 잔액 반환.
        return balance;
    }
    string getOwner(){ // 계좌 소유주를 반환한다.
        return name;
    }
};
int main(){
    Account a("kitae",1,5000); // id 1번, 잔액 5000원, 이름이 kitae인 계좌 생성
    a.deposit(50000);
    cout << a.getOwner() <<"의 잔액은" << a.inquiry() <<endl;
    int money = a.withdraw(20000);
    cout << a.getOwner() << "의 잔액은" << a.inquiry() << endl;
}