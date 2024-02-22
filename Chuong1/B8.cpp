#include<iostream>
using namespace std;

// S = 1 + 2 + ... + n
long long Sum1(int n){
	if( n == 1 ) return 1;
	return n + Sum1( n - 1 );
}

// S = 1^2 + 2^2 + 3^2 + ... + n^2
long long Sum2(int n){
	if( n == 1 ) return 1;
	return n * n + Sum2( n - 1 );
}

// S = 1 + 1/2 +  .... + 1/n
float Sum3(int n){
	if( n == 1 ) return 1;
	return 1.0 * 1 / n + Sum3( n - 1 );
}

// S = 1 * 2 * .... * n
long long Sum4(int n){
	if( n == 1 ) return 1;
	return n * Sum4( n - 1 );
}

// S = 1! + 2! + ... + n!
long long Sum5(int n){
	if( n == 1) return 1;
	return Sum4(n) + Sum5(n-1);
}

int main(){
	char continueChoice;
	do {
		cout << "\nNhap 1 so nguyen duong n: ";
		int n; cin >> n;
		while(n <= 0){
			cout << "So vua nhap khong hop le. Vui long nhap so nguyen duong khac";
			cout << "\nNhap 1 so nguyen duong n: "; cin >> n;
		}
		while(true){
			cout << "\n\n";
			cout << "**********************MENU************************\n";
			cout << "** 1. S = 1 + 2 + … + n                         **\n";
			cout << "** 2. S = 1^2 + 2^2 + … + n^2                   **\n";
			cout << "** 3. S = 1 + 1/2 + … + 1/n                     **\n";
			cout << "** 4. S = 1 * 2 * … * n                         **\n";
			cout << "** 5. S = 1! + 2! + … + n!                      **\n";
			cout << "** 0. Thoat khoi chuong trinh                   **\n";			
			cout << "**************************************************\n";
			cout << "Nhap lua chon cua ban: ";
			int key; cin >> key;
			switch(key){
				case 1:
					cout << "\nGia tri cua S = 1 + 2 + … + n la: "<< Sum1(n) << endl;
					break;
				case 2:
					cout << "\nGia tri cua S = 1^2 + 2^2 + … + n^2 la: " << Sum2(n) << endl;
					break;
				case 3:
					cout << "\nGia tri cua S = 1 + 1/2 + … + 1/n la: " << Sum3(n) << endl;
					break;
				case 4:
					cout << "nGia tri cua S = 1 * 2 * … * n la: " << Sum4(n) << endl;
					break;
				case 5:
					cout << "\nGia tri cua 5. S = 1! + 2! + … + n! la:" << Sum5(n) << endl;
					break;
				case 0:
					cout << "\nBan da thoat khoi Menu\n";
					break;
				default:
					cout << "\nKhong co chuc nang nay!";
					cout << "\nHay chon chuc nang khac trong Menu.";
			}
			if(key == 0) break;
	    }
	    do{
	    	cout << "\n\nNhap N de thoat hoac nhap Y de nhap so khac: ";
        	cin >> continueChoice;
        	if (continueChoice == 'N') {
            	cout << "\nBan da thoat khoi chuong trinh\n";
            	system("Pause");
            	return 0;
	    	}else if( continueChoice != 'Y'){
            	cout << "\nKi tu vua nhap khong hop le. Vui long nhap 1 ki tu khac";
        	}
			else{
				break;
			}	
		}while (continueChoice != 'Y');
    } while (true);
	return 0;
}

