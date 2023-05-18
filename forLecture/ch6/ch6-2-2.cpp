//ch6-2.cpp
//실습문제 2번 -2
#include<iostream>
using namespace std;

class Person {
	int id;
	double weight;
	string name;
public:
	void show() {cout << id <<' '<< weight << ' '<< name << endl;}
	
	Person(int id= 1, string name = "Grace", double weight = 20.5) { //디폴트 매개변수를 가진 하나의 생성자
		this ->id = id;
		this ->name = name;
		this -> weight = weight;
	}
};


int main() {
	Person grace, ashley(2, "Ashley"), helen(3,"Helen", 32.5);
	grace.show();
	ashley.show();
	helen.show();
}