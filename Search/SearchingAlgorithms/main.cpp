#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;

//  Tìm kiếm tuần tự vét cạn (Exhaustive Linear)
int LinearExhaustive(int a[], int n, int x)
{
    for(int i=0; i<n; i++)
    {
        if(a[i] == x)
            return i;
    }
    return -1;
}

//  Tìm kiếm tuần tự lính canh (Sentinel Linear)
int SentinelLinear( int a[], int n, int x)
{
    // đặt lính canh ở cuối mảng có giá trị = x
    a[n] = x;
    for(int i=0; ; i++) // giúp bỏ được điều kiện cuối mảng
    {
        if(a[i] == x)
            return i;
    }
}

//  Tìm kiếm nhị phân (Binary Search)
int BinarySearch(int a[], int n, int x)
{
    int left = 0, right = n - 1;
    int mid;
    while( left <=  right)
    {
        mid = (left + right) / 2;
        if(x == a[mid])
            return mid;
        else if(x < a[mid])
            right = mid - 1;
        else //(x > a[mid])
            left = mid + 1;
    }
    return -1;
}

//  Tìm kiếm nhị phân (Binary Search) bằng đệ qui
int BinarySearchRe(int a[], int left, int right, int x)
{
    if(left > right)
        return -1;
    int mid = (left + right) / 2;
    if(x == a[mid])
        return mid;
    else if(x < a[mid])
        return BinarySearchRe(a, left, mid - 1, x);
    else
        return BinarySearchRe(a, mid + 1, right, x);
}


int main()
{
    volatile double sink;
    clock_t start, end;
    double cpu_time_used;
    start = clock();

      for(size_t i=0; i<3141592; ++i)
      sink+=sin(i);

//    // Khởi tạo seed cho hàm ngẫu nhiên
//    srand(static_cast<unsigned int>(time(0)));
//
//    const int arraySize = 100;
//    int a[arraySize];
//
//    // Tạo một mảng a với 100 phần tử ngẫu nhiên trong khoảng từ 1 đến 1000
//    for (int i = 0; i < arraySize; ++i) {
//        a[i] = rand() % 1000 + 1;
//    }
//
////    int a[7] = {2, 1, 4, 3, 6, 9, 5};
//    cout << LinearExhaustive(a, 100, 99);
////    cout << SentinelLinear(a, 7, 8);
//    int b[7] = {1, 2, 6, 26, 28, 37, 40};
////    cout << BinarySearchRe(b, 0, 6, 40); // testcase 2, 40, -7

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Thoi gian xu ly la: %f\n", cpu_time_used);
    return 0;
}


