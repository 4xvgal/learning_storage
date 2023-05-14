//ch7-1-2.cpp
//friend를 사용하여 외부함수로 구현
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
    friend Book operator+=(Book& op1,int price); //Book& <- '&'는 참조 매개변수이다.
    friend Book operator-=(Book& op2,int price); //p334 하단에 설명 있음.  
    //참조 매개변수를 사용하면 매개변수로 객체가 복사되지 않기 때문에 효과적이나, 참조 매개 변수로 원본 객체를 수정할 수 있어 주의해야한다.
};

Book operator+=(Book& op, int price) { //구현부
    op.price += price;
    return op;
}
Book operator-=(Book& op, int price) {
    op.price-= price;
    return op;
}
int main(){
	Book a("청춘", 20000, 300), b("미래", 30000, 500);
	a += 500;
	b -= 500;
	a.show();
	b.show();	
}