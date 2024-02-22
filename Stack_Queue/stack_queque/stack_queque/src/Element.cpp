/*
 * Element.cpp
 *
 *  Created on: Sep 18, 2023
 *      Author: HUY
 */

#include "Element.h"

Element::Element() {
	// TODO Auto-generated constructor stub
   this->data=0;
   this->pointer=nullptr;
}
Element::Element(int d) {
	// TODO Auto-generated constructor stub
   this->data=d;
   this->pointer=nullptr;
}
void Element::showdata(){
	cout<<this->data;
}
int Element::getdata(){
	return this->data;
}
void Element::setdata(int d){
	this->data=d;
}
Element* Element::getPointer(){
     return this->pointer;
}
void Element::setPointer(Element*p){
     this->pointer=p;
}
Element::~Element() {
	// TODO Auto-generated destructor stub
}

