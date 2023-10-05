//ch12-2 예제

#include<iostream>
#include<fstream>
using namespace std;
using std::cout;

int main() {
	string file_path = "bin/student.txt"; //UNIX 경로입니다.
	ifstream fn;
	fn.open(file_path);
	if(!fn){
		std::cout << "파일을 열 수 없다.";
		return 0;
	}
	char name[10],dept[20];
	int sid;
	
	//파일 열기
	fn >> name;
	fn >> sid;
	fn >> dept;
	
	//출력
	cout << name << endl;
	cout << sid << endl;
	cout << dept << endl;
	fn.close();
}