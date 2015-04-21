/*
 * Complex.h
 *
 *  Created on: Apr 21, 2015
 *      Author: 010042799
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
using namespace std;

class Complex
{
public:
	Complex();
	Complex(double r, double i);
	Complex(double real_part);

	friend bool operator == (const Complex& coma, const Complex& comb);
	friend Complex operator + (const Complex& coma, const Complex& comb);
	friend Complex operator - (const Complex& coma, const Complex& comb);
	friend Complex operator * (const Complex& coma, const Complex& comb);
	friend istream& operator >> (istream& in, Complex& com);
	friend ostream& operator << (ostream& out, const Complex& com);

private:
	double real;
	double imaginary;
};

const Complex i(0, 1);



#endif /* COMPLEX_H_ */
