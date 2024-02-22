/*
 * LinkedList.h
 *
 *  Created on: Sep 18, 2023
 *      Author: HUY
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include "Element.h"
class LinkedList {
	Element* head;
	Element* tail;
	int nNum;

public:
	void insertFirst(Element*);
	bool deletefirst();
	bool deletetail();
	void travel();
	Element *getHead();
	LinkedList();
	virtual ~LinkedList();
};

#endif /* LINKEDLIST_H_ */
