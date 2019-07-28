#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;
#define MAX 5000

int a[MAX]; int n;
void init(int a[], int& n)
{
	cout << "nhap vao so luong phan tu cua danh sach: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10000 + 1;
	}
	cout << "danh sach cac so nhap ngau nhien nhu sau:\n";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void input(int a[], int& n)
{
	cout << "nhap so luong phan tu cua danh sach: ";
	cin >> n;
	cout << "nhap vao cac phan tu cua danh sach:\n";
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
}
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void copyarray(int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}
void insertionsort(int a[], int n)
{
	int i, key, j;
	for (i = 0; i < n; i++)
	{
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + i] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}
void selectionsort(int a[], int n)
{
	int min_pos, i, j;
	for (i = 0; i < n - 1; i++)
	{
		min_pos = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min_pos])
				min_pos = j;
		swap(a[min_pos], a[i]);
	}
}
void swap(int& a, int& b)
{
	int c;
	c = a;
	a = b;
	b = c;
}
void bubblesort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])
				swap(a[j], a[j - 1]);
}
void interchangsort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				swap(a[j], a[i]);
}
void quicksort(int a[], int left, int right)
{
	int x = a[(left + right) / 2];
	int i = left;
	int j = right;
	while (i < j)
	{
		while (a[i] < x)i++;
		while (a[j] < x)j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++; j--;
		}

	}
	if (left < j)quicksort(a, left, j);
	if (right > i)quicksort(a, i, right);
}
void shift(int a[], int i, int n)
{
	int j = 2 * i + 1;
	if (j >= n)
		return;
	if (j + 1 < n)
		if (a[i] < a[j + 1])
			j++;
	if (a[i] >= a[j])
		return;
	else {
		swap(a[i], a[j]);
		shift(a, j, n);
	}

}
void heapsort(int a[], int n)
{
	int i = n / 2 - 1;
	while (i >= 0)
	{
		shift(a, i, n - 1); i--;
	}
	int right = n - 1;
	while (right > 0)
	{
		swap(a[0], a[right]);
		right--;
		if (right > 0)
			shift(a, 0, right);
	}
}
int search(int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
		i++;
	if (i < n)
		return i;
	return -1;
}
int binarysearch(int a[], int n, int x)
{
	int left = 0, right = n - 1, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == x)
			return mid;
		if (x > a[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}
int main()
{
	int b[MAX];
	int left, right;
	clock_t start;
	double duration;
	int choise, x;

	system("cls");
	cout << "0.khoi tao danh sach ngau nhien \n";
	cout << "1.nhap danh sach\n";
	cout << "2.xuat danh sach\n";
	cout << "3.sep thu tu danh sach bang selectionsort\n";
	cout << "4.sep thu tu danh sach bang insertionsort\n";
	cout << "5.sep thu tu danh sach bang bubblesort\n";
	cout << "6.sep thu tu danh sach bang interchangsort\n";
	cout << "7.sep thu tu danh sach bang quicksort\n";
	cout << "8.sep thu tu danh sach bang heapsort\n";
	cout << "9.tim kirm phan tu x bang tim tuan tu\n";
	cout << "10.tim kirm phan tu x bang tim nhi phan\n";
	do {
		cout << "vui long chon buoc de thuc hien: ";
		cin >> choise;
		switch (choise)
		{
		case 0:
			init(a, n);
			break;
		case 1:
			input(a, n);
			break;
		case 2:
			output(a, n);
			break;
		case 3:
			copyarray(a, b, n);
			start = clock();
			selectionsort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "ds sau khi sap sep voi insertionsort: ";
				output(b, n);
			}
			if (duration > 0)
			{
				cout << "thoi gian insertionsort :" << duration * 1000000 << " Micriosecond" << endl;
			}
			break;
		case 4:
			copyarray(a, b, n);
			start = clock();
			bubblesort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "ds sau khi sap sep voi bubblesort: ";
				output(b, n);
			}
			if (duration > 0)
			{
				cout << "thoi gian bubblesort :" << duration * 1000000 << " Micriosecond" << endl;
			}
			break;
		case 5:
			copyarray(a, b, n);
			start = clock();
			bubblesort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "ds sau khi sap sep voi bubblesort: ";
				output(b, n);
			}
			if (duration > 0)
			{
				cout << "thoi gian bubblesort :" << duration * 1000000 << " Micriosecond" << endl;
			}
			break;
		case 6:
			copyarray(a, b, n);
			start = clock();
			interchangsort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "ds sau khi sap sep voi interchangsort: ";
				output(b, n);
			}
			if (duration > 0)
			{
				cout << "thoi gian interchangsort :" << duration * 1000000 << " Micriosecond" << endl;
			}
			break;
		case 7:
			left = 0; right = n - 1;
			copyarray(a, b, n);
			start = clock();
			quicksort(b, left, right);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "ds sau khi sap sep voi quicksort: ";
				output(b, n);
			}
			if (duration > 0)
			{
				cout << "thoi gian quicksort :" << duration * 1000000 << " Micriosecond" << endl;
			}
			break;
		case 8:
			copyarray(a, b, n);
			start = clock();
			heapsort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "ds sau khi sap sep voi heapsort: ";
				output(b, n);
			}
			if (duration > 0)
			{
				cout << "thoi gian heapsort :" << duration * 1000000 << " Micriosecond" << endl;
			}
			break;
		case 9:
			cout << "nhap so can tim: ";
			cin >> x;
			if (search(a, n, x) != -1)
			{
				cout << "tim thay phan tu tai vi tri: " << search(a, n, x) << endl;
			}
			else
				cout << "khong tim thay" << endl;
			break;
		case 10:
			cout << "nhap so can tim: ";
			cin >> x;
			if (binarysearch(a, n, x) != -1)
			{
				cout << "tim thay phan tu tai vi tri: " << binarysearch(a, n, x) << endl;
			}
			else
				cout << "khong tim thay" << endl;
			break;
		case 11:
			cout << "tam biet" << endl;
			break;
		default:

			break;
		}
	} while (choise != 11);
	system("pause");
	return 0;
}