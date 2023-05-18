//ch6-2.cpp
//실습문제 2번 -1 
#include<iostream>
using namespace std;

class Person {
	int id;
	double weight;
	string name;
public:
	void show() {cout << id <<' '<< weight << ' '<< name << endl;}
	
	Person(){ //기본 생성자
		id = 1;
		name = "Grace";
		weight = 20.5;
	}
	Person(int id, string name) { //매개변수로 id, name을 사용하는 생성자
		this -> id = id;
		this -> name = name;
	}
	Person(int id, string name, double weight){ //매개변수로 3개의 변수를 사용하는 생성자
		this -> id = id;
		this -> name = name;
		this -> weight = weight;
	}
};


int main() {
	Person grace, ashley(2, "Ashley"), helen(3,"Helen", 32.5);
	grace.show();
	ashley.show();
	helen.show();
}