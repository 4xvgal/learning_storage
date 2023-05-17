//ch8-4.cpp
#include <iostream>
using namespace std;

// Point class declaration
class Point
{
	int x, y;

public:
	// Point class constructor
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	// Getter methods for x and y coordinates
	int getX() { return x; }
	int getY() { return y; }

protected:
	// Method to move the point to a new location
	void move(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

// ColorPoint class declaration, derived from Point class
class ColorPoint : public Point
{
private:
	string ColorName;

public:
	// ColorPoint class constructor
	ColorPoint(int x = 0, int y = 0, string name = "BLACK") : Point(x, y)
	{
		ColorName = name;
	}
	// Method to set the location of the point
	void setPoint(int x, int y)
	{
		move(x, y);
	}
	// Method to set the color of the point
	void setColor(string name)
	{
		ColorName = name;
	}
	// Method to display the color and location of the point
	void show()
	{
		cout << ColorName << "색으로 (" << getX() << ',' << getY() << ")에 위치한 점입니다." << endl;
	}
};

// Main function
int main()
{
	// Create a ColorPoint object with default values
	ColorPoint zeroPoint;
	// Display the color and location of the point
	zeroPoint.show();
	// Create a ColorPoint object with specified values
	ColorPoint cp(5, 5);
	// Set the location of the point to a new location
	cp.setPoint(10, 20);
	// Set the color of the point to blue
	cp.setColor("BLUE");
	// Display the color and location of the point
	cp.show();
}

