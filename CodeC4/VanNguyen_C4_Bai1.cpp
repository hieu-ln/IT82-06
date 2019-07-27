#include <iostream>
#include <stdio.h>
using namespace std;
#define COUNT 10
struct node {
	int info;
	node *left;
	node *right;
};
node *root;
void init()
{
	root=NULL;
}
void insert_node_recursive(int x,node *&p)
{
	if  (p==NULL)
	{
		p= new node;
		p->info=x;
		p->left=NULL;
		p->right=NULL;
	}
	else
	{
		if(p->info==x)
			return;
		else if(p->info>x)
			return insert_node_recursive(x,p->left);
		else if(p->info<x)
			return insert_node_recursive(x,p->right);
	}
}
node *search(node *p,int x )
{
	if (p!=NULL)
	{
		if (p->info==x)
			return p;
		else
			if (x>p->info)
				return search(p->right,x);
			else
				return search(p->left,x);
	}
	return 0;
}
void searchstandfor(node *&p,node *&q)
{
	if (q->info==NULL)
	{
		p->info=q->info;
		p=q;
		q=q->right;
	}
	else
		searchstandfor(p,q->left);
}
int Delete(node *&t,int x)
{
	if (t==NULL) return 0;
	if(t->info==x)
	{
		node *p=t;
		if (t->left==NULL)
			t=t->right;
		else if (t->right==NULL)
			t=t->left;
			else
				searchstandfor(p,t->right);
		delete p;
		return 1;
	}
	else 
		if(t->info<x) 
			return Delete(t->right,x);
		else
			return Delete(t->left,x);
}
void duyetLNR(node *p)
{
	if (p!=NULL)
	{
		duyetLNR(p->left);
		cout<<p->info<<" ";
		duyetLNR(p->right);
	}
}
void duyetNLR(node *p)
{
	if (p!=NULL)
	{
		cout<<p->info<<" ";
		duyetNLR(p->left);
		duyetNLR(p->right);
	}
}
void duyetLRN(node *p)
{
	if (p!=NULL)
	{
		duyetLRN(p->left);
		duyetLRN(p->right);
		cout<<p->info<<" ";
	}
}
void print(node *p,int space)
{
	if (p==NULL)
		return;
	space+=COUNT;
	print(p->right, space);
	cout<<endl;
	for (int i= COUNT;i<space;i++)
		cout<<" ";
	cout<<p->info<<"\n";
	print(p->left,space);
}
void process_tree()
{
	print(root,0);
}
int main()
{
	int choise=0;
	int x,i;
	node *p;
	cout<<"------------BAI TAP 1. CHUONG 4, CAY NPTK----------"<<endl;
	cout<<"1. khoi tao cay nptk rong"<<endl;
	cout<<"2. them phan tu vao cay nptk"<<endl;
	cout<<"3. tim phan tu co gia tri x trong cay nptk"<<endl;
	cout<<"4. xoa phan tu co gia tri x trong cay nptk"<<endl;
	cout<<"5. duyet cau nptk theo LNR"<<endl;
	cout<<"6. duyet cau nptk theo NLR"<<endl;
	cout<<"7. duyet cau nptk theo LRN"<<endl;
	cout<<"8. xuat cay nptk"<<endl;
	cout<<"9. thoat"<<endl;
	do{
		cout<<"vui long chon so de thuc hien: ";
		cin>>choise;
		switch(choise)
		{
		case 1:
			init();
			cout<<"ban vua tao cay nhi phanthanh cong:\n";
			break;
		case 2:
			cout<<"vui long nhap gia tri x can them: ";
			cin>>x;
			insert_node_recursive(x,root);
			cout<<"cay nhi phan tim kiem sau khi them la: ";
			process_tree();
			break;
		case 3:
			cout<<"vui long nhap gia tri x can tim: ";
			cin>>x;
			p=search(root,x);
			if(p!=NULL)
				cout<<"tim thay x="<<x<<" trong cay nptk"<<endl;
			break;
		case 4:
			cout<<"vui long nhap gia tri x can xoa: ";
			cin>>x;
			i=Delete(root,x);
			if (i==0)
				cout<<"khong tim thây x="<<x<<" de xoa!"<<x<<endl;
			else
			{
				cout<<"da xoa thanh cong phan tu x="<<x<<" trong cay nptk"<<endl;
				cout<<"cay nptk sau khi xoa la: ";
				process_tree();
			}
			break;
		case 5:
			cout<<"cay nptk theo LNR la: ";
			duyetLNR(root);
			break;
		case 6:
			cout<<"cay nptk theo NLR la: ";
			duyetNLR(root);
			break;
		case 7:
			cout<<"cay nptk theo LRN la: ";
			duyetLRN(root);
			break;
		case 8:
			cout<<"cay nptk nhu sau: ";
			process_tree();
			break;
		case 9:
			cout<<"-----------goodbye-----------\n";
			break;
		default:
			break;
		}

	}while(choise!=9);
	system("pause");
	return 0;
}