#include<iostream>
#include<math.h>
using namespace std;

//	chuoi fibonacci fib[0] = 0,  fib[1] = 1, fib[2] = 1
long long  InEvenFib(int startNum, int endNum){
	long long fib[90];
	fib[0] = 0;
	fib[1] = 1;
	for(int i = 2; i <= endNum; i++){
		fib[i] = fib[i-1] + fib[i-2];
	}
	
//	nap so chan Fib vao mang
	long long SumEvenFib = 0;
	int cnt = 0;
	for(int i = startNum; i <= endNum; i++){
		if(fib[i] % 2 == 0){
			SumEvenFib += fib[i];
		}
	}
	return SumEvenFib;
}
int main(){
	cout << "\nNhap so nguyen M, N: ";
	int M, N; cin >> M >> N;
	while(M < 0 || N < 0 || M >= N){
		cout << "\nM, N khong hop le!" << endl;
		cout << "\nNhap so nguyen M, N: ";
		cin >> M >> N;
	}
	cout << "\nTong so chan Fibonacci tu M den N: " << InEvenFib(M,N) <<endl;
	return 0;
}
