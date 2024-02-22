/*
 * DLinkedList.h
 *
 *  Created on: Oct 11, 2023
 *      Author: HUY
 */

#ifndef DLINKEDLIST_H_
#define DLINKEDLIST_H_
#include "DElement.h"
class DLinkedList {
	DElement* head;
	DElement* tail;
	int nNum;
public:
	void insertFirst(DElement*);
	bool deletefirst();
	bool deletetail();
	void travel();
	DLinkedList();
	virtual ~DLinkedList();
};

#endif /* DLINKEDLIST_H_ */
