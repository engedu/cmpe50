/*
 * circle.h
 *
 *  Created on: May 4, 2015
 *      Author: yutao
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_
#include "figure.h"

class Circle : public Figure
{

public:
	virtual void erase();
	virtual void draw();
};
#endif /* CIRCLE_H_ */
