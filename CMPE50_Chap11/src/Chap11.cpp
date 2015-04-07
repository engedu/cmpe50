/*
 * Chap11.cpp
 *
 *  Created on: Apr 3, 2015
 *      Author: yutao
 */
#include <iostream>
using namespace std;

class DayOfYear
{
public:
	DayOfYear();
	DayOfYear(int m, int d);

	friend bool equal(DayOfYear& date1, DayOfYear& date2);

	friend DayOfYear operator +(DayOfYear date1, DayOfYear date2);

	void output();
private:
	int month;
	int day;
};


int main() {
	DayOfYear date1(1, 2);
	date1.output();


	return 0;
}

DayOfYear::DayOfYear() : month(0), day(0)
{

}
DayOfYear::DayOfYear(int m, int d)
{
	month = m;
	day = d;
}

void DayOfYear::output()
{
	cout << month << day;
}

bool equal(DayOfYear& date1, DayOfYear& date2)
{
	return (date1.month == date2.month) && (date1.day == date2.day);
}

DayOfYear operator +(DayOfYear date1, DayOfYear date2) {
	DayOfYear result;
	return result;
}
