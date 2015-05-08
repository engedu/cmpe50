/*
 * administrator.cpp
 *
 *  Created on: May 4, 2015
 *      Author: yutao
 */
#include <iostream>
#include "administrator.h"
using namespace std;


void Administrator::set_supervisor(string s)
{
	supervisor = s;
}

void Administrator::input(istream& in)
{
	cout << "Please input name:\n";
	string name;
	in >> name;
	this->set_name(name);

	cout << "Please input ssn:\n";
	string ssn;
	in >> ssn;
	this->set_ssn(ssn);

	cout << "Please input title:\n";
	in >> title;

	cout << "Please input responsibility:\n";
	in >> responsibility;

	cout << "Please input supervisor:\n";
	in >> supervisor;

	cout << "Please input salary:\n";
	in >> salary;//annual salary
}

void Administrator::print(ostream& out)
{
	out << "\n__________________________________________________\n";
	out << "title: " << title << endl;
	out << "responsibility: " << responsibility << endl;
	out << "supervisor: " << supervisor << endl;
	out << "_________________________________________________\n";

}

void Administrator::print_check()
{
	set_net_pay(salary);
	cout << "\n__________________________________________________\n";
	cout << "Pay to the order of " << get_name( ) << endl;
	cout << "The sum of " << get_net_pay( ) << " Dollars\n";
	cout << "_________________________________________________\n";
	cout << "Check Stub NOT NEGOTIABLE \n";
	cout << "Employee Number: " << get_ssn( ) << endl;
	cout << "Salaried Employee. Regular Pay: "
		 << salary << endl;
	cout << "_________________________________________________\n";
}




