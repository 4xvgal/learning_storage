//ch4-7.cpp
#include<iostream>
using namespace std;

class Circle{
private:
    int radius; // 반지름s
public: 
    void setRadius(int radius); // 반지름을 설정한다.
    double getArea(); // 면적을 반환한다. 
}; 

void Circle::setRadius(int radius){
    this -> radius = radius; // this 문으로 매개변수 radius 를 멤버변수 radius에 저장한다.
}

double Circle::getArea(){   //원의 넓이를 반환한다.
    return radius * radius * 3.14;
}


int main(){
    Circle *p;
    p= new Circle[3];
    int tmp;
    int count =0;
    for (int i=0;i<3;i++){
        cout << "원 "<< i+1 << "의 반지름 >>";
        cin >> tmp;
        p[i].setRadius(tmp); //tmp 를 매개변수로 멤버변수 radius에 저장한다.
        if (p[i].getArea() > 100){ //getArea()의 반환값이 100보다 클 경우 count++ 한다.
            count++;
        }
    }
    cout << "면적이 100보다 큰 원의 갯수는 >> "<< count << "개 입니다";
}
