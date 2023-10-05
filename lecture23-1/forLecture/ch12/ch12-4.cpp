//ch12-4.cpp
//system.ini를 읽어 대문자로 변환하여 저장
#include<iostream>
#include<fstream>
using namespace std;
using ::cout;
int main() {
    //읽기 파일 스트림 생성
    ifstream fin("c:\\windows\\system.ini");
    if (!fin) {
        cout << "c:\\windows\\system.ini 열기 오류";
        return 0;
    }
    //쓰기 파일 스트림 생성
    ofstream fout("c:\\Temp\\system.txt");
    if (!fout) {
        cout << "c:\\Temp\\system.txt 열기 오류";
        return 0;
    }
    cout << "initializing Read..." << endl;
    int ch;
    while ((ch = fin.get()) != EOF) {
        ch = toupper(ch); //문자를 대문자로 바꾸기
        cout << (char)ch; 
        fout.put(ch);   //파일에 출력
    }
    cout << "저장 끝" << endl;
    fin.close(); //파일 스트림 닫기
    fout.close();
}