//Chuong 2 Bai 10
#include <iostream>
using namespace std;
//10.1
struct Node
{
	int info;
	Node *link;
};
Node *sp;
//10.2
void init()
{
	sp = NULL;
}
//10.3
int isEmpty()
{
	if(sp==NULL)
		return 1;
	return 0;
}
//10.4
void Push(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}
//10.5
int Pop(int &x)
{
	if(sp!=NULL)
	{
		Node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
	}
	return 0;
}
//XUAT
void Process_stack()
{
	Node *p = sp;
	do{
		cout << p->info << "\t";
		p = p->link;
	}while(p!=NULL);
	cout << endl;
}
int main()
{
	int choice, x, i;
	cout << "----- CHUONG 2 BAI 10 -----\n";
	cout << "1. Khoi tao STACK rong\n";
	cout << "2. Kiem tra STACK rong\n";
	cout << "3. Them phan tu vao STACK\n";
	cout << "4. Lay phan tu ra khoi STACK\n";
	cout << "5. Xuat STACK\n";
	cout << "6. Thoat\n";
	do {
		cout << "Vui long nhap so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			init();
			cout << "Da khoi tao thanh cong STACK rong!\n";
			break;
		case 2:
			int kt;
			kt = isEmpty();
			if(kt==1)
				cout << "STACK rong!\n";
			else
				cout << "STACK khong rong!\n";
			break;
		case 3:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			Push(x);
			cout << "STACK sau khi them la: ";
			Process_stack();
			break;
		case 4:
			Pop(x);
			cout << "Phan tu lay ra tu STACK la x = " << x << endl;
			cout << "STACK sau khi lay ra la: ";
			Process_stack();
			break;
		case 5: 
			cout << "STACK hien tai la: ";
			Process_stack();
			break;
		default:
			cout << "Goodbye!!!!\n";
			choice = 6;
			break;
		}
	} while (choice!=6);
	return 0;
}