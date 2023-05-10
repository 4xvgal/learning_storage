//가산1 .cpp
#include<iostream>
#include<string>
using namespace std;

class Student{  // 학생 정보 클래스
private:
    string Name;    //string 형식의 이름의 멤버 변수
    string Number;  //학번 멤버 변수
    double Korean;  //국어성적 멤버변수
public:
    void setData(string Name, string Number, double Korean){ //매개 변수 3개를 입력받아 멤버변수에 저장한다.
        this -> Name = Name;
        this -> Number = Number;
        this -> Korean = Korean;
    }
    string getName(){   //멤버변수를 반환한다.
        return Name;
    }
    string getNumber(){
        return Number;
    }
    double getKorean(){
        return Korean;
    }
};
void input(Student *ps, double *avg); //input 변수 선언
void output(Student *p);    //output 변수 선언

int main(){
    Student ps[3];      //객체 배열 ps 선언
    double avg = 0;      //평균점수를 저장할 변수 선언
    input(ps,&avg);     //input 함수에 객체배열 ps 와 avg의 주소를 매개변수로 사용한다.
    output(ps);         //output 함수에 객체배열 ps를 넘겨준다.
    cout << "국어평균       "<< avg<<endl <<endl;   //평균점수 avg 출력
    return 0;
}

void input(Student *ps, double *avg){   //input 변수는 Student 클래스의 포인터 객체와 avg 의 주소를 매개변수로 받는다.
    string a,b;  //입력을 받을 변수 a,b,c
    double c;
    double sum;
    cout << "1학년의 성적 관리 프로그램 입니다"<< endl;
    for(int i =0;i<3;i++){      //클래스의 원형이 3개의 객체배열이므로 3번에 걸쳐 입력받는다.
        
        cout << "이름, 학번, 성적입력 :";
        cin >> a >> b >> c;
        ps[i].setData(a,b,c);       //ps의 i방 객체에   setData() 멤버함수를 호출해 멤버변수에 데이터를 입력한다.
        sum += c;                  //평균점수 계산을 위해 sum에 국어성적 c 를 저장한다.
    }
    *avg = sum / 3;             //평균점수는 sum / 3 이다.
}

void output(Student *p){            //객체를 매개변수로 받아 객체내의 멤버변수를 출력하는 함수이다.
    cout << "===============" << endl;
    cout << "학번   이름    국어성적"<<endl;
    cout << "===============" << endl;
    for(int i=0;i<3;i++){
        cout << p[i].getNumber()<< "번  " << "["<<p[i].getName()<<"]"<< "  "<<p[i].getKorean()<<endl;
        //객체 p 의 [i] 방에서 get함수를 이용해 멤버 변수를 반환받아 출력한다.
    }
        cout << "===============" << endl;
}
