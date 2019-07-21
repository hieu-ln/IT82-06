//Chuong 2 - Bai 5
#include <iostream>
#include <stdio.h>
using namespace std;
//Cau 5.1
#define MAX 100
int a[MAX];
int sp;
//Cau 5.2
void init(int a[], int &sp)
{
	sp = -1;
}
//Cau 5.3
int isEmpty(int a[], int sp)
{
	if(sp==-1)
		return 1;
	return 0;
}
//Cau 5.4
int isFull(int a[], int sp)
{
	if(sp==MAX-1)
		return 1;
	return 0;
}
//Cau 5.5
int Push(int a[], int &sp, int x)
{
	if(sp < MAX - 1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}
//Cau 5.6
int Pop(int a[], int &sp, int &x)
{
	if(sp!=-1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}
//XUAT
void Process_stack(int a[], int sp)
{
	for(int i=0; i<sp+1; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}
int main()
{
	int a[MAX];
	int choice = 0, sp, x, i;
	system("cls");
	cout << "---------- BAI TAP 5 - CHUONG 2 - NGAN XEP - DANH SACH DAC ----------\n";
	cout << "1. Khoi tao STACK rong\n";
	cout << "2. Them phan tu vao STACK\n";
	cout << "3. Lay phan tu ra khoi STACK\n";
	cout << "4. Kiem tra STACK co day hay khong\n";
	cout << "5. Kiem tra STACK co rong hay khong\n";
	cout << "6. Xuat STACK\n";
	cout << "7. Thoat\n";
	do
	{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			init(a, sp);
			cout << "Da khoi tao thanh cong STACK rong!\n";
			break;
		case 2:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			i = Push(a, sp, x);
			cout << "STACK sau khi them la: ";
			Process_stack(a, sp);
			break;
		case 3:
			i = Pop(a, sp, x);
			cout << "Phan tu lay ra tu STACK la x = " << x << endl;
			cout << "STACK sau khi lay ra la: ";
			Process_stack(a, sp);
			break;
		case 4:
			i = isFull(a, sp);
			if(i==0)
				cout << "STACK chua day!\n";
			else
				cout << "STACK da day!\n";
			break;
		case 5:
			i = isEmpty(a, sp);
			if(i==0)
				cout << "STACK khong rong!\n";
			else
				cout << "STACK rong!\n";
			break;
		case 6:
			cout << "STACK hien tai la: ";
			Process_stack(a, sp);
			break;
		case 7:
			cout << "Good bye!\n";
			break;
		default:
			break;
		}
	}while(choice!=7);
	system("pause");
	return 0;
}