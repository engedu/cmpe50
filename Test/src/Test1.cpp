/*
 * Test1.cpp
 *
 *  Created on: Jan 30, 2015
 *      Author: yutao
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//	const int size = 9;


class Tata
{
public:
	~Tata() {
		cout << "Tata gone!";
	}
};

class Bye : public Tata
{
public:
	~Bye() {
		cout << "Bye gone!";
	}
};

void testTataBye() {
//	Tata *pTata = new Bye;
//	delete pTata;

	Bye *pBye = new Bye;
	delete pBye;
}

void testvector() {
//	vector<int> v(10);
//
//	v.push_back(1);
//	cout << v.size();

	vector<int> vec1;
	vec1.push_back(2);
	cout << vec1.capacity() << endl;
	vec1.reserve(vec1.capacity() + 1);
	cout << vec1.capacity() << endl;
	int i = vec1[0];
	cout << i << endl;
}

void testStringP() {
	string *p = new string("a");

	cout << *p;

}
void get_input(double& f_variable)
{
	cin >> f_variable;
}

void negative_array()
{
	int size = -9;
	int* p = new int[size];
}

int main()
{
	testTataBye();
//	testvector();
//	testStringP();
//	double f_variable;
//	get_input(f_variable);
//	cout << f_variable << endl;


	// test exit
//	cout << "msg before exit 1" << endl;
//	exit(1);
//	cout << "msg after exit 1" << endl;

//	cout.setf(ios::showpos);
//	cout.width(10);
//	cout << 1 << endl;
//	cout.width(10);
//	cout << 2 << endl;
//	int array[10];
//	int size;
//	cout << "Input the size of array:\n";
//	cin >> size;
//	int array[size];
//	for (int i = 0; i < size; i++) {
//		array[i] = i;
//
//	}
//
//
//	for (int i = 0; i < size; i++) {
//		cout << array[i] << endl;
//	}
//
//	cout << endl;
//	cout << (array + 3)[0] << endl;
//	int array[] = {0, 0, 0};
//	int array[size];

//	negative_array();
}





