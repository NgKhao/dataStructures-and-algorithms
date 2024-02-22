#include <iostream>
#include"hashNode.h"
#include"hashTable.h"
using namespace std;

int main()
{
    hashTable *st = new hashTable(20);
    st->insertNode(new hashNode("Lan", "001", "lan@gmail.com", "0922222222"));
    st->insertNode(new hashNode("Phong", "002", "phong@gmail.com", "093333333"));
    st->insertNode(new hashNode("Thuy", "003", "thuy@gmail.com", "098273732"));
    st->insertNode(new hashNode("Ha", "004", "ha@gmail.com", "0944444444"));
    st->insertNode(new hashNode("Anh", "005", "anh@gmail.com", "0955555555"));
    st->insertNode(new hashNode("Ban", "006", "ban@gmail.com", "0966666666"));
    st->insertNode(new hashNode("Aan", "007", "aan@gmail.com", "0966666666"));
    st->insertNode(new hashNode("Cuong", "008", "cuong@gmail.com", "097777777"));
    st->insertNode(new hashNode("Khag", "009", "khag@gmail.com", "098888888"));
    st->insertNode(new hashNode("Yem", "010", "yem@gmail.com", "09999999999"));
    st->display();
    st->deleteNode("Lan");
    st->display();
    cout << st->searchNode("Phong")->getStudentEmail();
    return 0;
}
