
//ch3-2.cpp
#include<iostream>
#include<string>
using namespace std;

class Date{
private:
    int year;
    int month;
    int date;
    string yymmdd;
public:
    Date(int y, int m, int d){ //int 형 인자 3개를 받는 생성자
        year = y;
        month = m;
        date = d;
    };
    Date(string yymmdd){ //string 형을 입력으로 받는 생성자
        this -> yymmdd = yymmdd;
        // substr 함수를 이용해 연도 월, 일을 때어낸다. stoi를 사용해 문자열을 정수로 변환한다.
        year = stoi(yymmdd.substr(0,4)); 
        month = stoi(yymmdd.substr(5,1));
        date = stoi(yymmdd.substr(7,2));
    };
    void show(); //year, month, date 을 출력하는 함수
    int getYear(){  return year;    }
    int getMonth(){ return month;   }
    int getDate(){  return date;    }
};
//콘솔에 출력한다.
void Date::show(){
    cout << year << "년"<< month << "월" << date << "일"<<endl;
}

int main(){
    Date birth(2014, 3, 20); // 2014년 3월 20일 
    Date independenceDay("1945/8/15"); // 1945년 8월 15일
    independenceDay.show();
    cout << birth.getYear () << ","<< birth. getMonth() << ","<< birth.getDate() << endl;
}