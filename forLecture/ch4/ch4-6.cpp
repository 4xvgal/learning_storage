//ch 4-6.cpp
#include<iostream>
#include<string>
using namespace std;
int main(){
    /*문자열을 거꾸로출력 해야한다.
    string 클래스의 reverse 함수를 사용한다.*/
   string n;
   cout << "아래에 한 줄을 입력 하세요(exit을 입력하면 종료)" << endl;
   while(1){
        cout << ">>";
        getline(cin, n); //getline 함수를사용해 공백까지도 입력받을수 있게 한다
        if (n == "exit"){   //만약 exit이 입력되면 종료
            break;
        }
        reverse(n.begin(), n.end()); //reverse 함수는 범위를 지정해야한다. 해당문제에서 범위는 처음(n.begin())부터 끝 (n.end())이다.
        cout << n << endl;    
   }
}


