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
        int curr_index = (hashIndex + 1) % TABLE_SIZE;
        while(curr_index != hashIndex)
        {
            if(table[curr_index] == nullptr || table[curr_index]->getFullName().empty() || table[curr_index]->getFullName() == p->getFullName())
            {
                table[curr_index] = p;
                break;
            }
//            chia phần trăm đề khi duyệt tới cuối thì chia dư i sẽ về 0, cách này ok hơn là tăng i
            curr_index = (curr_index + 1) % TABLE_SIZE;
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

//    xóa phần tử khi bị xung đột tại hashIndex
    int curr_index = (hashIndex + 1) % TABLE_SIZE;
//    i phải khác hashIndex && ptu tại đó ko đc NULL
//    khác hashIndex dành cho TH cả bảng có chung 1 hashIndex ban đầu
    while(curr_index != hashIndex && table[curr_index] != nullptr)
    {
        if(table[curr_index]->getFullName().compare(fullName) == 0)
        {
            delete table[curr_index];
            table[curr_index] =nullptr; // khi delete(giai phong) cần cập nhập lại con trỏ bằng null
//        vì ko cập nhập né sẽ trỏ đến 1 địa chỉ vùng nhớ không xác định
            --curr_size;
            return true;
        }
//            chia phần trăm đề khi duyệt tới cuối thì chia dư i sẽ về 0, cách này ok hơn là tăng i
        curr_index = (curr_index + 1) % TABLE_SIZE;
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
    int curr_index = (hashIndex + 1) % TABLE_SIZE;
//    i phải khác hashIndex && ptu tại đó ko đc NULL
//    khác hashIndex dành cho TH cả bảng có chung 1 hashIndex ban đầu
    while(curr_index != hashIndex && table[curr_index] != nullptr)
    {
        if(table[curr_index]->getFullName().compare(fullName) == 0 )
        {
            return table[curr_index];
        }
//            chia phần trăm đề khi duyệt tới cuối thì chia dư i sẽ về 0, cách này ok hơn là tăng i
        curr_index = (curr_index + 1) % TABLE_SIZE;
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
