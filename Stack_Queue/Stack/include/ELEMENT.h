#ifndef ELEMENT_H
#define ELEMENT_H

class ELEMENT
{
      public:
            ELEMENT();
            ELEMENT(int);
            virtual ~ELEMENT();

            int Getdata() { return data;}
            void Setdata(int val) {data = val;}
            ELEMENT* Getpointer() {return pointer;}
            void Setpointer(ELEMENT *val) {pointer = val;}

      protected:

      private:
            int data;
            ELEMENT *pointer;
};

#endif // ELEMENT_H
