/*
 * Element.h
 *
 *  Created on: Sep 18, 2023
 *      Author: HUY
 */

#ifndef ELEMENT_H_
#define ELEMENT_H_
#include <iostream>
using namespace std;
class Element {
private:

	int data;
	Element *pointer;

public:

	Element();
	Element(int);
	void showdata();
	int getdata();
	void setdata(int);

    Element* getPointer();
    void setPointer(Element*);
	virtual ~Element();
};

#endif /* ELEMENT_H_ */
