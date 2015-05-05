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

}




