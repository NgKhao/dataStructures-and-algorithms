#include<iostream>
using namespace std;

//	UCLN
int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int sumGcd(int a,int b,int c){
	return gcd(a, b) + gcd(b, c) + gcd(a, c);
} 

int main(){
	cout << "\nNhap so nguyen a, b, c: ";
	int a, b, c; cin >> a >> b >> c;
	while(a < 0 || b < 0 || c < 0){
		cout << "\na, b,c khong hop le!" << endl;
		cout << "\nNhap so nguyen a, b, c: ";
		cin >> a >> b >> c;
	}
	cout << "\nTong USCLN: " << sumGcd(a, b, c) <<endl;
	return 0;
}
