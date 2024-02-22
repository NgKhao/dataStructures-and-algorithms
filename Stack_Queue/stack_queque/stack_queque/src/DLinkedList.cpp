/*
 * DLinkedList.cpp
 *
 *  Created on: Oct 11, 2023
 *      Author: HUY
 */

#include "DLinkedList.h"

void DLinkedList::insertFirst(DElement*p){
   if(this->head==nullptr){
      this->head=this->tail=p;
   }else{
    	p->setNext(this->head);
    	this->head->setPrev(p);
    	this->head=p;
   }
   this->nNum++;
}
bool DLinkedList::deletetail(){

	if(this->head==nullptr)
		return false;
	else{
		DElement *p=this->tail;
		this->tail=this->tail->getPrev();
		delete p;
	}
}
DLinkedList::DLinkedList() {
	// TODO Auto-generated constructor stub
     this->tail=nullptr;
     this->head=nullptr;
     this->nNum=0;
}

DLinkedList::~DLinkedList() {
	// TODO Auto-generated destructor stub
}

