//ch8-5.cpp
// BaseArray 를 상속받아 큐처럼 작동하는 Myqueue 클래스를 작성하라.
#include<iostream>
using namespace std;
using ::cout;;

class BaseArray {
private:
	int capacity; //배열의 크기
	int *mem; //정수 배열을 만들기 위한 메모리의 포인터
protected:
	BaseArray(int capacity=100) {
		this -> capacity = capacity; mem = new int[capacity];
	}
	~BaseArray() { delete [] mem;}
	void put(int index, int val) { mem[index] = val;}
	int get(int index) {return mem[index];}
	int getCapacity(){return capacity;}
};

class MyQueue : protected BaseArray {
private:
	int front = 0; //큐 앞부분
	int rear = 0;	//큐 뒷부분
public:
	MyQueue(int n) : BaseArray(n){ } //기본생성자
	//큐에 인자 n 을 추가하기
	void enqueue(int n) {
		if(rear >= getCapacity()){
			std::cout << "Queue is full..." << endl;
		}
		rear++;
		put(rear,n);
	}
	//큐에서 삭제하기
	int dequeue() {
		if(rear < 0){
			std::cout << "Queue is empty..."<<endl;
			exit(1);
		}
		++front;
		rear--;
		return get(front);
	}
	//큐의 용량 반환 (상속받은 BaseArray가 protected 이기 떄문이다.)
	int capacity() {
		return getCapacity();
	}
	//큐의 길이 반환 
	int length(){
		return rear;
	}
};
int main(){
	MyQueue mq(100);
	int n;
	cout << "큐에 삽입할 5개의 정수를 입력하라 >>";
	for(int i=0;i<5;i++){
		cin >> n;
		mq.enqueue(n); //큐에 삽입
	}
	cout <<"큐의 용량:" << mq.capacity() <<", 큐의 크기: " <<mq.length() << endl;
	cout << "큐의 원소를 순서대로 제거하여 출력한다. >> ";
	while (mq.length() != 0 ){
		cout << mq.dequeue() << ' '; //큐에서 제거하여 출력
	}
	cout << endl << "큐의 현재크기 : " << mq.length() << endl;
}