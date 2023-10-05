//ch12-5 예제
#include<iostream>
#include<fstream>
using namespace std;
using std::cout;

int main() {
	string sysIni = "c:\\windows\\systeam.ini";
	ifstream fn(sysIni);
	if(!fn) {
		std::cout << sysIni << "열기 실패"<<endl;
		return 0;
	}
	char buf[81];
	while(fn.getline(buf,81)){
		std::cout << buf << endl;
	}
	fn.close();
}