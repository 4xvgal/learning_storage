//ch8-1.cpp
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
	NamedCircle(int radius, string name) : Circle(radius){
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


