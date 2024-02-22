#include "Stack.h"

 void Stack::push(int x){

     this->linkedlist->insertFirst(new Element(x));
 }
 int Stack::pop(){
    int p=this->linkedlist->getHead()->getdata();
    this->linkedlist->deletefirst();
    return p;

 }
  void Stack::prinStack(){
      this->linkedlist->travel();
  }
Stack::Stack()
{
    //ctor
    this->nNum=0;
    this->linkedlist=new LinkedList();


}

Stack::~Stack()
{
    //dtor
}
