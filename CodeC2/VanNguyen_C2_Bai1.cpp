//Chuong 2 Bai 1
#include <iostream>
using namespace std;

#define MAX 100
//1.1 Khai bao cau truc danh sach
int a[MAX], n;
//1.2 Nhap danh sach
void input (int a[], int &n)
{
	cout << "Nhap so luong phan tu: ";
	do {
		cin >> n;
		if (n > MAX)
			cout << "So luong phan tu phai nho hon 100!! Nhap lai: ";
	} while (n > MAX);
	cout << "Nhap " << n << " so nguyen: ";
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
//1.3 Xuat danh sach
void output (int a[], int n)
{
	cout << "Danh sach hien tai la\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << "	";
	cout << endl;
}
//1.4 Tim kiem
void search (int a[], int n, int x)
{
	int soLan = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == x)
		{
			soLan++;
			if (soLan == 1)
				cout << "Da tim thay gia tri " << x << " tai vi tri:";
			cout << " " << i;
		}
	if (soLan == 0)
		cout << "Khong tim thay gia tri " << x << " trong mang!";
	cout << endl;
}
//1.5 Them cuoi danh sach
void insert_last (int a[], int &n, int x)
{
		a[n++] = x;
}
//1.6 Xoa cuoi danh sach
void delete_last (int a[], int &n)
{
		n--;
}
//1.7 Xoa tai vi tri i
void delete_i (int a[], int &n, int i)
{
	if (i == n)
		delete_last(a,n);
	else
		{
			for (int j = i; j < n; j++)
				a[j] = a[j+1];
			n--;
		}
}
//1.8 Tim va xoa
void search_n_delete (int a[], int &n, int x)
{
	int soLan = 0, j = -1;
	for (int i = 0; i < n; i++)
	{
		j++;
		if (a[i] == x)
		{
			soLan++;
			if (soLan == 1)
				cout << "Da tim thay va xoa gia tri " << x << " tai vi tri:";
			cout << " " << j+1;
			delete_i(a,n,i);
			i--;
		}
	}
	if (soLan == 0)
		cout << "Khong ton tai gia tri " << x << " trong mang";
	cout << endl;
}

int main()
{
	int choice, x, i;
	cout << "----------- BAI 1 CHUONG 2 -----------\n";
	cout << "1. Nhap danh sach\n";
	cout << "2. Xuat danh sach\n";
	cout << "3. Tim kiem\n";
	cout << "4. Them cuoi danh sach\n";
	cout << "5. Xoa cuoi danh sach\n";
	cout << "6. Xoa tai vi tri thu i\n";
	cout << "7. Tim kiem va xoa\n";
	cout << "8. thoat\n";
	
	do {
		cout << "Lua chon cua ban: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			input(a,n);
			break;
		case 2:
			output(a,n);
			break;
		case 3:
			if (n > 0)
			{
				cout << "Nhap gia tri muon tim kiem: ";
				cin >> x;
				search(a,n,x);
			}
			else
				cout << "Mang khong co phan tu de thuc hien!\n";
			break;
		case 4:
			if (n < MAX)
			{
				cout << "Nhap gia tri muon them: ";
				cin >> x;
				insert_last(a,n,x);
				cout << "Da them thanh cong!!!\n";
				output(a,n);
			}
			else
				cout << "Khong the them phan tu do vuot qua gioi han!\n";
			break;
		case 5:
			if (n > 0)
			{
				delete_last(a,n);
				cout << "Xoa thanh cong!!!\n";
				output(a,n);
			}
			else
				cout << "Mang khong co phan tu de thuc hien!\n";
			break;
		case 6:
			if (n > 0)
			{
				cout << "Nhap vi tri muon xoa: ";
				cin >> i;
				delete_i(a,n,i-1);
				cout << "Xoa thanh cong!!!\n";
				output(a,n);
			}
			else
				cout << "Mang khong co phan tu de thuc hien!\n";
			break;
		case 7:
			if (n > 0)
			{
				cout << "Nhap gia tri muon tim kiem de xoa: ";
				cin >> x;
				search_n_delete(a,n,x);
				output(a,n);
			}
			else
				cout << "Mang khong co phan tu de thuc hien!\n";
			break;
		default:
			cout << "Goodbye!!!\n";
			choice = 8;
			break;
		}
	} while (choice != 8);
	return 0;
}