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

	exercise_1();
	exercise_2();
	return 0;
}

void exercise_1()
{

	int c = 2;
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

	double test_cfa[] = {1.1, 2.2, 3.3};
	double test_cfb[] = {4.4, 5.5};

	Polynomial a(test_cfa, 2);
	Polynomial b(test_cfb, 1);

	// a + b
	cout << a;
	cout << "+" << endl;
	cout << b;
	cout << "=" << endl;
	Polynomial sum;
	sum = a + b;
	cout << sum << endl;

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
	Complex com_a, com_b;
	cout << "Please input a complex number(com_a) like a + b * i:\n";
	cin >> com_a;
	cout << "You just input: ";
	cout << com_a;

	cout << "Please input a complex number(com_b) like a + b * i:\n";
	cin >> com_b;
	cout << "You just input: ";
	cout << com_b;

	cout << com_a << " + \n" << com_b;
	cout << com_a + com_b << endl;
	cout << endl;

	cout << com_a << " - \n" << com_b;
	cout << com_a - com_b << endl;
	cout << endl;


	cout << com_a << " * \n" << com_b;
	cout << com_a * com_b << endl;
	cout << endl;


	cout << com_a << " == \n" << com_b;
	cout << (com_a == com_b ? "true" : "false") << endl;
	cout << endl;
}


/*
3.3*x^2 + 2.2*x^1 + 1.1*x^0
+
5.5*x^1 + 4.4*x^0
=
operator +
3.3*x^2 + 7.7*x^1 + 5.5*x^0



3.3*x^2 + 2.2*x^1 + 1.1*x^0
+
2
=
3.3*x^2 + 2.2*x^1 + 3.1*x^0



2
+
3.3*x^2 + 2.2*x^1 + 1.1*x^0
=
operator +
3.3*x^2 + 2.2*x^1 + 3.1*x^0



3.3*x^2 + 2.2*x^1 + 1.1*x^0
-
5.5*x^1 + 4.4*x^0
=
3.3*x^2 + -3.3*x^1 + -3.3*x^0



3.3*x^2 + 2.2*x^1 + 1.1*x^0
-
2
=
3.3*x^2 + 2.2*x^1 + -0.9*x^0



2
-
3.3*x^2 + 2.2*x^1 + 1.1*x^0
=
-3.3*x^2 + -2.2*x^1 + 0.9*x^0



3.3*x^2 + 2.2*x^1 + 1.1*x^0
*
5.5*x^1 + 4.4*x^0
=
18.15*x^3 + 26.62*x^2 + 15.73*x^1 + 4.84*x^0



3.3*x^2 + 2.2*x^1 + 1.1*x^0
*
2
=
6.6*x^2 + 4.4*x^1 + 2.2*x^0



2
*
3.3*x^2 + 2.2*x^1 + 1.1*x^0
=
6.6*x^2 + 4.4*x^1 + 2.2*x^0



Please input a complex number(com_a) like a + b * i:
1 + 2 * i
You just input: 1 + 2 * i
Please input a complex number(com_b) like a + b * i:
1 + 2 * i
You just input: 1 + 2 * i
1 + 2 * i
 +
1 + 2 * i
2 + 4 * i


1 + 2 * i
 -
1 + 2 * i
0 - 0 * i


1 + 2 * i
 *
1 + 2 * i
-3 + 4 * i


1 + 2 * i
 ==
1 + 2 * i
true


 */
