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


int main(){
Random r;
    cout << "--0에서 " << RAND_MAX << "까지의 랜덤 정수 10개-- " << endl;
    for (int i=0;i<10;i ++){
        int n= r.next();
        cout << n << ' ';
    }
    
    cout << endl << endl << "--2 에서 4까지의 랜덤정수 10개 --" << endl;
    for(int i=0;i<10;i++){
        int n= r.nextInRange(2,4);
        cout << n<< ' ';
    }
    cout << endl;
}