//ch8-1.cpp
//Circle 클래스를 상속받는 NamedCircle 프로그램
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
class NamedCircle : public Circle{ //Circle 클래스를 상속받은 NamedCircle
//Circle을 public으로 상속받았다.
private:
	string name;
public:
	NamedCircle(int radius, string name) : Circle(radius){ //파생클래스 생성자가 기본클래스 생성자에 매개변수를 전달하는 방식
		this -> name = name;
	}
	string getName(){
		return name;
	}
	void show(){
		cout << "반지름이 "<< getRadius()<< "인 "<< getName();
	}
};
int main(){
	NamedCircle waffle(3,"waffle");
	waffle.show();
}


