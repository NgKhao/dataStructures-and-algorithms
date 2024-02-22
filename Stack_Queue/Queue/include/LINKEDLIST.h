#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "ELEMENT.h"

class LINKEDLIST
{
      public:
            LINKEDLIST();
            virtual ~LINKEDLIST();

            ELEMENT* Gethead() {return head;}
            void Sethead(ELEMENT *val) {head = val;}
            ELEMENT* Gettail() {return tail;}
            void Settail(ELEMENT *val) {tail = val;}
            void InsertFirst(ELEMENT*);
            void InsertTail(ELEMENT*);
            void InsertElementAfterNodep(ELEMENT*, int);
            void DeleteFirst();
            void DeleteTail();
            void DeleteNodep(ELEMENT*);
            void Travel();
            void RemoveAll();
      protected:

      private:
            ELEMENT *head;
            ELEMENT *tail;
};

#endif // LINKEDLIST_H
