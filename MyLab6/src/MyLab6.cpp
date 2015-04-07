/*
 * MyLab6.cpp
 *
 *  Created on: Apr 3, 2015
 *      Author: yutao
 */
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdlib>
using namespace std;

void exercise_1();
void exercise_2();

class Resource
{
public:
	Resource();
	Resource(int w);

	int get_status() const;
	int get_writeTo() const;

	void set_status(int s);
	void set_writeTo(int w);

	void output(ostream& out);

	friend bool check_status(const Resource& res1, const Resource& res2);

private:
	int status;
	int writeTo;

};

class Rational
{
public:
	Rational();
	Rational(int n, int d);
	void input(istream& in);
	void output(ostream& out);
	void normalize();

	friend Rational add(Rational& r1, Rational& r2);
	friend Rational subtract(Rational& r1, Rational& r2);
	friend Rational multiply(Rational& r1, Rational& r2);
	friend Rational division(Rational& r1, Rational& r2);

	friend bool equal(const Rational& r1, const Rational& r2);
	friend bool less_than(const Rational& r1, const Rational&r2);

private:
	int numerator;
	int denominator;

	int gcd(int n1, int n2);
};

int main()
{
	exercise_1();

	exercise_2();
	return 0;
}

void exercise_1()
{
	cout << "exercise_1():\n";
	Resource res1, res2, res3(1);
	cout << "res1: ";
	res1.output(cout);
	cout << "res2: ";
	res2.output(cout);
	cout << "res3: ";
	res3.output(cout);

	cout << "modify res2, res3\n";
	res2.set_status(1);
	res2.set_writeTo(1);
	res3.set_status(1);
	cout << "res2: ";
	res2.output(cout);
	cout << "res3: ";
	res3.output(cout);

	cout << "check status res1 and res2: ";
	if (check_status(res1, res2))
	{
		cout << "resource available\n";
	}
	else
	{
		cout << "resource unavailable\n";
	}

	cout << "check status res2 and res3: ";
	if (check_status(res2, res3))
	{
		cout << "resource available\n";
	}
	else
	{
		cout << "resource unavailable\n";
	}

}

Resource::Resource() :
		status(0), writeTo(0)
{

}

Resource::Resource(int w)
{
	if (w > 1 || w < 0)
	{
		writeTo = 0;
	}
	else
	{
		writeTo = w;
	}
}

int Resource::get_status() const
{
	return status;
}

int Resource::get_writeTo() const
{
	return writeTo;
}

void Resource::set_status(int s)
{
	if (s > 1 || s < 0)
	{
		status = 0;
	}
	else
	{
		status = s;
	}
}
void Resource::set_writeTo(int w)
{
	if (w > 1 || w < 0)
	{
		writeTo = 0;
	}
	else
	{
		writeTo = w;
	}
}

void Resource::output(ostream& out)
{
	out << "status: " << status << " , writeTo: " << writeTo << endl;
}

bool check_status(const Resource& res1, const Resource& res2)
{
	return (res1.status == 1) && (res2.status == 1);

}

void exercise_2()
{
	cout << "exercise_2():\n";
	Rational r1, r2;
	cout
			<< "Please input rational r1 with numerator and denominator(like -1/2, 15/32, or -300/-401): ";
	r1.input(cin);
	cout << "r1: ";
	r1.output(cout);

	cout
			<< "Please input rational r2 with numerator and denominator(like -1/2, 15/32, or -300/-401): ";
	r2.input(cin);
	cout << "r2: ";
	r2.output(cout);

	cout << "r1 + r2: ";
	add(r1, r2).output(cout);

	cout << "r1 - r2: ";
	subtract(r1, r2).output(cout);

	cout << "r1 * r2: ";
	multiply(r1, r2).output(cout);

	cout << "r1 / r2: ";
	division(r1, r2).output(cout);

	if (equal(r1, r2))
	{
		cout << "r1 equal r2\n";
	}
	else if (less_than(r1, r2))
	{
		cout << "r1 less than r2\n";
	}
	else
	{
		cout << "r1 more than r2\n";
	}
}

Rational::Rational() :
		numerator(1), denominator(1)
{

}

Rational::Rational(int n, int d)
{
	numerator = n;
	if (d == 0)
	{
		cout << "denominator can not be 0!!!\n";
		exit(1);
	}
	else
	{
		denominator = d;
		normalize();
	}
}

