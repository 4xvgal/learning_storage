//ch7-1-1.cpp

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
	Book& operator += (int price); //연산자 중복함수 선언
	Book& operator -= (int price);
};

Book& Book::operator += (int price){	//+= 에 대한 연산자 함수 구현
	this -> price += price;
	return *this;
}

Book& Book::operator -= (int price){	//-= 에 대한 연산자 함수 구현
	this -> price -= price;
	return *this;
}

int main(){
	Book a("청춘", 20000, 300), b("미래", 30000, 500);
	a += 500;
	b -= 500;
	a.show();
	b.show();	
}