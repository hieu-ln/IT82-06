//#include<stdio.h>
//#include <iostream>
//using namespace std;
//struct node
//{
//	int info;
//	node *link;
//};
//node *first;
//void init()
//{
//	first=NULL;
//}
//void process_list()
//{
//	node*p;
//	p=first;
//	while (p!=NULL)
//	{
//		cout <<p->info<<"\t";
//	}
//	cout<<endl;
//}
//node search(int x)
//{
//	node *p;
//	p=new node;
//	p->info=x;
//	p->link=first;
//	first=p;
//}
//int delete_first()
//{
//	if (first !=NULL)
//	{
//		node *p=first;
//		first =first->link;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//void insert_last(int x)
//{
//	node *p;
//	p= new node;
//	p->info=x;
//	p->link=NULL;
//		if(first==NULL)
//		{
//			first=p;
//		}
//		else
//		{
//			node*q=first;
//			while(q->link!=NULL)
//			{
//				q=q->link;
//			}
//			q->link=p;
//		}
//}
//int delete_last()
//{
//	if (first==NULL)
//	{
//		node *p,*q;
//		q=first;
//		p=first;
//		while (p->link!=NULL)
//		{
//			q=p;
//			p=p->link;
//		}
//		if (p!=first)
//		{
//			q->link=NULL;
//		}
//		else first=NULL;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//int seachanddelete(int x)
//{
//	if (first !=NULL)
//	{
//		node *p,*q;
//		q=first;
//		p=first;
//		while (p->info!=x&&p->link!=NULL)
//		{
//			q=p;
//			p=p->link;
//		}
//	if (p!=first&&p->link=NULL)
//	{
//		if (p->link!=NULL)
//			q->link=p->link;
//		else
//			q->link=NULL;
//		delete p;
//		return 1;
//	}
//	else if(p->link==NULL&&p->info==x)
//	{
//		q->link=NULL;
//		delete p;
//		return 1;
//	}
//		else
//		return 0;
//}
//	return 0;
//}
//void swap(node *a,node *b)
//{
//	int t=a->info;
//	a->info=b->info;
//	b->info=t;
//}
//void sort()
//{
//	node *p,*q,*min;
//	p=first;
//	while (p!=NULL)
//	{
//		min=p;
//		q=p->link;
//		while(q!=NULL)
//		{
//			if (q->info<min->info)
//				min=q;
//			q=q->link;
//		}
//		swap(min,q);
//		p=p->link;
//	}
//}
//int main()
//{
//	int choice=0;
//	system("cls");
//	cout<<"1.khai bao cau truc danh sach"<<endl;
//	cout<<"2.khoi tao danh sach rong"<<endl;
//	cout<<"3.xuat danh sach cac ohan tu"<<endl;
//	cout<<"4.tim 1 phan tu trong danh sach"<<endl;
//	cout<<"5.them 1 phan tu vao dau danh sach"<<endl;
//	cout<<"6.xoa 1 phan tu dau danh sach"<<endl;
//	cout<<"7.them 1 phan tu vao cuoi danh sach"<<endl;
//	cout<<"8.xoa 1 phan tu cuoi danh sach"<<endl;
//	cout<<"9.tim 1 phan tu trong danh sach neu tim thay xoa no"<<endl;
//	cout<<"10.xap sep tu be den lon"<<endl;
//	do{
//		cout<<"vui long chon so de thuc hien: "<<endl;
//		cin>>choice;
//		switch(choice)
//		{
//		case 1:
//			init;
//			cout<<"ban vua khoi tao danh sach thanh cong"<<endl;
//			break;
//		case 2:
//			process_list();
//			cout<<endl;
//			break;
//		case 3:
//			cout<<"nhap phan tu can tim";
//			int x;
//			cin>> x;
//			search(x);
//			process_list();
//			break;
//		case 4:
//			cout<<"nhap pha tu vao cuoi danh sach";
//			cin>>x;
//			insert_last(x);
//			process_list();
//			break;
//		case 5:
//			delete_first;
//			process_list();
//			break;
//		case 6:
//			delete_last;
//			process_list();
//			break;
//		case 7:
//			cin>>x;
//			seachanddelete(x);
//			process_list();
//			break;
//		case 8:
//			cout<<"goood bye..."<<endl;
//			break;
//		default:
//			cout<<"nhap lai"<<endl;
//			break;
//		}
//	}while(choice !=8);
//		system("pause");
//		return 0;
//}
//
//		
