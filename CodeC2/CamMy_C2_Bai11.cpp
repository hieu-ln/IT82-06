//Bai 11 - Chuong 2 - QUEUE - DSLK DON
#include <iostream>
#include <stdio.h>
using namespace std;
//Cau 11.1
struct Node
{
	int info;
	Node *link;
};
Node *front, *rear;
//Cau 11.2
void init()
{
	front = NULL;
	rear = NULL;
}
//Cau 11.3
int isEmpty()
{
	if(front == NULL)
		return 1;
	return 0;
}
//Cau 11.4
void Push(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if(rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}
//Cau 11.4
int Pop(int &x)
{
	if(front != NULL)
	{
		Node *p = front;
		front = p->link;
		x = p->info;
		if(front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}
//XUAT
void Process_queue()
{
	if(front != NULL)
	{
		Node *p = front;
		cout << "<--\t";
		do{
			cout << p->info << "\t";
			p = p->link;
		}while(p!=NULL);
		cout << "<--\n";
	}
}
int main()
{
	int choice, x, i;
	system("cls");
	cout << "----------BAI 11 - CHUONG 2 - QUEUE - DSLK DON----------\n";
	cout << "1. Khoi tao QUEUE rong\n";
	cout << "2. Them phan tu vao QUEUE\n";
	cout << "3. Lay phan tu ra khoi QUEUE\n";
	cout << "4. Kiem tra QUEUE co rong hay khong\n";
	cout << "5. Xuat QUEUE\n";
	cout << "6. Thoat\n";
	do{
		cout << "\nVui long nhap so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			init();
			cout << "Da khoi tao thanh cong QUEUE!\n";
			break;
		case 2:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			Push(x);
			cout << "QUEUE sau khi them la: ";
			Process_queue();
			break;
		case 3:
			Pop(x);
			cout << "Phan tu lay ra tu QUEUE la x = " << x << endl;
			cout << "QUEUE sau khi lay ra la: ";
			Process_queue();
			break;
		case 4:
			i = isEmpty();
			if(i==0)
				cout << "QUEUE khong rong!\n";
			else
				cout << "QUEUE rong!\n";
			break;
		case 5: 
			cout << "QUEUE hien tai la: ";
			Process_queue();
			break;
		case 6: 
			cout << "Good bye!\n";
			break;
		default:
			break;
		}
	}while(choice!=6);
	system("pause");
	return 0;
}