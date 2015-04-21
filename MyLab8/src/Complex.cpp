/*
 * Complex.cpp
 *
 *  Created on: Apr 21, 2015
 *      Author: 010042799
 */

#include "Complex.h"
Complex::Complex() :
		real(0), imaginary(0)
{

}

Complex::Complex(double r, double i) :
		real(r), imaginary(i)
{

}

Complex::Complex(double real_part) :
		real(real_part), imaginary(0)
{

}

bool operator ==(const Complex& coma, const Complex& comb)
{
	return coma.real == comb.real && coma.imaginary == comb.imaginary;
}

Complex operator +(const Complex& coma, const Complex& comb)
{
	double real = coma.real + comb.real;
	double imaginary = coma.imaginary + comb.imaginary;
	Complex result(real, imaginary);
	return result;
}

Complex operator -(const Complex& coma, const Complex& comb)
{
	double real = coma.real - comb.real;
	double imaginary = coma.imaginary - comb.imaginary;
	Complex result(real, imaginary);
	return result;
}

Complex operator *(const Complex& coma, const Complex& comb)
{
	double real = coma.real * comb.real - coma.imaginary * comb.imaginary;
	double imaginary = coma.real * comb.imaginary + comb.real * coma.imaginary;

	Complex result(real, imaginary);

	return result;
}

istream& operator >> (istream& in, Complex& com)
{

	double r, i;
	char plus;
	in >> r;


	in >> plus;


	in >> i;

	com.real = r;
	com.imaginary = i;

	return in;
}

ostream& operator <<(ostream& out, const Complex& com)
{
	out << com.real << " + " << com.imaginary << " * i" << endl;
	return out;
}

