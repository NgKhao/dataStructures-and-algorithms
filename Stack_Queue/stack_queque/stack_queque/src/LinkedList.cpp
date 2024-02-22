/*
 * LinkedList.cpp
 *
 *  Created on: Sep 18, 2023
 *      Author: HUY
 */

#include "LinkedList.h"

void LinkedList::insertFirst(Element*p){
   if(this->head==nullptr){
      this->head=this->tail=p;

   }else{
    	p->setPointer(this->head);
    	this->head=p;


   }

  this->nNum++;

}
void LinkedList::travel(){
    Element* p=this->head;
    while(p!=nullptr)
    {
    	p->showdata();
    	cout<<"\t";
    	p=p->getPointer();
    }
}
bool LinkedList::deletefirst(){
	if(this->head==nullptr) return false;
	else {
        Element*p=head;
        this->head=this->head->getPointer();
        delete p;
	}
	return true;
}
bool LinkedList::deletetail(){
	if(this->nNum==0) return false;
	if(this->nNum==1) return this->deletefirst();
	else {
		   Element *p=this->head;
		   while(p->getPointer()->getPointer()!=nullptr) // 1
			   p=p->getPointer();
		   delete this->tail;   // 2
		   tail=p;        // 3
		   tail->setPointer(nullptr);
		   this->nNum--;
		   return true;
	}
}
	Element *LinkedList::getHead(){
	 return this->head;
	}
LinkedList::LinkedList() {
	// TODO Auto-generated constructor stub
   this->head=nullptr;
   this->tail=nullptr;
   this->nNum=0;
}

LinkedList::~LinkedList() {
	// TODO Auto-generated destructor stub
}


