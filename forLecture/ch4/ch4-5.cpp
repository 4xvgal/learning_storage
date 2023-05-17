//ch4-5.cpp

#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

class Random{
private:
    int rand_i; //랜덤 정수
    int rangeInit;  //범위지정식
    int rangeAdder; //범위지정 가산식
public:
    Random(){ //기본생성자
       srand((unsigned)time(NULL));
       rand_i = rand();
       rangeInit = 1;
    }
    Random(int start, int des){
        srand(time(NULL));
        rangeInit = (des-start+1); //범위지정식 저장
        rangeAdder = start; //범위 가산식 저장
        rand_i = rand(); //랜덤 정수 저장
    }
    int getRand(); 
    int getNewRand();
    void newRand();
    void setRange(int start,int des){ // 범위 지정 문제
        rangeInit = (des-start+1);
        rangeAdder = start;
    }
    
};

int Random::getRand(){ //랜덤 변수 반환
    return rand_i % rangeInit + rangeAdder;
}

void Random::newRand(){ //새로운 랜덤 변수 저장
    rand_i = rand() % rangeInit + rangeAdder;
}

int Random::getNewRand(){ //새 변수 저장 + 반환
    Random::newRand();
    return Random::getRand();
}

int main(){ 
    string origin;
    string modified;
    char modChar;
    int len =0;
    
    Random forPos(0,len);
    Random forAscii(97,122);

    cout << "아래에 한 줄을 입력 하세요(exit을 입력하면 종료)" << endl;
    
    while(true){
        cout<< "<<";
        getline(cin, origin);
        if (origin == "exit"){
            break;
        }
        len = origin.length(); //원래 문자열의 길이 저장
        forPos.setRange(0,len);//문자열 내의 랜덤 포지션 정하기
        int posRand = forPos.getNewRand(); // 랜덤 포지션저장

        modified = origin; //문자열 복사
        int modInt = forAscii.getNewRand(); //랜덤 아스키코드 저장
        modChar = char(modInt); //아스키코드를 문자화

        modified[posRand] = modChar; // 랜덤 포지션에 랜덤 아스키로치환
        cout<< modified <<endl; //출력
    }
}