#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
//    int x;
//    Stack *s=new Stack();
//    for(int i=0; i < 3; i++)
//    {
//        cout << "\nNhap phan tu "<< i+1<<": "; cin >> x;
//        s->push(x);
//    }
//    for(int i=0; i<4; i++)
//    {
//        if(s->isEmpty())
//        {
//            cout << "\nSTACK RONG, KHONG LAY DUOC PHAN TU" << endl;
//        }
//        else
//        {
//            int val = s->pop();
//            cout << "\nGia tri lay ra: " << val;
//        }
//    }
    Stack *s = new Stack();
    int coSo10;
    cout << "\nNhap gia tri he thap phan: "; cin >> coSo10;
    int coSoCanChuyen;
    cout<< "\nNhap co so can chuyen (2, 8, 16): "; cin >> coSoCanChuyen;
    s->chuyenHeCoSo(coSoCanChuyen, coSo10);
    s->printStackHeCoSo();

    return 0;
}
