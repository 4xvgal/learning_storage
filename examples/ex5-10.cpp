//ex5-10.cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
class Person { //Person 클래스 선언
    char* name;
    int id;
public:
    Person(int id,const char* name);
    ~Person();
    void changeName(const char* name);
    void show() { 
        cout << id << ',' << name << endl;
    }
};

Person::Person(int id, const char* name) { //생성자
    this -> id = id;
    int len = strlen(name); //name의 문자 개수 저장
    this -> name = new char [len+1]; //len + null 만큼의 문자열을 저장할 공간확보
    strcpy(this -> name, name); // (도착지, 출발지)
}

Person::~Person(){ // 소멸자
    if (name) {
        delete [] name;
    }
}

void Person::changeName(const char* name) { //이름 변경
    if(strlen(name) > strlen(this -> name))
    return;                     //현재 name에 할당된 메모리보다 긴 이름으로 바꿀 수 없다.
    strcpy(this -> name, name);
}

int main() {
    Person father(1,"Kitae");       //father 객체 생성
    Person daughter(father);        //  daughter 객체 복사 생성. 복사 생성자 호출  

    cout << "daughter 객체 생성 직후 ---" << endl;
    father.show(); // -> 1, kitae
    daughter.show(); // -> 1, kitae
    
    daughter.changeName("Grace"); // daughter의 name을 "Grace"로 변경
    cout << "daughter 이름을 grace 로 변경한 후 ----" << endl;
    father.show(); // --> Grace
    daughter.show(); // --> Grace 
    //father 를 복사한 daughter은 서로 같은 name 메모리 영역을 공유하므로
    // 복사된 객체의 멤버변수를 수정하면 같이 수정됨

    return 0;
}