//practice4-9.cpp

#include<iostream>
#include<string>
using namespace std;

class Person {
	string name;
	string tel;
public:
	Person();
	string getName() {
		return name;
	}
	string getTel() { return tel; }
	void set(string name, string tel);
};

Person::Person() {
	name = '\0';
	tel = '\0';
};

void Person::set(string name, string tel) {
	this->name = name;
	this->tel = tel;
}

int main() {
	cout << endl;
	Person* cArray = new Person[3]; // 객체 Person을 가지는 배열 선언
	cout << "이름과 전화 번호를 입력해 주세요";

	string tmpName; // 객체 배열에 입력할 버퍼
	string tmpTel; // 전화번호 버퍼
	cout << endl;
	Person* p = cArray; //편한 객체 배열 참조를 위해 새로운 객체 포인터 생성
	for (int i = 0; i < 3; i++) { //입력받기
		cout << "사람" << i + 1 << ">> ";
		cin >> tmpName >> tmpTel;
		p->set(tmpName, tmpTel);
		p++; // 다음 배열로 
	}
	cout << endl;
	cout << "모든 사람의 이름은 "; // 모든 사람의 이름 출력
	p = cArray; // 객체 포인터의 주소값 초기화 (다시 0번째 배열주소로 초기화)
	for (int i = 0; i < 3; i++) {
		cout << p->getName() << " ";
		p++;
	}
	cout << endl;
	cout << "전화번호를 검색합니다. 이름을 입력하세요 >>"; // 전화번호 검색단계
	cin >> tmpName;

	//cout << endl;
	p = cArray;
	for (int i = 0; i < 3; i++) {
		if (p->getName() == tmpName) { //객체 포인터를 1씩 증가시키며 배열내의 이름과 입력이름을 대조
			cout << "전화번호는 " << p->getTel(); // 동일한 이름을 찾으면 전화번호를 출력
		}
		p++;
	}
}
