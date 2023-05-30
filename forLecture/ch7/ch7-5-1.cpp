//ch7-5-1.cpp
#include<iostream>
using namespace std;
class Color {
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
	Color& operator + (Color op2); // + 연산자 선언
	bool operator == (Color& op); // == 연산자 선언
};

Color& Color::operator+ (Color op2){
	Color tmp; //임시 객체 생성
	tmp.red = this->red + op2.red;
	tmp.blue = this-> blue + op2.blue;
	tmp.green = this-> green + op2.green;
	return tmp;
}

bool Color::operator== (Color& op2){
	if (this->red == op2.red &&
		this->blue == op2.blue &&
		this->green == op2.green){
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
	