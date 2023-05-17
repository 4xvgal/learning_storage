//ch3-6.cpp 짝수 랜덤클래스
#include<iostream>
#include<cstdlib>

using namespace std;


class Random{
public:
    Random(){ //기본 생성자 지정
        srand(time(NULL)); //현재 시간을 seed로 사용
    };
    int next(){
        return rand(); //새로운 rand를 리턴한다.
    }
    int nextInRange(int x,int y){
        return rand() % (y-x+1) + x; // (y-x+1) 로 rand 를 나눈 값에 x 를 더하면 x~y 범위를 벗어나지 않는다.
    }
};


class EvenRandom{
public:
    EvenRandom(){
        srand(time(NULL)); //현재 시간을 seed로 사용
    };
    int next(){
        int rd = rand(); //새로운 랜덤함수를 rd 변수에 저장
        if (rd % 2 ==1) { //rd가 홀수라면 rd에서 1을 뺀다.
            rd = rd -1; 
        }
        return rd;
    }
    int nextInRange(int x, int y){
        int rd = rand() % (y-x+1) + x; //새로운 x~y 범위 변수를 rd 에 저장한다.
        if (rd % 2 ==1) { //rd가 홀수라면 rd 에서 1을 뺀다.
            rd = rd -1;
        }
        return rd;
    }

    
        
};

int main(){
    EvenRandom r;
    cout << "--0에서 " << RAND_MAX << "까지의 랜덤 정수 10개-- " << endl;
    for (int i=0;i<10;i ++){
        int n= r.next();
        cout << n << ' ';
    }
    
    cout << endl << endl << "--2 에서 10까지의 랜덤정수 10개 --" << endl;
    for(int i=0;i<10;i++){
        int n= r.nextInRange(2,10);
        cout << n<< ' ';
    }
    cout << endl;
}
