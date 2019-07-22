#include<iostream>
#include<stdio.h>
using namespace std;

//khai bao cau truc
struct Node
{
	int info;
	Node *next;
	Node *previous;
}
typedef struct list LIST;
Node *first, *last;
//khoi tao
void init()
{
	first = NULL;
	last = NULL;
}
//xuat
void output()
{
	Node *p = first;
	while(p != NULL)
	{
		cout << p -> info << "\t";
		p = p -> next;
	}
}
//Them dau
void Insert_first(int x)
{
	Node *p;
	p = new Node;
	p -> info = x;
	p -> next = first;
	p -> previous = NULL;
	if(first != NULL)
		first -> previous = p;
	else
		last = p;
	first = p;
}
// Them cuoi
void Insert_last(int x)
{
	Node *p;
	p = new Node;
	p -> info = x;
	p ->next = NULL;
	p ->previous = last;
	if(last != NULL)
		last ->next = p;
	else
		first = p;
	last = p;
}
//Xoa dau
int Delete_first()
{
	if(first != NULL)
	{
		Node *p = first;
		first = first -> next;
		delete p;
		if(first != NULL)
			first -> previous = NULL;
		else
			last = NULL;
		return 1;
	}
	return 0;
}
// Xoa cuoi
int Delete_last()
{
	if(last != NULL)
	{
		Node *p = last;
		last = last ->previous;
		if( last != NULL)
			last -> next = NULL;
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}

// Tim va xoa
Node *search(int x)
{
	Node *p = first;
	while (p != NULL && p->info != x)
		p = p->next;
	return p;
}
int searchAnddelete(int x)
{
	int check = 0;
	Node *p = search(x);
	if (p != NULL)
	{
		if (p == first)
			check = Delete_first();
		else if (p == last)
			check = Delete_last();
		else
		{
			Node *ptr = p;
			p = p->previous;
			p->next = ptr->next;
			delete ptr;
			return -1;
		}
	}
	return 0;
}
int menu()
 {
	 cout << "\n\n============= MENU ============="
		 << "\n0. Thoat"
		 << "\n1. Khoi tao"
		 << "\n2. Them mot phan tu vao dau danh sach"
		 << "\n3. Them mot phan tu vao cuoi danh sach"
		 << "\n4. Xoa phan tu dau"
		 << "\n5. Xoa phan tu cuoi"
		 << "\n6. Tim va xoa phan tu trong danh sach"
		 << "\n7. Xuat"
		 << "\n===============================";
	 int choose;
	 cout << "\nChon: ";
	 cin >> choose;
	 return choose;
 }
 int main()
 {
	 int choose;
	 int x;
	 do {
		 choose = menu();
		 switch (choose)
		 {
		 case 0:
			 cout << "Thoat chuong trinh\n";
			 return 0;
			 break;
		 case 1:
			 init();
			 cout << "Khoi tao thanh cong";
			 break;
		 case 2:
			 cout << "\n2. Them mot phan tu vao dau danh sach : ";
			 cin >> x;
			 Insert_first(x);
			 break;
		 case 3:
			 cout << "\n3. Them mot phan tu vao cuoi danh sach: ";
			 cin >> x;
			 Insert_last(x);
			 break;
		 
		 case 4:
			 if (Delete_first() == 1)
				 cout << "Da xoa gia tri dau\n";
			 else
				 cout << "Xoa that bai\n";
			 break;
		 case 5:
			 if (Delete_last() == 1)
				 cout << "Da xoa gia tri cuoi\n";
			 else
				 cout << "Xoa that bai";
			 break;
		 case 7:
			 cout << "Cac phan co trong danh sach : ";
			 output();
		 }
	 } while (choose != 0);
	 cout << endl;
	 system("pause");
	 return 0;
}