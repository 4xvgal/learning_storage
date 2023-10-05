//ch8-2.cpp
//Circle을 상속받는 NamedCircle를 이용하여 가장 면적이 큰 피자를 구하는 프로그램
#include<iostream>

using namespace std;

class Circle{
private:
	int radius;
public:
	Circle(int radius = 0) {this -> radius = radius;}
	int getRadius() { return radius;}
	void setRadius(int radius) { this-> radius = radius;}
	double getArea() {return 3.14*radius*radius;}
};
class NamedCircle : public Circle{
private:
	string name;
public:
	NamedCircle(int radius = 1, string name = "Circle") : Circle(radius){ //Circle 클래스를 상속하여 생성자 생성
		this -> name = name;
	}
	string getName(){ return name;}
	void setName(string name){
		this -> name = name;
	}
	void show(){
		cout << "반지름이 "<< getRadius()<< "인 "<< getName();
	}
};
string getBiggest(NamedCircle c[], int size){ // NamedCircle 객체를 받아 가장 반지름이 큰 객체의 name 멤버변수를 반환
	int max = -999999;
	string maxName;
	for(int i=0;i<size;i++){
		if (c[i].getRadius() >= max){
			max= c[i].getRadius();
			maxName= c[i].getName();
		}
	}
	return maxName;
}
int main(){
	int tmp_i; //입력을 위한 임시 변수 생성
	string tmp_s;
	NamedCircle pizza[5]; //Circle를 상속받는 NamedCircle 배열 생성
	cout << "5개의 정수 반지름과 원의 이름을 입력하세요"<<endl;
	for(int i =0;i<5;i++){
		cout << i+1 << ">> ";
		cin >> tmp_i >> tmp_s;
		pizza[i].setRadius(tmp_i);
		pizza[i].setName(tmp_s);
	}
	string biggest = getBiggest(pizza,5);
	cout << "가장 면적이 큰 피자는 "<< biggest<<"입니다.";
}


