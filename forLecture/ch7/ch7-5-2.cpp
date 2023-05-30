//ch7-5-2.cpp
//friend 로 외부함수를 클래스 내부에서 사용하기
#include<iostream>
using namespace std;
class Color {
private:
	int red, green, blue;
public:
	Color() {red = green= blue = 0;}
	Color(int r, int g, int b) { red =r, green = g, blue = b;}
	void setColor(int r, int g, int b){
		red =r;
		green = g;
		blue = b;
	}
	void show() {
		string s = " ";
		cout << red << s << green << s << blue << endl;
	}
	friend Color& operator+ (Color& op1, Color& op2); // + 연산자 선언
	friend bool operator == (Color& op1, Color& op2); // == 연산자 선언
};

Color& operator+ (Color& op1, Color& op2){
	Color tmp; //임시 객체 생성
	tmp.red = op1.red + op2.red;
	tmp.blue = op1.blue + op2.blue;
	tmp.green = op1.green + op2.green;
	return tmp;
}

bool operator== (Color& op1, Color& op2){
	if (op1.red == op2.red &&
		op1.blue == op2.blue){
			return true;
		}
	return false;
}
int main(){
	Color red(255,0,0) , blue(0,0,255), c;
	c = red + blue;
	c.show();
	Color fuchsia(255, 0, 255);
	if ( c == fuchsia)
		cout << "보라색 맞음";
	else
		cout << "보라색 아님";
	}
	