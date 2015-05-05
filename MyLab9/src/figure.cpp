/*
 * figure.cpp
 *
 *  Created on: May 4, 2015
 *      Author: yutao
 */
#include <iostream>
#include "figure.h"
using namespace std;


void Figure::erase()
{

	cout << "Figure::erase()" << endl;
}
void Figure::draw()
{

	cout << "Figure::draw()" << endl;
}

void Figure::center()
{
	erase();
	draw();
}



