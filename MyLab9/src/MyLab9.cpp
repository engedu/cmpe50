//============================================================================
// Name        : MyLab9.cpp
// Author      : Yutao Hou
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include "figure.h"
#include "circle.h"
#include "triangle.h"

using namespace std;

void myDraw(Figure *fig)
{
	fig->draw();
	cout << "\n myDraw: Derived class object calling center(). \n";
	fig->center();
}

int main(){
	Figure *fig;
	Triangle *tri = new Triangle;

	fig = tri;
	fig->draw();
	cout << "\n Derived class Triangle object calling center(). \n";
	fig->center();

	myDraw(tri);

	Circle *cir = new Circle;
	fig = cir;
	cir->draw();
	cout << "\n Derived class Circle object calling center(). \n";
	cir->center();

	myDraw(cir);

	return 0;

}


/* output
=========================no virtual=========================
Figure::draw()

 Derived class Triangle object calling center().
Figure::erase()
Figure::draw()
Figure::draw()

 myDraw: Derived class object calling center().
Figure::erase()
Figure::draw()
Circle::draw()

 Derived class Circle object calling center().
Figure::erase()
Figure::draw()
Figure::draw()

 myDraw: Derived class object calling center().
Figure::erase()
Figure::draw()
=========================virtual=========================
Triangle::draw()

 Derived class Triangle object calling center().
Triangle::erase()
Triangle::draw()
Triangle::draw()

 myDraw: Derived class object calling center().
Triangle::erase()
Triangle::draw()
Circle::draw()

 Derived class Circle object calling center().
Circle::erase()
Circle::draw()
Circle::draw()

 myDraw: Derived class object calling center().
Circle::erase()
Circle::draw()
=========================reason=========================
No virtual, compiler treat the pointer of the type base class as it is pointing a base class. When function erase() and draw() are invoked,
the functions of base class are invoked.
After add virtual, it tell the compiler that even it is a base class pointer, it needs to check the virtual table to get the correct function
to invoke. If it is pointing a derived class, call the functions of derived class instead of functions of base class.
This is called Polymorphism.


 */
