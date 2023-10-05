//ch12-1 예제

#include<iostream>
#include<fstream>
using namespace std;

int main() {
	char name[10],dept[20];
	int sid;
	string output_path = "bin/student.txt"; //UNIX 경로입니다.
	//키보드로부터 읽기
	std::cout << "이름>>";
	std::cin >> name;
	std::cout << "학번(숫자로)>>";
	std::cin >> sid;
	std::cout <<"학과>>";
	std::cin >> dept;
	//파일 열기. student.txt 파일을 열고 출력 스트림 생성
	ofstream fout(output_path);
	if(!fout) {
		cout << output_path << "파일을 열수없다.";
		return 0;
	}
	//file writing
	fout << name << endl;
	fout << sid << endl;
	fout << dept << endl;

	fout.close();
}