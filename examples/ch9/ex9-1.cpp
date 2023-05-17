//ex9-1
#include <iostream>
using namespace std;

class Base
{
public:
	void f() { cout << "Base::f() called" << endl; } // Base class function
};

class Derived : public Base
{
public:
	void f() { cout << "Derived::f() called" << endl; } // Derived class function
};

int main()
{
	Derived d, *pDer; // Creating object of Derived class and pointer to Derived class
	pDer = &d;		  // Assigning address of Derived object to pointer
	pDer->f();		  // Calling Derived class function using pointer

	Base *pBase;  // Creating pointer to Base class
	pBase = pDer; // Assigning address of Derived object to Base pointer
	pBase->f();	  // Calling Base class function using Base pointer
}