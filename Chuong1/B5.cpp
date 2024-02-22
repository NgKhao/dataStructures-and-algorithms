#include<iostream>
using namespace std;

// Giai thua
int Fact(int n){
	if(n == 0) return 1;
	return n * Fact(n-1);
}

// Fibonacii F[1] = 1, F[2] = 1, F[3] = 2, ....
long long Fibo(int n){
	if( n ==1 || n==2 ) return 1;
	return Fibo(n-1) + Fibo(n-2);
}

// Tong Fibo
long long SumFibo(int n){
	long long sum = 0;
	for(int i=1; i <= n; i++){
		sum += Fibo(i);
	}
	return sum;
}

int main(){
	cout << "\nNhap so nguyen M, N: ";
	int M, N; cin >> M >> N;
	while(M < 0 || N < 0 ){
		cout << "\nM, N khong hop le!" << endl;
		cout << "\nNhap so nguyen M, N: ";
		cin >> M >> N;
	}
	cout << "\nTong: " << Fact(M) + SumFibo(N) <<endl;
	return 0;
}
