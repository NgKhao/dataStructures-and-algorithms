#include "hashTable.h"
#include<iostream>
#include<iomanip>
using namespace std;

hashTable::hashTable(int sz) : TABLE_SIZE(sz), curr_size(0)
{
    //ctor
    table = new hashNode * [TABLE_SIZE];
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = nullptr;
    }
}

hashTable::~hashTable()
{
    //dtor
}

int hashTable::hashFunc(string fullName)
{
    int sum = 0;
    for(int i=0; i < fullName.size(); i++)
        sum += (int)tolower(fullName[i]);
    return sum % TABLE_SIZE;
}

int hashTable::hashFunc2(string fullName)
{
    int sum = 0;
    for(int i=0; i < fullName.size(); i++)
        sum += (int)tolower(fullName[i]);
    return 1 + (sum % 13);
}
// hàm xử lý xung đột bậc 2
int hashTable::doubleProbe(string fullName, int i)
{
    return (hashFunc(fullName) + i * hashFunc2(fullName)) % TABLE_SIZE;
}

void hashTable::insertNode(hashNode *p)
{
//    check curr size đạt tới size table chưa??
    if(curr_size == TABLE_SIZE)
        return;
    int hashIndex = hashFunc(p->getFullName());
    if(table[hashIndex] == nullptr || table[hashIndex]->getFullName().empty() || table[hashIndex]->getFullName() == p->getFullName())
        table[hashIndex] = p;
    else
    {
        int i = 1;
        int curr_index = doubleProbe(p->getFullName(), i);
        while(curr_index != hashIndex)
        {
            if(table[curr_index] == nullptr || table[curr_index]->getFullName().empty() || table[curr_index]->getFullName() == p->getFullName())
            {
                table[curr_index] = p;
                break;
            }
            ++i;
            curr_index = doubleProbe(p->getFullName(), i);
        }
    }
    ++curr_size;
}

bool hashTable::deleteNode(string fullName)
{
    int hashIndex = hashFunc(fullName);
//    check phần tử của hashIndex có nullptr ko?; vì nếu nullptr thì ko truy cập đến getFullName() đc
    if(table[hashIndex] == nullptr) return false;
//  xoá phần tử tại hashIndex
    else if(table[hashIndex]->getFullName().compare(fullName) == 0)
    {
        delete table[hashIndex];
        table[hashIndex] = nullptr; // khi delete(giai phong) cần cập nhập lại con trỏ bằng null
//        vì ko cập nhập né sẽ trỏ đến 1 địa chỉ vùng nhớ không xác định
        --curr_size;
        return true;
    }

//    xóa phần tử khi bị xung đột tại index
    int i = 1;
    int curr_index = doubleProbe(fullName, i);
//    curr_index phải khác index && ptu tại đó ko đc NULL
//    khác index dành cho TH cả bảng có chung 1 index ban đầu
    while(curr_index != hashIndex && table[curr_index] != nullptr)
    {
        if(table[curr_index]->getFullName().compare(fullName) == 0)
        {
            delete table[curr_index];
            table[curr_index] = nullptr; // khi delete(giai phong) cần cập nhập lại con trỏ bằng null
//        vì ko cập nhập nó sẽ trỏ đến 1 địa chỉ vùng nhớ không xác định
            --curr_size;
            return true;
        }
        ++i;
        curr_index = doubleProbe(fullName, i);
    }
    return false;
}

hashNode* hashTable::searchNode(string fullName)
{
    int hashIndex = hashFunc(fullName);
//    check phần tử của hashIndex có nullptr ko?; vì nếu nullptr thì ko truy cập đến getFullName() đc
    if(table[hashIndex] == nullptr) return nullptr;

    else if(table[hashIndex]->getFullName().compare(fullName) == 0)
        return table[hashIndex];

//    find phần tử khi bị xung đột tại hashIndex
    int i = 1;
    int curr_index = doubleProbe(fullName, i);
//    curr_index phải khác index && ptu tại đó ko đc NULL
//    khác index dành cho TH cả bảng có chung 1 index ban đầu
    while(curr_index != hashIndex && table[curr_index] != nullptr)
    {
        if(table[curr_index]->getFullName().compare(fullName) == 0)
        {
            return table[i];
        }
//            chia phần trăm đề khi duyệt tới cuối thì chia dư i sẽ về 0, cách này ok hơn là tăng i
        ++i;
        curr_index = doubleProbe(fullName, i);
    }
    return nullptr;
}

void hashTable::display()
{

    // Traverse the entire hash table
    for (int i=0; i < TABLE_SIZE; ++i) {
//        cout <<      "  +--------+--------+" << endl;
        cout << i << " |";
//        hashNode* p = table[i];
        if (table[i] == nullptr ) {
            // NULL record, print empty
            cout << "[" << setw(6) << "" << " ]";// | " << setw(6) << "" << " |";
            }
        if(table[i] != nullptr) {
            // Print the record from the table
            cout << "[ " << table[i]->getFullName() << " | " << table[i]->getStudentEmail() << ", " << table[i]->getPhoneNumber() << ", " << table[i]->getStudentID() << " ]";
//
//            // Traverse and print the chain
//            for (p = p->getNext(); p != nullptr ; p = p->getNext()) {
//              cout << " --> " << "[ " << p->getFullName() << " | " << p->getStudentEmail() << ", " << p->getPhoneNumber() << ", " << p->getStudentID() << " ]";
//            }
        }
        cout << endl;
    }
    cout << endl;
}