void Rational::input(istream& in)
{
	char stash;
	int n, d;
	cin >> n >> stash >> d;

	numerator = n;

	if (d == 0)
	{
		cout << "denominator can not be 0!!!\n";
		exit(1);
	}
	else
	{
		denominator = d;
		normalize();
	}
}

void Rational::output(ostream& out)
{
	if (numerator == 0)
	{
		cout << 0 << endl;
	}
	else if (numerator == denominator)
	{
		cout << 1 << endl;
	}
	else
	{
		out << numerator << "/" << denominator << endl;
	}
}

void Rational::normalize()
{
	if (numerator == 0)
	{
		return;
	}

	int g = gcd(numerator, denominator);

	numerator = numerator / g;
	denominator = denominator / g;

	if (numerator * denominator < 0)
	{
		numerator = -abs(numerator);
		denominator = abs(denominator);
	}
	else
	{
		numerator = abs(numerator);
		denominator = abs(denominator);
	}
}

int Rational::gcd(int n1, int n2)
{
	int tmp;

	while (n2 != 0)
	{
		tmp = n1;
		n1 = n2;
		n2 = tmp % n2;
	}

	return n1;

}

Rational add(Rational& r1, Rational& r2)
{
	int n = r1.numerator * r2.denominator + r2.numerator * r1.denominator;
	int d = r1.denominator * r2.denominator;
	Rational result(n, d);
	result.normalize();
	return result;

}
Rational subtract(Rational& r1, Rational& r2)
{
	int n = r1.numerator * r2.denominator - r2.numerator * r1.denominator;
	int d = r1.denominator * r2.denominator;
	Rational result(n, d);
	result.normalize();
	return result;

}
Rational multiply(Rational& r1, Rational& r2)
{
	int n = r1.numerator * r2.numerator;
	int d = r1.denominator * r2.denominator;
	Rational result(n, d);
	result.normalize();
	return result;
}

Rational division(Rational& r1, Rational& r2)
{
	if (r2.numerator == 0)
	{
		cout << "denominator can not be 0!!!\n";
		exit(1);
	}
	int n = r1.numerator * r2.denominator;
	int d = r1.denominator * r2.numerator;
	Rational result(n, d);
	result.normalize();

	return result;
}

bool equal(const Rational& r1, const Rational& r2)
{
	return r1.numerator * r2.denominator == r2.numerator * r1.denominator;

}
bool less_than(const Rational& r1, const Rational&r2)
{
	if (r1.numerator == 0 || r2.numerator == 0)
	{
		return r1.numerator < r2.numerator;
	}
	return r1.numerator * r2.denominator < r2.numerator * r1.denominator;

}
/*
output

exercise_1():
res1: status: 0 , writeTo: 0
res2: status: 0 , writeTo: 0
res3: status: 0 , writeTo: 1
modify res2, res3
res2: status: 1 , writeTo: 1
res3: status: 1 , writeTo: 1
check status res1 and res2: resource unavailable
check status res2 and res3: resource available

exercise_2() test cases:
4/8
4/6

8000/16000
150/300

-100/200
-200/300

exercise_2():
Please input rational r1 with numerator and denominator(like -1/2, 15/32, or -300/-401): 4/8
r1: 1/2
Please input rational r2 with numerator and denominator(like -1/2, 15/32, or -300/-401): 4/6
r2: 2/3
r1 + r2: 7/6
r1 - r2: -1/6
r1 * r2: 1/3
r1 / r2: 3/4
r1 less than r2

exercise_2():
Please input rational r1 with numerator and denominator(like -1/2, 15/32, or -300/-401): 8000/16000
r1: 1/2
Please input rational r2 with numerator and denominator(like -1/2, 15/32, or -300/-401): 150/300
r2: 1/2
r1 + r2: 1
r1 - r2: 0
r1 * r2: 1/4
r1 / r2: 1
r1 equal r2

exercise_2():
Please input rational r1 with numerator and denominator(like -1/2, 15/32, or -300/-401): -100/200
r1: -1/2
Please input rational r2 with numerator and denominator(like -1/2, 15/32, or -300/-401): -200/300
r2: -2/3
r1 + r2: -7/6
r1 - r2: 1/6
r1 * r2: 1/3
r1 / r2: 3/4
r1 more than r2

 */

