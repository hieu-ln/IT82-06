Chuong2 - Bai3
#include <iostream>
#include <stdio.h>
using namespace std;
Cau 3.1
struct Node
{
	int info;
	Node *link;
};
Cau 3.2
Node *first;
void init()
{
	first = NULL;
}
Cau 3.3
void Process_list()
{
	Node *p;
	p = first;
	while(p!=NULL)
	{
		cout << p->info << "\t";
		p = p->link;
	}
}
Cau 3.4
Node *Search(int x)
{
	Node *p = first;
	while((p!=NULL) && (p->info!=x))
		p = p->link;
	return p;
}
Cau 3.5
void Insert_first(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}
Cau 3.6
int Delete_first()
{
	if(first!=NULL)
	{
		Node *p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}
Cau 3.7
void Insert_last(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = NULL;
	if(first == NULL)
		first = p;
	else
	{
		Node *q = first;
		while(q->link!=NULL)
			q = q->link;
		q->link = p;
	}
}
Cau 3.8
int Delete_last()
{
	if(first!=NULL)
	{
		Node *p, *q;
		p = first; q = NULL;
		if(p!=NULL)
			while(p->link!=NULL)
			{
				q=p;
				p=p->link;
			}
		if(p!=first)
			q->link=NULL;
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}
Cau 3.9
int SearchAndDelete(int x)
{
	if(first != NULL)
	{
		Node *p, *q;
		p = first;
		q = first;
		while(p->info !=x)
		{
			q=p;
			p=p->link;
		}
		if(p!=first && p!=NULL)
		{
			if(p->link !=NULL)
				q->link = p->link;
			else
				q->link = NULL;
			delete p;
			return 1;
		}
		else if(p == first)
		{
			first = p->link;
			delete p;
			return 1;
		}
		else
			return 0;
	}
	return 0;
}
int main()
{
	int choice = 0;
	int x, i;
	Node* p;
	system("cls");
	cout << "------ BAI TAP 3 - CHUONG 2 - DANH SACH LIEN KET DON ------\n";
	cout << "1. Khoi tao DSLK DON rong\n";
	cout << "2. Them phan tu vao dau DSLK DON\n";
	cout << "3. Them phan tu vao cuoi DSLK DON\n";
	cout << "4. Xoa phan tu dau DSLK DON\n";
	cout << "5. Xoa phan tu cuoi DSLK DON\n";
	cout << "6. Xuat DSLK DON\n";
	cout << "7. Tim mot phan tu voi gia tri x trong DSLK DON\n";
	cout << "8. Tim phan tu voi gia tri x va xoa no neu co\n";
	cout << "9. Thoat\n";
	do
	{
		cout << "\n\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			init();
			cout << "Ban vua khoi tao DSLK DON thanh cong!\n";
			break;
		case 2:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			Insert_last(x);
			cout << "Danh sach sau khi them la: ";
			Process_list();
			break;
		case 3:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			Insert_last(x);
			cout << "Danh sach sai khi them la: ";
			Process_list();
			break;
		case 4:
			i = Delete_first();
			if(i==0)
				cout << "Danh sach rong, khong the xoa!\n";
			else
			{
				cout << "Da xoa thanh cong phan tu dau cua DSLK DON!\n";
				cout << "Danh sach sau khi xoa la: ";
				Process_list();
			}
			break;
		case 5:
			i = Delete_last();
			if(i==0)
				cout << "Danh sach rong, khong the xoa!\n";
			else
			{
				cout << "Da xoa thanh cong phan tu cuoi cua DSLK DON!\n";
				cout << "Danh sach sau khi xoa la: ";
				Process_list();
			}
			break;
		case 6:
			cout << "Danh sach hien tai la: ";
			Process_list();
			break;
		case 7:
			cout << "Vui long nhap gia tri can tim x = ";
			cin >> x;
			p = Search(x);
			if(p!=NULL)
			{
				cout << "Tim thay phan tu x = " << x << "!\n"; 
			}
			else
				cout << "Khong tim thay phan tu co gia tri x = " << x << "!\n";
			break;
		case 8:
			cout << "Vui long nhap gia tri can tim x = ";
			cin >> x;
			i = SearchAndDelete(x);
			if(i==1)
			{
				cout << "Tim thay x = " << x << " va da xoa thanh cong\n";
				cout << "Danh sach sau khi xoa la: ";
				Process_list();
			}
			else
				cout << "Khong tim thay phan tu co gia tri x = " << x << "!\n";
			break;
		case 9:
			cout << "\nGood bye!\n";
			break;
		default:
			break;
		}
	}while(choice!=9);
	system("pause");
	return 0;
}