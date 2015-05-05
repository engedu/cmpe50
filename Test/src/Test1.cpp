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

void testvector() {
	vector<int> v(10);

	v.push_back(1);
	cout << v.size();

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
//	testvector();
	testStringP();
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





