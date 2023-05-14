//ch7-2-2.cpp
//세 개의 == 연산자를 프렌드 함수로 작성하라.
#include<iostream>
#include<string>

using namespace std;
class Book {
	string title;
	int price, pages;
public:
	Book(string title="",int price =0, int pages =0) { //매개변수 중복
		this-> title = title; this -> price = price; this -> pages = pages;
	}
	void show(){
		cout << title << ' '<< price <<"원 " << pages << " 페이지" <<  endl;
	}
	string getTitle() {
		return title;
    }
    friend bool operator==(Book& op, int pr);       //price 비교
    friend bool operator==(Book& op, string a);     //책 title 비교
    friend bool operator==(Book& op1, Book& op2);   //책의 titile,price,pages 모두 비교
};

bool operator==(Book& op, int pr){
    if(op.price == pr){
        return true;
    } 
    return false;
}

bool operator==(Book& op, string a){
    if(op.title == a){
        return true;
    }
    return false;
}

bool operator==(Book& op1, Book& op2){
    if(op1.title == op2.title && op1.price == op2.price && op1.pages == op2.pages){
        return true;
    }
    return false;
}
int main(){
	Book a("명품 C++", 30000, 500), b("고품 C++", 30000, 500);
    if(a == 30000) cout << "정가 30000원" << endl; //price 비교
    if(a == "명품 C++") cout << "명품 C++ 입니다." << endl; //책 title 비교
    if(a==b) cout << "두 책이 같은 책입니다." <<  endl;
}