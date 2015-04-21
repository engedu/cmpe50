//============================================================================
// Name        : MyLab8.cpp
// Author      : Yutao Hou
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Polynomial.h"
#include "Complex.h"
using namespace std;

void exercise_1();
void exercise_2();


int main() {

//	exercise_1();
	exercise_2();
	return 0;
}

void exercise_1()
{

	int c;
//	int degree_a, degree_b;
//	double *cfa, *cfb;

//	cout << "Please input a constant\n";
//	cin >> c;
//
//	cout << "Polynomial a, please input the degree\n";
//	cin >> degree_a;
//	cfa = new double[degree_a + 1];
//
//	cout << "Please input " << degree_a + 1 << " coefficients:\n";
//	for (int i = 0; i < degree_a + 1; i++) {
//		cin >> cfa[i];
//	}

	c = 2;
	double test_cfa[] = {1.1, 2.2, 3.3};
	double test_cfb[] = {4.4, 5.5};

	Polynomial a(test_cfa, 2);
	Polynomial b(test_cfb, 1);

	// a + b
	cout << a;
	cout << "+" << endl;
	cout << b;
	cout << "=" << endl;
	cout << a + b << endl;

	cout << endl;
	cout << endl;

	// a + int
	cout << a;
	cout << "+" << endl;
	cout << c << endl;
	cout << "=" << endl;
	cout << a + c << endl;

	cout << endl;
	cout << endl;

	// int + a
	cout << c << endl;
	cout << "+" << endl;
	cout << a;
	cout << "=" << endl;
	cout << c + a << endl;

	cout << endl;
	cout << endl;

	// a - b
	cout << a;
	cout << "-" << endl;
	cout << b;
	cout << "=" << endl;
	cout << a - b << endl;

	cout << endl;
	cout << endl;

	// a - int
	cout << a;
	cout << "-" << endl;
	cout << c << endl;
	cout << "=" << endl;
	cout << a - c << endl;

	cout << endl;
	cout << endl;

	// int - a
	cout << c << endl;
	cout << "-" << endl;
	cout << a;
	cout << "=" << endl;
	cout << c - a << endl;

	cout << endl;
	cout << endl;

	// a * b
	cout << a;
	cout << "*" << endl;
	cout << b;
	cout << "=" << endl;
	cout << a * b << endl;

	cout << endl;
	cout << endl;

	// a * int
	cout << a;
	cout << "*" << endl;
	cout << c << endl;
	cout << "=" << endl;
	cout << a * c << endl;

	cout << endl;
	cout << endl;

	// int * a
	cout << c << endl;
	cout << "*" << endl;
	cout << a;
	cout << "=" << endl;
	cout << c * a << endl;

	cout << endl;
	cout << endl;

//	delete [] cfa;
//	delete [] cfb;
}

void exercise_2()
{
	Complex com;
	cout << "input:\n";
	cin >> com;
	cout << com;

}
