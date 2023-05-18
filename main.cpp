//ch9-2.cpp
//실습문제2 킬로미터를 마일로 전환하기
#include<iostream>
using namespace std;

class Converter {
protected:
	double ratio;
	virtual double convert(double src) = 0; //src 를 다른 단위로 변환한다.
	virtual string getSourceString() = 0; //src 단위 명칭
	virtual string getDestString() = 0; // dest 단위 명칭
public:
	Converter(double ratio) { this->ratio = ratio; }
	void run() {
		double src;
		cout << getSourceString() << "을 " << getDestString() << "로 바꿉니다";
		cout << getSourceString() << "을 입력하세요 >>";
		cin >> src;
		cout << "변환 결과 : " << convert(src) << getDestString() << endl;
	}
};

class KmToMile : public Converter {
protected:
	virtual double convert(double src){
		return src / 1.609344;
	}
	virtual string getSourceString() {return "Km";}
	virtual string getDestString() {return "Mile";}
public:
	KmToMile(double km) : Converter(km) { }
};
int main() {
	KmToMile toMile(1.609344);
	toMile.run();
}