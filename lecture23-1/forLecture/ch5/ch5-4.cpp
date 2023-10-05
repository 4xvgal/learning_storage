//ch5-4.cpp

#include<iostream>
using namespace std;
// a와 b 가 같으면 true, 다르면 false 그리고 big에는 큰수를 리턴한다

bool bigger(int a, int b,int &big){
	if (a == b){
		return true;
	}
	else if(a > b){
		big =a;
	}
	else if(b>a){
		big =b;
	}
	return false;
}

int main(){
	int a= 3;
	int b= 5;
	int big = 0;
	cout <<"A : " << a << " 	B : " <<b << endl;
	cout<< "is a and b equal? : "  << bigger(a,b,big) << endl;
	cout << "bigger integer : "  << big << endl;
}
