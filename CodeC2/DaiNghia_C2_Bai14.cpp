//Chuong 2 Bai 14
#include <iostream>
using namespace std;

struct DaThuc
{
	int info;
	DaThuc *next, *prev;
};
DaThuc *first, *last;
DaThuc *first1, *last1;
DaThuc *first2, *last2;
void init ()
{
	first = NULL;
	last = NULL;
	first1 = NULL;
	first2 = NULL;
	last1 = NULL;
	last2 = NULL;
}
void Insert1 (int x)
{
	DaThuc *a;
	a = new DaThuc;
	a->info = x;
	a->next = NULL;
	a->prev = last1;
	if (last1 != NULL)
		last1->next = a;
	else
		first1 = a;
	last1 = a;
}
void Insert2 (int x)
{
	DaThuc *a;
	a = new DaThuc;
	a->info = x;
	a->next = NULL;
	a->prev = last2;
	if (last2 != NULL)
		last2->next = a;
	else
		first2 = a;
	last2 = a;
}
void Insert3 (int x)
{
	DaThuc *a;
	a = new DaThuc;
	a->info = x;
	a->next = first;
	a->prev = NULL;
	if (first != NULL)
		first->prev = a;
	else
		last = a;
	first = a;
}
void Input1(int &bac1)
{
	cout << "Hay nhap bac cua da thuc: ";
	do {
		cin >> bac1;
		if (bac1 < 0)
			cout << "Nhap sai. Nhap lai: ";
	} while (bac1 < 0);
	int x, j = 0;
	for (int i = bac1; i >= 0; i--)
	{
		cout << "Hay nhap he so cua " << char(97+j++);
		if (i != 0)
			cout << "x";
		if (i > 1)
			cout << "^" << i;
		cout << "= ";
		cin >> x;
		Insert1(x);
	}
}
void Input2(int &bac2)
{
	cout << "Hay nhap bac cua da thuc: ";
	do {
		cin >> bac2;
		if (bac2 < 0)
			cout << "Nhap sai. Nhap lai: ";
	} while (bac2 < 0);
	int x, j = 0;
	for (int i = bac2; i >= 0; i--)
	{
		cout << "Hay nhap he so cua " << char(97+j++);
		if (i != 0)
			cout << "x";
		if (i > 1)
			cout << "^" << i;
		cout << "= ";
		cin >> x;
		Insert2(x);
	}
}
void To_Last1(int bac1)
{
	int vitri = 1;
	DaThuc *p = first1;
	while (p != NULL)
	{
		for (int i = bac1; i >= 0; i--)
		{
			if (p->info != 0)
			{
				if (vitri == 1)
					cout << p->info;
				else if (p->info < 0)
					cout << " - " << -p->info;
				else
					cout << " + " << p->info;
				if (i != 0)
					cout << "x";
				if (i > 1)
					cout << "^" << i;
				vitri++;
			}
			p = p->next;
		}
	}
	cout << endl;
}
void To_Last2(int bac2)
{
	int vitri = 1;
	DaThuc *p = first2;
	while (p != NULL)
	{
		for (int i = bac2; i >= 0; i--)
		{
			if (p->info != 0)
			{
				if (vitri == 1)
					cout << p->info;
				else if (p->info < 0)
					cout << " - " << -p->info;
				else
					cout << " + " << p->info;
				if (i != 0)
					cout << "x";
				if (i > 1)
					cout << "^" << i;
				vitri++;
			}
			p = p->next;
		}
	}
	cout << endl;
}
int main()
{
	DaThuc *p, *q;
	int choice, bac1, bac2;
	cout << "----- Chuong 2 Bai 14 -----\n";
	cout << "1) Khoi tao (Hoac xoa du lieu) 2 Da Thuc\n";
	cout << "2) Nhap Da Thuc 1\n";
	cout << "3) Xuat Da Thuc 1\n";
	cout << "4) Nhap Da Thuc 2\n";
	cout << "5) Xuat Da Thuc 2\n";
	cout << "-) Phim bat ky de thoat\n";
	do {
		cout << "Lua chon cua ban: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			init();
			cout << "Khoi tao thanh cong!!!\n";
			break;
		case 2:
			Input1(bac1);
			break;
		case 4:
			Input2(bac2);
			break;
		case 3:
			To_Last1(bac1);
			break;
		case 5:
			To_Last2(bac2);
			break;
		default:
			cout << "Goodbye!!!\n";
			choice = 99;
			break;
		}
	} while (choice != 99);
	return 0;
}