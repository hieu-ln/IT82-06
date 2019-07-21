//Chuong 2 Bai 11
#include <iostream>
using namespace std;

//11.1: khia bao cau truc QUEUE
struct Node
{
	int info;
	Node *link;
};
Node *front, *rear;

//11.2: Khoi tao QUEUE rong
void init()
{
	front = NULL;
	rear = NULL;
}

//Ktra QUEUE rong
int isEmpty()
{
	if (front == NULL)
		return 1;
	return 0;
}
 //11.4: Them phan tu vao QUEUE
void Push(int x)
{
	Node *p = new  Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}

//11.5: Lay phan tu ra khoi QUEUE
int Pop(int &x)
{
	if (front != NULL)
	{
		Node *p = front;
		front = p->link;
		x = p->info;
		if (front == NULL)
		{
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}

//Xuat QUEUE
void Process_queue()
{
	if (front != NULL)
	{
		Node *p = front;
		cout << "<-- ";
		do
		{
			cout << p->info << " ";
			p = p->link;
		} while (p != NULL);
		cout << "<-- " << endl;
	}
}

int main()
{
	int choice, x, i;
	cout << " ----- CHUONG 2 BAI 11 -----\n" << endl;
	cout << " 1. Khi tao QUEUE rong" << endl;
	cout << " 2. Them phan tu vao QUEUE" << endl;
	cout << " 3. Lay phan tu ra khoi QUEUE" << endl;
	cout << " 4. Kiem tra QUEUE co rong hay khong" << endl;
	cout << " 5. Xuat QUEUE" << endl;
	cout << " -. Phim bat ky de thoat" << endl;
	do
	{
		cout << "\n Vui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << " Ban vua khoi tao QUEUE rong thanh cong!\n";
			break;
		case 2:
			cout << " Vui long nhap gia tri x can them= ";
			cin >> x;
			Push(x);
		case 3:
			Pop(x);
			cout << " Phan tu lay ra tu QUEUE la x= " << x << endl;
			cout << " QUEUE sau khi lay ra la: ";
			Process_queue();
			break;
		case 4:
			i = isEmpty();
			if (i == 0)
				cout << " QUEUE khong rong!" << x << endl;
			else
				cout << " QUEUE rong!" << endl;
			break;
		case 5:
			cout << " QUEUE hien tai la: ";
			Process_queue();
			break;
		default:
			cout << " Goodbye......!" << endl;
			choice = 6;
			break;
		}
	} while (choice != 6);
	return 0;
}