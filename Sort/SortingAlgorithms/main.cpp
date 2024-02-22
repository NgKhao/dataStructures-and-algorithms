#include <iostream>
#include<fstream>
#include<vector>
using namespace std;
void swap(int &a, int &b)
{
    int tmp = b;
    b = a;
    a = tmp;
}

//Selection Sort ( Sắp xếp chọn)
void selectionSort(int arr[], int n)
{
    int min;
    for(int i = 0; i < n - 1; i++)
    {
        min = i;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }
        if(min != i)
            swap(arr[min], arr[i]);
    }
}

void insetionSort(int arr[], int n)
{
    int i, key, j;
    for(i = 1; i < n; i++)
    {
        key = arr[i];
        // duyệt ngược các ptu trước arr[i]
        j = i - 1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
//        duyệt ngược đến khi key lớn nhất thì gán nó cho vị trí đc chọn
        arr[j + 1] = key;
    }
}
//Head sort (sx vung dong)
// hàm dùng để build max heap cho tree
void heapify(int arr[], int n, int i)
{
    int largest = i;
//    child left
    int l = 2 * i + 1;
//child right
    int r = 2 * i + 2;
//đk 1 khi trong TH node lá, khi đó các node con ko có value sẽ dừng, đk 2 chú ý là so sánh với largest, ko phải i
    if(l < n && arr[l] > arr[largest])
        largest = l; // gán v để dễ dàng so sanh với nút right
    if(r < n && arr[r] > arr[largest])
        largest = r;
    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

//hàm duyệt cây và đưa từng node lớn nhất và mảng
void headSort(int arr[], int n)
{
//    build max head from last parent leaf to root
    for(int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for(int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
//        các nhánh đã được sx trừ root nên ko cần duyệt cách nhánh dưới mà chỉ cần xét root
        heapify(arr, i, 0);
    }
}


bool inputFile(string fileName, int arr[], int &n)
{
    ifstream fileIn(fileName);
    if(!fileIn.is_open())
        return false;
    int cnt = 0;
    int num;
    while(fileIn >> num) // tự tìm kiếm kiểu int và trả về true
        {
            arr[cnt++] = num;
        }
    n = cnt;
    fileIn.close();
    return true;
}

//Quick Sort (Sx nhanh)
int partition(int arr[], int left, int right)
{
    int pivot = arr[right]; // create pivot in last array
    int i = left - 1;
    for(int j = left; j < right; j++) // neu right ko cuoi mang thi xet j <= right
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[right]); // ko swap voi pivot vi neu TH co nhieu ptu bang pivot no se lay gia tri dau tien
    return i; // tra ve index da duoc xep
}

void quickSort(int arr[], int left, int right)
{
    if(left < right) // dk dung khi con 1 ptu
    {
        int pi = partition(arr, left, right);
        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
    }
}

// Merge Sort(sx tron)
//từ 1 mảng ban đầu tách mảng 2 vector so sánh lần lượt và gán các ptu đã sx của 2 vector vào mảng ban đầu
void merge(int arr[], int left, int mid, int right)
{
    vector<int> x(arr + left, arr + mid + 1);
    vector<int> y(arr + mid + 1, arr + right + 1);
    int i = 0, j = 0;
//    so sánh đến vector kết thúc đầu tiên
    while(i < x.size() && j < y.size())
    {
        if(x[i] < y[j])
            arr[left++] = x[i++];
        else
            arr[left++] = y[j++];
    }
//    gán ptu còn lại  của vector còn lại vào mảng
    while(i < x.size())
        arr[left++] = x[i++];
    while(j < y.size())
        arr[left++] = y[j++];
}

void mergeSort(int arr[], int left, int right)
{
    if(left >= right) // dk dung khi con 1 phan tu
        return;
    int mid = (left + right) / 2;
//    split ảmng cho đến khi còn 1 phần tử rồi trộn
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
int main()
{
//    int arr[] = {9, 14, 10, 5};
//    int arr[] = {5, 1, 2, 3, 8, 6, 23, 10};
    int arr[] = {12, 2, 15, -3, 8, 5, 1, -8, 6, 0, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
//    int arr[100];
//    int n;
//    if(!inputFile("input.txt", arr, n))
//        cout << "ko mo dc";
//    else
//    {
        insetionSort(arr, n);
//        selectionSort(arr, n);
//        headSort(arr, n);
//        quickSort(arr, 0, n - 1);
//        mergeSort(arr, 0, n - 1);
        for(int i=0; i<n; i++)
        {
            cout << arr[i] << " ";
        }
//    }
////cau 2
//    cout << "\nSo lon t3: " << arr[n - 3];
////cau 3
//    int cnt = 1;
//    for(int i = n - 2; i >= 0; i--)
//    {
//        if(arr[i] == arr[n - 1])
//            cnt++;
//    }
//    cout << "\nSo luong ptu lon nhat: " << cnt << endl;
////cau 4
//    for(int i = 0; i < n; i++ )
//    {
//        if(arr[i] < 0)
//            arr[i] *= -1;
//    }
//    selectionSort(arr, n);
//    for(int i=0; i<n; i++)
//    {
//        cout << arr[i] << " ";
//    }
    return 0;
}
