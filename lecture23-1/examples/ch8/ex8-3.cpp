//ex8-3.cpp
#include<iostream>
#include<string>
using namespace std;

class TV{
	int size;
public:
	TV() { size = 20; }
	TV(int size) { this -> size = size;}
	int getSize() {return size;}
};

class WideTV : public TV {
	bool videoIn;
public:
	WideTV(int size, bool videoIn) : TV(size){
		this-> videoIn = videoIn;
	}
	bool getVideoIn() { return videoIn;}
};

class SmartTV : public WideTV {
	string ipAddr;
public:
	SmartTV(string ipAddr, int size) : WideTV(size, true){
		this -> ipAddr = ipAddr;
	}
	string getIpAddr() {
		return ipAddr;
	}
};

int main() {
	//32인치 크기에 "192.0.0.1" 의 인터넷 주소를 가지는 스마트 TV 객체 새엇ㅇ
	SmartTV htv("192.0.0.1", 32);
	cout << "size = " << htv.getSize() << endl;
	cout << "videoIn=" << boolalpha << htv.getVideoIn() << endl;
	cout << "IP=" << htv.getIpAddr() <<endl;
}