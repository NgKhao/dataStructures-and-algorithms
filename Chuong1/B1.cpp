#include<iostream>
#include<math.h>
using namespace std;

//	check so nto
bool checkNTo(int a){
	for(int i=2; i<=sqrt(a); i++){
		if(a % i == 0) return 0;
	}
	return a > 1;
}

// Sum so khong phai nto
int SumNTo(int N){
	int sum = 0;
	for(int i = 1; i <= N; i++){
		if(!checkNTo(i)){
			sum += i;
		}
	}
	return sum;
}
int main(){
	cout << "\nNhap so nguyen N: ";
	int N; cin >> N;
	while(N <= 0){
		cout << "\nN khong hop le!" << endl;
		cout << "\nNhap so nguyen N: ";
		cin >> N;
	}
	cout << "\nTong so khong phai so nguyen to la: " << SumNTo(N) <<endl;
	return 0;
}
