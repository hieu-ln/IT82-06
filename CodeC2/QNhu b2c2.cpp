#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 100

//cau 2.1
int a[MAX];
int n;

//Cau 2.2: them phan tu vao danh sach
void swap (int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
void quickSort(int a[], int left, int right)
{
	int x = a[(left + right)/2];
	int i = left;
	int j = right;
	while (i < j)
	{
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if( i <= j)
		{
			swap (a[i], a[j]); //doi cho
			i++;
			j--;
		}
	}
	if (left < j)
			quickSort(a, left, j);
	if (i < right)
		quickSort(a,i,right);
}
void input(int a[], int &n)
{
	cout <<"Nhap so phan tu cua danh sach: ";
	cin >>n;
	cout <<"Nhap cac phan tu cua danh sach (tang dan): " <<endl;
	for (int i = 0; i<n; i++)
	{
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
	quickSort(a, 0, n-1);
}

//Cau 2.3: xuat danh sach
void output(int a[], int n)
{
	for (int i = 0; i<n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;

}

//cau 2.4 Tim phan tu trong danh sach (tim kiem tuan tu)
int search(int a[], int n, int x)
{
	int i = 0;
	while (i<n && a[i]!=x)
	{
		i++;
		if (i == n)
			return -1;
	}
	return i;
}

//cau 2.4 Tim phan tu trong danh sach (tim kiem nhi phan)
int searchBinary (int a[], int l, int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2; //tuong duong (l+r)/2 uu diem tranh tran

		//Nếu a[mid] = x, tra ve chi so va ket thuc
		if (a[mid] == x)
			return mid;

		//Nếu a[mid] > x, tim nua trai
		if (a[mid] == x)
			return searchBinary(a, l, mid - 1, x);

		//Nếu a[mid] < x, tim nua phai
		return searchBinary(a, l, mid - 1, x);
	}
	 // Neu tim khong thay
	return -1;
}


//xoa phan tu tai vi tri i
int Delete(int a[], int &n, int i)
{
	if (i >= 0 && i<n)
	{
		for (int j=i; j<n-1; j++)
		{
			a[j] = a[j+1];
		}
		n--;
		return 1;
	}
	return 0;
}

//cau 2.6 tim 1  phan tu trong danh sach va xoa phan tu do
int SearchAndDelete(int a[], int &n, int x)
{
	for (int i=0; i<n; i++)
	{
		if (a[i] == x)
		{
			Delete(a, n, i);
			return 1;
		}
	}
	return 0;
}

//main
int main()
{
	int choice = 0;
	int x, i;
	system("cls");
	cout<<"				CHUONG2_B2			" << endl;
	cout<<"1. Nhap danh sach"<<endl;
	cout<<"2. Xuat danh sach"<<endl;
	cout<<"3. Tim kiem tuan tu"<<endl;
	cout<<"4. Tim kiem nhi phan"<<endl;
	cout<<"5. Tim phan tu va xoa"<<endl;
	cout<<"6. Thoat"<<endl;

	do
	{
		cout <<" Chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			input(a, n);
			cout <<"Nhap danh sach thanh cong! \n";
			break;
		case 2:
			cout <<"danh sach moi: \n";
			output(a, n);
			break;
		case 3:
			cout <<"Nhap x can tim: ";
			cin >> x;
			i = search(a, n, x);
			if(i == -1)
				cout <<"Khong tim thay phan tu co gia tri x" << x << endl;
			else
				cout <<"Tim thay tai vi tri i= " << i << endl;
			break;
		case 4:
			cout <<" Nhap x can tim: ";
			cin >> x;
			i = searchBinary(a,0,n,x);
			if(i == -1)
				cout <<"Khong tim thay phan tu co gia tri x" << x << endl;
			else
				cout <<"Tim thay tai vi tri i= " << i << endl;
			break;
		case 5:
			cout << "Nhap gia tri can xoa x= ";
			cin >> x;
			i = SearchAndDelete(a, n, x);
			if (i==1)
			{
				cout << "da xoa thanh cong phan tu co gia tri x= " << x << endl;
				cout << "Danh sach moi: \n";
				output(a, n);
			}
			else
				cout << "Khong tim thay phan tu de xoa!";
			break;
		case 6:
			cout << "Goodbye!";
			break;
		default:
			break;
		}
	}
	while (choice != 6);
	system("pause");
	return 0;
}


