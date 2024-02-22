#include<iostream>
#include<math.h>
using namespace std;

//	return so dao nguoc
int ReverseNum(int n){
	int tmp = 0;
	while(n != 0){
		int tail = n % 10;
		tmp = tmp * 10 + tail;
		n /= 10;
	}
	return tmp;
}

//	bool so doi xung
bool SymmetricalNum(int n){
	int tmp = n;
	return ReverseNum(n) == tmp;
}

// so chinh phuong
bool SquareNum(int n){
	int canNum = sqrt(n);
	return canNum * canNum == n;	
}

// so nguyen to
bool PrimeNum(int n){
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0){
			return 0;
		}
	}
	return n > 1;
} 

// tong chu so le
int OldSum(int n){
	int sum = 0;
	while(n != 0){
		int tail = n % 10;
		if(tail % 2 != 0 ){
			sum += tail;
		}
		n /= 10;
	}
	return sum;
}

// tong chu so nguyen to
int PrimeSum(int n){
	int sum = 0;
	while(n != 0){
		int tail = n% 10;
		if(PrimeNum(tail)){
			sum += tail;
		}
		n /= 10;
	}
	return sum;
}

// tong chu so chinh phuong
int SquareSum(int n){
	int sum = 0;
	while(n != 0){
		int tail = n% 10;
		if(SquareNum(tail)){
			sum += tail;
		}
		n /= 10;
	}
	return sum;
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
			cout << "** 1. Tra ve so dao cua so do                   **\n";
			cout << "** 2. Co phai la so doi xung                    **\n";
			cout << "** 3. Co phai la so chinh phuong                **\n";
			cout << "** 4. Co phai la so nguyen to                   **\n";
			cout << "** 5. Tong cac chu so le                        **\n";
			cout << "** 6. Tong cac chu so nguyen to                 **\n";
			cout << "** 7. Tong cac chu so chinh phuong              **\n";
			cout << "** 0. Thoat khoi chuong trinh                   **\n";
			cout << "**************************************************\n";
			cout << "Nhap lua chon cua ban: ";
			int key; cin >> key;
			switch(key){
				case 1:
					cout << "So dao can tim la: " << ReverseNum(n) << endl;
					break;
				case 2:
					cout << (SymmetricalNum(n) ? "YES\n" : "NO\n");
					break;
				case 3:
					cout << (SquareNum(n) ? "YES\n" : "NO\n");
					break;
				case 4:
					cout << (PrimeNum(n) ? "YES\n" : "NO\n");
					break;
				case 5:
					cout << OldSum(n);
					break;
				case 6:
					cout << PrimeSum(n);
					break;
				case 7:
					cout << SquareSum(n);
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
