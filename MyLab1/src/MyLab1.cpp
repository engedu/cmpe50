//============================================================================
// Name        : MyLab1.cpp
// Author      : Yutao Hou
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <cmath>
using namespace std;

void method2();
void method3();
void method4();

int main()
{
	method2();
	method3();
	method4();
	return 0;
}

// Question 2
// testing output:
// A fool thinks himself to be wise, but a wise man knows himself to be a fool.
void method2()
{
	cout
			<< "A fool thinks himself to be wise, but a wise man knows himself to be a fool."
			<< endl;
}

// Question 3
// testing
// input : output
// -10000000000:0,-1000:1000000, -2.5:4, -0.5:0, 0:0, 0.5:0, 2.5:4, 1000:1000000, 10000000000:1
void method3()
{
	int input;
	cin >> input;
	cout << input * input << endl;
}

// Question 4
// test -1
// no output

// test 0
// no output

// test 1
// no output

// test 2
// no output

// test 3
// 3 is a prime number.

// test 13
//3 is a prime number.
//5 is a prime number.
//7 is a prime number.
//11 is a prime number.
//13 is a prime number.

// test 28
// 28
// 3 is a prime number.
// 5 is a prime number.
// 7 is a prime number.
// 11 is a prime number.
// 13 is a prime number.
// 17 is a prime number.
// 19 is a prime number.
// 23 is a prime number.

// test 1000000000000
// no output
void method4()
{
	int k;
	cin >> k;
	for (int i = 3; i < k + 1; i++)
	{
		if (i == 3)
		{
			cout << i << " is a prime number." << endl;
		}
		else
		{
			bool is_prime = true;
			int half = i / 2 + 1;
			for (int j = 2; j < half; j++)
			{
				if (i % j == 0)
				{
					is_prime = false;
					break;
				}
			}

			if (is_prime)
			{
				cout << i << " is a prime number." << endl;
			}
		}
	}
}

