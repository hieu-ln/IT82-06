//C3_B1
#include <iostream>
#include <time.h>
#include <ctime>
using namespace std;

//1.1
#define MAX 5000
int a[MAX], n;

//1.0 Khoi tao ngau nhien
void init (int a[], int &n)
{
	cout << "Nhap so luong phan tu muon tao: ";
	cin >> n;
	for (int i = 0; i < n; i++)
		a[i] = rand() % 10000 + 1;
	cout << "Danh sach da khoi tao ngau nhien la:\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << "	";
	cout << endl;
}
//1.2 Nhap danh sach
void input (int a[], int &n)
{
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap a["<<i<<"] = ";
		cin >> a[i];
	}
}
//1.3 Xuat danh sach
void output (int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "	";
	cout << endl;
}
//Sao chep mang
void copyArray (int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}
//1.4 Insertion Sort
void insertionSort (int a[], int n)
{
	int x, j;
	for (int i = 1; i < n; i++)
	{
		x = a[i]; j = i-1;
		while (j >= 0 && x < a[j])
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = x;
	}
}
//Doi cho phan tu
void swap (int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
//1.5 Selection Sort
void selectionSort (int a[], int n)
{
	int min_p;
	for (int i = 0; i < n-1; i++)
	{
		min_p = i;
		for (int j = i+1; j < n; j++)
			if (a[j] < a[min_p])
				min_p = j;
		swap(a[i],a[min_p]);
	}
}
//1.6 Interchange Sort
void interchangeSort (int a[], int n)
{
	for (int i = 0; i < n-1; i++)
		for (int j = i+1; j < n; j++)
			if (a[j] < a[i])
				swap(a[j],a[i]);
}
//1.7 Bubble Sort
void bubbleSort (int a[], int n)
{
	for (int i = 0; i < n-1; i++)
		for (int j = n-1; j > i; j--)
			if (a[j] < a[j-1])
				swap(a[j],a[j-1]);
}
//1.8 Quick Sort
void quickSort (int a[], int left, int right)
{
	int x = a[(left + right)/2];
	int i = left, j = right;
	while (i < j)
	{
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i <= j)
		{
			swap(a[i],a[j]);
			i++; j--;
		}
	}
	if (left < j)
		quickSort(a,left,j);
	if (i < right)
		quickSort(a,i,right);
}
//1.9 Heap Sort
void shift (int a[], int i, int n)
{
	int j = 2*i + 1;
	if (j >= n)
		return;
	if (j+1 < n)
		if (a[j] < a[j+1])
			j++;
	if (a[i] >= a[j])
		return;
	else
	{
		swap(a[i],a[j]);
		shift(a,j,n);
	}
}
void heapSort (int a[], int n)
{
	int i = n / 2 - 1;
	while (i >= 0)
	{
		shift(a,i,n);
		i--;
	}
	int right = n - 1;
	while (right > 0)
	{
		swap(a[0],a[right]);
		right--;
		if (right > 0)
			shift(a,0,right);
	}
}
// Tim kiem
int search(int a[],int n,int x)
{
	int i=0;
	while(i<n&&a[i]!=x)
		i++;
	if (i<n)
		return i;
	return -1;
}
// Tim kiem nhi phan
int binarysearch(int a[],int n,int x)
{
	int left=0,right=n-1,mid;
	while (left<=right)
	{
		mid=(left+right)/2;
		if (a[mid]==x)
			return mid;
		if (x>a[mid])
			left=mid+1;
		else
			right=mid-1;
	}
	return -1;
}
int main()
{
	int b[MAX];
	clock_t start;
	double duration;
	int choice, x, i;
	system("cls");
	cout << "BAI TAP 1, CHUONG 3\n";
	cout << "0) Khoi tao danh sach ngau nhien\n";
	cout << "1) Nhap danh sach\n";
	cout << "2) Xuat danh sach\n";
	cout << "3) Xep tang dan danh sach bang SELECTION SORT\n";
	cout << "4) Xep tang dan danh sach bang INSERTION SORT\n";
	cout << "5) Xep tang dan danh sach bang BUBBLE SORT\n";
	cout << "6) Xep tang dan danh sach bang INTERCHANGE SORT\n";
	cout << "7) Xep tang dan danh sach bang QUICK SORT\n";
	cout << "8) Xep tang dan danh sach bang HEAP SORT\n";
	cout << "9) TIM KIEM TUAN TU phan tu x\n";
	cout << "10) TIM KIEM NHI PHAN phan tu x\n";
	cout << "12) Clear man hinh\n";
	cout << "11) Thoat\n";
	do {
		cout << "Hay nhap so de lua chon: ";
		cin >> choice;
		switch (choice)
		{
		case 0: //khoi tao random
			init(a,n);
			break;
		case 1: //nhap ds
			input(a,n);
			break;
		case 2: //xuat ds
			cout << "Danh sach da nhap:\n";
			output(a,n);
			break;
		case 3: //selection sort
			copyArray(a,b,n);
			start = clock();
			selectionSort(b,n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau sap xep SELECTION SORT\n";
				output(b,n);
			}
			cout << "Thoi gian SELECTION SORT: " << duration * 1000000 << " microseconds\n";
			break;
		case 4: //insertion sort
			copyArray(a,b,n);
			start = clock();
			insertionSort(b,n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau sap xep INSERTION SORT\n";
				output(b,n);
			}
			cout << "Thoi gian INSERTION SORT: " << duration * 1000000 << " microseconds\n";
			break;
		case 5: //bubble sort
			copyArray(a,b,n);
			start = clock();
			bubbleSort(b,n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau sap xep BUBBLE SORT\n";
				output(b,n);
			}
			cout << "Thoi gian BUBBLE SORT: " << duration * 1000000 << " microseconds\n";
			break;
		case 6: //interchange sort
			copyArray(a,b,n);
			start = clock();
			interchangeSort(b,n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau sap xep INTERCHANGE SORT\n";
				output(b,n);
			}
			cout << "Thoi gian INTERCHANGE SORT: " << duration * 1000000 << " microseconds\n";
			break;
		case 7: //quick sort
			copyArray(a,b,n);
			start = clock();
			quickSort(b,0,n-1);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau sap xep QUICK SORT\n";
				output(b,n);
			}
			cout << "Thoi gian QUICK SORT: " << duration * 1000000 << " microseconds\n";
			break;
		case 8: // Heap Sort
			copyArray(a,b,n);
			start = clock();
			heapSort(b,n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau sap xep HEAP SORT\n";
				output(b,n);
			}
			cout << "Thoi gian HEAP SORT: " << duration * 1000000 << " microseconds\n";
			break;
			case 9:
			cout<<"nhap so can tim: ";
			cin>>x;
			if(search(a,n,x)!=-1)
			{
				cout<<"tim thay phan tu tai vi tri: "<<search(a,n,x)<<endl;
			}
			else
				cout<<"khong tim thay"<<endl;
			break;
		case 10:
			cout<<"nhap so can tim: ";
			cin>>x;
			if(binarysearch(a,n,x)!=-1)
			{
				cout<<"tim thay phan tu tai vi tri: "<<binarysearch(a,n,x)<<endl;
			}
			else
				cout<<"khong tim thay"<<endl;
			break;
		case 12: // CLEAR Screen
			system("cls");
			break;
		}
	} while (choice != 11);
	return 0;
}