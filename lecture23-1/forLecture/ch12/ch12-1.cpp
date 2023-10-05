//ch12 - 1 (키보드로 입력받기)
#include<iostream>
#include<fstream>
using namespace std;
using ::cout;

int main() {
	const char* filePath = "c://Temp/test.txt"; //윈도우경로
	//파일에 키보드로 입력하기

	char line[20];
	char line2[20];
	//키보드부터 읽기
	cin >> line;
	cin >> line2;
	//입력모드 파일 열기 filepath 에서 파일을 열고 출력 스트림 생성
	ofstream fout(filePath);
	if (!fout) {
		cout << filePath << "파일을 열수없다.";
		return 0;
	}
	//파일에 쓰기
	fout << line << endl;
	fout << line2 << endl;


	//파일 읽어들이기
	ifstream fn;
	fn.open(filePath);
	if (!fn) {
		std::cout << "c://Temp/test.txt 을 열수없습니다.";
		return 0;
	}
	int ch;
	while ((ch = fn.get()) != EOF) cout.put(ch); //파일의 끝까지 한줄을 ch 에 저장하여 출력
	fn.close();
}
