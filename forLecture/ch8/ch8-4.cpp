//ch8-4.cpp
//Point 클래스를 상속받는 ColorPoint 클래스 작성 및 응용
#include <iostream>
using namespace std;

// 포인트 클래스 선언부
class Point
{
	int x, y;

public:
	// 생성자 선언
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	//x,y 를 리턴하는 함수
	int getX() { return x; }
	int getY() { return y; }

protected:
	//좌표계를 새로 설정하는 함수 move
	void move(int x, int y){
		this->x = x;
		this->y = y;
	}
};

// Point를 상속받은 ColorPoint 클래스 선언
class ColorPoint : public Point{
private:
	string ColorName;

public:
	//ColorPoint 생성자 선언
	ColorPoint(int x = 0, int y = 0, string name = "BLACK") : Point(x, y){
		ColorName = name;
	}
	
	void setPoint(int x, int y){ // 새로운 좌표계를 설정하는 메소드
		move(x, y);
	}
	
	void setColor(string name) { // 컬러를 설정하는 메소드
		ColorName = name;
	}
	
	void show(){// 색과 좌표계 출력
		cout << ColorName << "색으로 (" << getX() << ',' << getY() << ")에 위치한 점입니다." << endl;
	}
};

// Main function
int main()
{
	ColorPoint zeroPoint;
	zeroPoint.show();
	ColorPoint cp(5, 5);
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();
}

