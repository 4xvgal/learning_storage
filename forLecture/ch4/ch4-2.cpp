//ch4-2.cpp

#include<iostream>
using namespace std;

class integers{
private:
    int n;
public:
    integers(){ //기본 연산자, n 을 0으로 초기화한다.
        n = 0;
    };
    void setInt(int n){ //매개 변수 n 을 멤버 변수 n 에 저장한다.
        this -> n = n;
    }
    int getInt(){ //멤버 변수 n 을 반환한다.
        return n;
    }
};

int main(){
    int tmp;
    double sum=0;
    
    integers *p; // 포인터 객체 integers 생성

    p = new integers[5]; //포인터 객체에 integers[5] 동적할당
    cout << "정수 5개 입력 >> ";
    for(int i =0;i<5;i++){
        cin >> tmp; //임시 변수 tmp 에 정수를 입력받는다.
        p[i].setInt(tmp);   //i 번째 integers 에 n을 저장한다.
        sum+= p[i].getInt();    //i 번째 integers 에서 값을 반환받아 sum 에 더한다.
    }
    
    cout << "평균 >> " << sum/5; //평균을 출력한다.
}
