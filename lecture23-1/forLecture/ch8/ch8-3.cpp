//ch8 실습 3
//Point 클래스를 상속받는 ColorPoint 클래스 작성
#include<iostream>
using namespace std;


class Point { //부모 클래스
	int x,y;
public:
	Point(int x,int y) { this -> x = x; this -> y = y;}
	int getX() {return x;}
	int getY() {return y;}
protected:
	void move(int x,int y) {this -> x= x; this -> y = y;}
};

class ColorPoint : public Point{ //Point를 Public으로 상속받은 클래스
private:
	string ColorName;
public:
	ColorPoint(int x,int y, string name ) : Point(x,y){ //정수 x,y를 Point의 생성자 매개변수로 사용
		ColorName = name;
	}
	void setPoint(int x,int y){ //좌표계를 설정한다.
		move(x,y);
	}
	void setColor(string name){ //이름을 설정한다.
		ColorName = name;
	}
	void show(){
		cout << ColorName<<"색으로 (" << getX()<< ','<<getY() <<")에 위치한 점입니다."<<endl;
	}
};
int main(){
	ColorPoint cp(5,5,"RED"); //객체 생성
	cp.setPoint(10,20); //좌표 설정
	cp.setColor("BLUE"); //컬러 변경
	cp.show(); //초기의 5,5 RED 에서 10,20 BLUE 로 바뀌게된다
}