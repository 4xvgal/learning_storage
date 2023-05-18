//ch6-4.cpp
//실습 4번문제

#include<iostream>
using namespace std;

class MyVector{
	int *mem;
	int size;
public:
	MyVector(int n= 100, int val = 0); // 디폴트 크기 100, 디폴트 초기화인자 = 0
	void show(){ //클래스 테스트를 위한 객체의 크기와 인자를 출력하는 함수
		cout << "Vector size = "<< size <<endl;
		cout << "Vector data"<<endl;
		for(int i=0;i<size;i++){
			cout <<mem[i] << ' ';
		}
		cout << endl;
	}
	~MyVector() { delete [] mem;}
};

MyVector:: MyVector(int n , int val){ // 생성자 구현부
	mem = new int[n]; //매개 변수n 만큼 동적할당
	size = n; //배열속 인자의 갯수는 n 이다.
	for(int i=0;i<size; i++) mem[i] = val; //size 만큼 반복하여 인자를 val로 초기화
}

int main(){
	MyVector a; //매개변수를 사용하지 않은 객체 a
	MyVector test(10, 3);	//크기 10, 초기화인자 3 으로 생성한 test 객체
	a.show();
	test.show();
	
}