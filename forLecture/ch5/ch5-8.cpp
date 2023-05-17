//ch5-8.cpp

#include<iostream>
using namespace std;

class MyIntStack {
	int *p; //스택 메모리로 사용할 포인터
	int size; //스택의 최대 크기
	int tos;	//스택의 꼭대기를 가리키는 인덱스
public:
	MyIntStack();
	MyIntStack(int size);
	MyIntStack(const MyIntStack& s); //복사 생성자
	~MyIntStack();

	bool push(int n); //정수 n 푸쉬, 꽉 차 있으면 false, 아니면 true 리턴
	bool pop(int &n);	//팝 하여 n  에 저장, 스택이 비어 잇으면 false, 아니면 true 리턴

};

MyIntStack::MyIntStack(){ //기본 생성자
	tos = 0;	//생성자에서 인덱스 초기화
}
MyIntStack::MyIntStack(int size){ // size 매개변수가 있는 생성자
	tos = 0; //tos 초기화
	p= new int[size]; // 포인터 p 에 size 만큼의 스택 할당
}
MyIntStack::MyIntStack(const MyIntStack& s){ //복사생성자 정의
	this -> size = s.size; //size값 복사
	this -> tos = s.tos; //tos 값 복사;
	this -> p = new int[size]; //포인터 새로 할당
}
MyIntStack::~MyIntStack(){ // 소멸자
	if(p) {
		delete[] p;
	}
}
bool MyIntStack::push(int n){ //stack 에 값을 push 하는 함수
	if (tos > 9 ){ //9보다 크다는 것은 스택을 초과한다 = 스택이 다 참
		return false; //push = false;
	}	
	else{
		p[tos] = n; //멤버 변수 p[tos] 인덱스에 n 저장
		tos++;			//그 다음 인덱스 참조를 위해 tos++
		return true;		//스택에 공간이 있으므로 true
	}
}

bool MyIntStack::pop(int &n){ //call by reference 참조에 의한 호출	
	tos--;				//tos는 곧 스택이 얼마나 차 있냐를 나타나기에 pop을 하면 tos 를 감소시킨다.
	if(tos < 0) return false; //만약 tos 가 0보다 작으면 false , 0보다 작다는 것은 스택이 비어있다는 뜻이다.
	else { 
		n = p[tos];	 //pop으로 추출한 값을 n 에 저장한다.
		return true;		//아직 스택이 남아있기에 true를 반환한다.
	}	
}

int main(){
	MyIntStack a(10);
	a.push(10);
	a.push(20);
	MyIntStack b = a; //복사 생성
	b.push(30);

	int n;
	a.pop(n);
	cout << "pop data from stack a : "<< n <<endl;
	b.pop(n);
	cout << "pop data from stack b : "<< n << endl;
}