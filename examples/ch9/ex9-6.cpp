//추상 클래스 구현 연습
//ex9-6.cpp
#include<iostream>
using namespace std;

class Calculator {
public:
	virtual int add(int a, int b) = 0;  //두 정수의 합 리턴
	virtual int subtract(int a,int b) = 0; // 두 정수의 차 리턴
	virtual double average(int a [], int size) = 0; //a의 평균리턴, size는 배열크기
};

class GoodCalc : public Calculator { //추상 클래스 구현
public:
	int add(int a,int b) { return a+b;}
	int subtract(int a, int b){ return a -b; }
	double average(int a[], int size) {
		double sum =0 ;
		for(int i=0;i<size; i++){ sum += a[i];}
		return sum/size;
	}
};
int main(){
	int a [] = {1,2,3,4,5};
	Calculator *p = new GoodCalc();
	cout << p-> add(2,3) << endl;
	cout << p-> subtract(2,3) << endl;
	cout << p-> average(a,5) << endl;
	delete p;
}