/*
 * DElement.h
 *
 *  Created on: Oct 11, 2023
 *      Author: HUY
 */

#ifndef DELEMENT_H_
#define DELEMENT_H_

class DElement {
private:
	int data;
	DElement *next;
	DElement *prev;
	int nNum;


public:
	void showdata();
    int getdata();
	void setdata(int);

	DElement* getNext();
	void setNext(DElement*);
	DElement* getPrev();
	void setPrev(DElement*);

	DElement();
	virtual ~DElement();
};

#endif /* DELEMENT_H_ */
