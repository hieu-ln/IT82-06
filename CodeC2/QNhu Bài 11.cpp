//#include <iostream>
//#include <stdio.h>
//using namespace std;
//
//
////Câu 11.1:
//struct Node
//{
//	int info;
//	Node *link;
//};
//Node *front, *rear;
//
////Câu 11.2:
//void Init()
//{
//	front = NULL;
//	rear = NULL;
//}
//
////Câu 11.3:
//int IsEmpty ()
//{
//	if (front == NULL)
//		return 1;
//	return 0;
//}
//
////Câu 11.4:
//void Push (int x)
//{
//	Node *p = new Node;
//	p->info = x;
//	p->link = NULL;
//	if (rear == NULL)
//		front = p;
//	else 
//		rear->link = p;
//
//}
//
////Câu 11.5:
//int Pop (int &x)
//{
//	if (front != NULL)
//	{
//		Node *p = front;
//		front = p->link;
//		x = p->info;
//		if (front == NULL)
//			rear = NULL;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//
////Xuất QUEUE
//void Process_Queue()
//{
//	if (front != NULL)
//	{
//		Node *p = front;
//		cout<<"<--\t";
//		do
//		{
//			cout<<p->info<<"\t";
//			p=p->link;
//		}while (p != NULL);
//		cout<<"<--"<<endl;
//	}
//}
//
//int main()
//{
//	int choice, x, i;
//	system("cls");
//	cout<<"----------CHUONG2_B11----------"<<endl;
//	cout<<"1. Khoi tao QUEUE rong"<<endl;
//	cout<<"2. Them phan tu vao QUEUE"<<endl;
//	cout<<"3. Lay phan tu ra khoi QUEUE"<<endl;
//	cout<<"4. Kiem tra QUEUE co rong hay khong"<<endl;
//	cout<<"5. Xuat QUEUE"<<endl;
//	cout<<"6. Thoat"<<endl;
//	do
//	{
//		cout<<"Chon so de thuc hien: ";
//		cin>>choice;
//		switch (choice)
//		{
//			case 1:
//				Init ();
//				cout<<"Khoi tao QUEUE rong thanh cong!"<<endl;
//				break;
//			case 2:
//				cout<<"Vui long nhap gia tri x=";
//				cin>>x;
//				Push (x);
//				cout<<"QUEUE moi:"<<endl;
//				Process_Queue ();
//				break;
//			case 3:
//				Pop(x);
//				cout<<"Phan tu lay ra tu QUEUE la x="<<x;
//				cout<<"QUEUE moi: "<<endl;
//				Process_Queue();
//				break;
//			case 4:
//				i = IsEmpty();
//				if (i == 0)
//					cout<<"QUEUE khong rong!"<<endl;
//				else cout<<"QUEUE rong!"<<endl;
//				break;
//			case 5:
//				cout<<"QUEUE hien tai la:"<<endl;
//				Process_Queue ();
//				break;
//			case 6:
//				cout<<"END."<<endl;
//				break;
//			default:
//				break;
//
//		}
//
//	}while (choice != 6);
//	system ("pause");
//	return 0;
//}