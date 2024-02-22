#include<iostream>
#include<math.h>
using namespace std;

//	Phuong trinh bac1
void FirstDegreeEquation(int a, int b){
	if(a == 0){
		if(b == 0){
			cout << "\nPhuong Trinh co vo so nghiem\n";
		}
		else{
			cout << "\nPhuong trinh vo nghiem\n";
		}
	}
	else{
		cout << "\nPhuong trinh co nghiem don la x = " << 1.0 * - b / a << endl;
	}
}

void QuadraticEquation(int a, int b, int c){
	if(a == 0){
		FirstDegreeEquation(b, c);
	}
	else{
		int delta = b * b - 4 * a * c;
		if(delta < 0){
			cout << "\nPhuong trinh vo nghiem\n";
		}
		else if(delta == 0){
			cout << "\nPhuong trinh co nghiem kep: x1 = x2 = " << 1.0 * - b / 2 * a << endl;
		}
		else{
			cout << "\nPhuong trinh co 2 nghiem phan biet: x1 = " <<1.0 * (- b +  sqrt(delta)) / (2 * a)<< " x2 = " << 1.0 * (- b - sqrt(delta))/ (2 * a) << endl; 
		}
	}
}

void Min(int a[]){
	int min = INT_MAX;
	for(int i=0; i<4; i++){
		if (a[i] < min){
			min = a[i];
		}
	}
	cout << "\nGTNN cua 4 so nguyen la: " << min << endl;
}

// swap
void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp; 
}

// sx 3 so nguyen tang dan
void sort(int a[]){
	for(int i=0; i<3; i++){
		for(int j= i+1; j<3; j++){
			if(a[i] > a[j]){
				swap(a[i], a[j]);
			}
		}
	}
	cout << "\n3 so nguyen tang dan lan luot: ";
	for(int i=0; i<3; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}
int main(){
	while(1){
		cout << "\n\n";
		cout << "**********************MENU************************\n";
		cout << "** 1. Giai phuong trinh bac nhat                **\n";
		cout << "** 2. Giai phuong trinh bac hai                 **\n";
		cout << "** 3. GTNN cua 4 so nguyen                      **\n";
		cout << "** 4. Hoan vi 2 so nguyen                       **\n";
		cout << "** 5. Sap xep 3 so nguyen tang dan              **\n";
		cout << "**************************************************\n";
		cout << "Nhap lua chon cua ban: ";
		int key; cin >> key;
		switch(key){
			case 1:
				cout << "\nNhap 2 so nguyen a, b: ";
				int a1, b1; cin >> a1 >> b1;
				FirstDegreeEquation(a1, b1);
			case 2:
				cout << "\nNhap 3 so nguyen a, b, c: ";
				int x, y, z; cin >> x >> y >> z;
				QuadraticEquation(x, y, z);
				break;
			case 3:
				int arr1[4];
				for(int i=0; i < 4; i++){
					cout << "\nNhap so a[" << i << "] = ";
					cin >> arr1[i];
				}
				Min(arr1);
				break;
			case 4:
				cout << "\nNhap 2 so nguyen a, b: ";
				int a2, b2; cin >> a2 >> b2;	
				swap(a2, b2);
				cout << "\n 2 so sau khi hoan vi a = " << a2 << " b = " << b2 <<endl;
				break;
			case 5:
				int arr2[3];
				for(int i=0; i < 3; i++){
					cout << "\nNhap so a[" << i << "] = " ;
					cin >> arr2[i];
				}		
				sort(arr2);						
				break;
			case 0:
				cout << "\nBan da chon thoat chuong trinh\n";
				return 0;
		}
	}
	return 0;
}
