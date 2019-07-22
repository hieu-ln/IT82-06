//#include <stdio.h>
//#include <iostream>
//using namespace std;
// cau 3.1
//struct Node
//{
//	int info;
//	Node *link;
//
//};
//Node *first;
//
//cau 3.2
//void init ()
//{
//	first = NULL;
//}
//
//cau 3.3
//void Process_list ()
//{
//	Node *p;
//	p=first;
//	while (p !=NULL)
//	{
//		cout <<p->info<<"\t";
//		p=p->link;
//	}
//	cout<<endl;
//}
//
//cau 3.4
//Node *Search (int x)
//{
//	Node *p=first;
//	while (p!=NULL && p->info !=x)
//		p= p->link;
//	return p;
//}
//
//cau 3.5
//void Insert_first (int x)
//{
//	Node *p;
//	p= new Node;
//	p->info = x;
//	p->link = first;
//	first = p;
//}
//
//cau 3.6
//int Delete_first()
//{
//	if (first!=NULL)
//	{
//		Node *p = first;
//		first = first->link;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//cau 3.7
//void Insert_last (int x)
//{
//	Node *p;
//	p= new Node;
//	p->info = x;
//	p->link = NULL;
//	if(first == NULL)
//		first =p;
//	else
//	{
//		Node *q=first;
//		while (q->link !=NULL)
//			q=q->link;
//		q->link=p;
//	}
//}
//
//	cau 3.8
//int Delete_last()
//{
//	if (first !=NULL)
//	{
//		Node *p, *q;
//		p=first;
//		q= NULL;
//		if (p!=NULL)
//			while (p->link !=NULL)
//			{
//				q=p;
//				p=p->link;
//			}
//		if (p!=first)
//			q->link =NULL;
//		else first=NULL;
//		delete p;
//		return 1;
//	} 
//	return 0;
//}
//
//cau 3.9
//int SearchAndDelete (int x)
//{
//	if (first != NULL)
//	{
//		Node *p, *q;
//		p=first;
//		q=first;
//		while (p->info !=x && p->link != NULL)
//		{
//			q=p;
//			p=p->link;
//		}
//		if (p !=first && p!=NULL)
//		{
//			if (p->link !=NULL)
//				q->link = p->link;
//			else
//				q->link=NULL;
//			delete p;
//			return 1;
//		}
//		else 
//			if (p==first)
//			{
//				first =p->link;
//				delete p;
//				return 1;
//			}
//			else
//				return 0;
//
//	}
//	return 0;
//}
//
//void swap (Node *a, Node *b)
//{
//	int t = a->info;
//	a->info = b->info;
//	b->info = t;
//}
//
//cau 3.10
//void Sort()
//{
//	Node *p, *q, *min;
//	p = first;
//	while (p != NULL)
//	{
//		min = p;
//		q = p->link;
//		while (q != NULL)
//		{
//			if (q->info < min->info)
//				min = q;
//			q = q->link;
//		}
//		swap (min, p);
//		p = p->link;
//	}
//}
//void SortDesc()
//{
//	Node *p, *q, *min;
//	p=first;
//	while (p!=NULL)
//	{
//		min = p;
//		q=p->link;
//		while (q!=NULL)
//		{
//			if (q->info > min->info)
//				min = q;
//			q=q->link;
//		}
//	}
//	swap (min, p);
//	p=p->link;
//}
//
//int main()
//{int choice =0;
//int x,i;
//Node *p;
//system ("cls");
//cout<<"--------- CHUONG2_B3 ---------"<<endl;
//cout<<"1. Khoi tao danh sach rong"<<endl;
//cout<<"2. Them phan tu vao dau danh sach"<<endl;
//cout<<"3. Them phan tu vao cuoi danh sach"<<endl;
//cout<<"4. Xoa phan tu vao dau danh sach"<<endl;
//cout<<"5. xoa phan tu vao cuoi danh sach"<<endl;
//cout<<"6. Xuat "<<endl;
//cout<<"7. Tim phan tu gia tri x trong danh sach"<<endl;
//cout<<"8.Tim phan tu gia tri x va xoa neu co"<<endl;
//cout<<"9. Sap xep tang dan"<<endl;
//cout<<"10. Sap xep giam dan"<<endl;
//cout<<"11. Thoat"<<endl;
//do
//{
//	cout <<"\nChon so de thuc hien: ";
//	cin>>choice;
//	switch (choice)
//	{
//		case 1:
//			init();
//			cout<<"Khoi tao thanh cong!\n";
//			break;
//		case 2:
//			cout <<"Nhap gia tri x=";
//			cin>>x;
//			Insert_first (x);
//			cout <<"Danh sach moi: ";
//			Process_list();
//			break;
//		case 3:
//
//			cout<<"Nhap gia tri x= ";
//			cin>>x;
//			Insert_last (x);
//			cout <<"Danh sach moi: ";
//			Process_list();
//			break;
//		
//		case 4:
//			i=Delete_first();
//			if (i==0)
//				cout<<"Danh sach rong, khong the xoa!"<<endl;
//			else
//			{
//				cout<<"Da xoa phan tu dau cua danh sach!"<<endl;
//				cout<<"Danh sach moi: ";
//				Process_list();
//			}
//			break;
//		case 5:
//			i= Delete_last();
//			if(i==0)
//				cout<<"danh sach rong, khong the xoa!"<<x<<endl;
//			else{
//				cout<< "Da xoa phan tu cuoi cua danh sach !"<<endl;
//				cout <<"Danh sach moi: ";
//				Process_list();
//			}
//			break;
//		case 6:
//			cout<<"Danh sach hien tai: ";
//			Process_list();
//			break;
//		case 7:
//			cout<<"Nhap gia tri can tim x=";
//			cin>>x;
//			p=Search(x);
//			if(p!=NULL)
//				cout<<"Tim thay phan tu co gia tri x="<<x<<endl;
//			else
//				cout<<"Khong tim thay phan tu co gia tri x="<<x<<endl;
//			break;
//		case 8:
//			cout<<"Nhap gia tri can tim x=";
//			cin>>x;
//			i=SearchAndDelete(x);
//			if (i==0)
//			{
//				cout<<"Khong tim thay phan tu co gia tri x="<<x<<endl;
//			}
//			else
//				cout<<"Tim thay x= "<<x<<" va da xoa"<<endl;
//				cout<<"danh sach moi: ";
//				Process_list();
//				
//			break;
//		case 9:
//			Sort();
//			cout <<"Danh sach sau khi sap xep tang dan: ";
//			Process_list();
//			break;
//		case 10:
//			SortDesc();
//			cout <<"Danh sach sau khi sap xep giam dan: ";
//			Process_list();
//			break;
//		case 11:
//			cout <<"END."<<endl;
//			break;
//		default:
//			break;
//		}
//	}while(choice !=11);
//	system ("pause");
//	return 0;
//	}