//Bai 1, Chuong 4: Cay nhi phan tim kiem
#include <stdio.h>
#include <iostream>
using namespace std;

#define COUNT 10

//Cau 1.1
struct Node
{
	int info;
	Node *left;
	Node *right;
};
Node *root;

//Cau 1.2
void Init()
{
	root = NULL;
}
 //Cau 1.3
//khong su dung dia chi con tro
int Insert_Node_Recursive(int x, Node *q)
{
	if(q->info == x)
		return 0;
	else if(q->info > x)
	{
		if(q->left == NULL)
		{
			Node *p = new Node;
			p->info = x;
			p->left = NULL;
			p->right = NULL;
			q->left = p;
			return 1;
		}
		else
			return Insert_Node_Recursive(x, q->left);
	}
	else
	{
		if(q->right == NULL)
		{
			Node *p = new Node;
			p->info = x;
			p->left = NULL;
			p->right = NULL;
			q->right = p;
			return 1;
		}
		else
			return Insert_Node_Recursive(x, q->right);
	}
}
//su dung dia chi con tro
void InsertNode(Node *&p, int x)
{
	if(p == NULL)
	{
		p = new Node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if(p->info == x)
			return;
		else if(p->info > x)
			return InsertNode(p->left, x);
		else
			return InsertNode(p->right, x);
	}
}
//Cau 1.4
Node *Search(Node *p, int x)
{
	if(p != NULL)
	{
		if(p->info == x)
			return p;
		else
			if(x > p->info)
				return Search(p->right, x);
			else
				return Search(p->left, x);
	}
	return NULL;
}

//Cau 1.5
void SearchStandFor(Node *&p, Node *&q)
{
	if(q->left == NULL)
	{
		p->info = q->info;
		p = q;
		q = q->right;
	}
	else
		SearchStandFor(p, q->left);
}
int Delete(Node *&T, int x)
{
	if(T == NULL)
		return 0;
	if(T->info == x)
	{
		Node *p = T;
		if(T->left == NULL)
			T = T->right;
		else if(T->right == NULL)
			T = T->left;
		else
			SearchStandFor(p, T->right);
		delete p;
		return 1;
	}
	if(T->info <= x)
		return Delete(T->right, x);
	if(T->info > x)
		return Delete(T->left, x);
}

//Cau 1.6
void DuyetLNR(Node *p)
{
	if(p != NULL)
	{
		DuyetLNR(p->left);
		cout << p->info << " ";
		DuyetLNR(p->right);
	}
}

//Cau 1.7
void DuyetNLR(Node *p)
{
	if(p != NULL)
	{
		cout << p->info << " ";
		DuyetNLR(p->left);
		DuyetNLR(p->right);
	}
}

//Cau 1.8
void DuyetLRN(Node *p)
{
	if(p != NULL)
	{
		DuyetLRN(p->left);
		DuyetLRN(p->right);
		cout << p->info << " ";
	}
}

void print2DUtil(Node *p, int space)
{
	if(p == NULL)
		return;
	space += COUNT;
	print2DUtil(p->right, space);
	cout << endl;
	for(int i = COUNT; i < space; i++)
		cout << " ";
	cout << p->info << "\n";
	print2DUtil(p->left, space);
}

void Process_Tree()
{
	print2DUtil(root, 0);
}

int main()
{
	int choice = 0;
	int x, i;
	Node *p;
	system("cls");
	cout << "---------- C4_B1 ----------\n";
	cout << "1. Khoi tao cay NPTK rong\n";
	cout << "2. Them phan tu vao cay NPTK\n";
	cout << "3. Tim phan tu co gia tri x trong cay NPTK\n";
	cout << "4. Xoa phan tu co gia tri x trong cay NPTK\n";
	cout << "5. Duyet cay NPTK theo LNR\n";
	cout << "6. Duyet cay NPTK theo NLR\n";
	cout << "7. Duyet cay NPTK theo LRN\n";
	cout << "8. Xuat cay NPTK\n";
	cout << "9. Thoat\n";
	do{
		cout << "\nChon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			Init();
			cout << "Khoi tao thanh cong CAY NPTK!\n";
			break;
		case 2:
			cout << "Nhap gia tri x can them: ";
			cin >> x;
			InsertNode(root, x);
			cout << "cay NPTK moi: ";
			Process_Tree();
			break;
		case 3:
			cout << "Nhap gia tri x can tim: ";
			cin >> x;
			p = Search(root, x);
			if(p!=NULL)
				cout << "Tim thay x = " << x << " trong cay NPTK\n";
			else
				cout << "Khong tim thay x = " << x << " trong cay NPTK\n";
			break;
		case 4:
			cout << "Nhap gia tri x can xoa: ";
			cin >> x;
			i = Delete(root, x);
			if(i == 0)
				cout << "Khong tim thay x = " << x << " de xoa!\n";
			else
			{
				cout << "Xoa thanh cong phan tu x = "<< x << " trong cay NPTK!\n";
				cout << "cay NPTK moi: ";
				Process_Tree();
			}
			break;
		case 5:
			cout << "cay NPTK duyet theo LNR la: ";
			DuyetLNR(root);
			break;
		case 6:
			cout << "cay NPTK duyet theo NLR la: ";
			DuyetNLR(root);
			break;
		case 7:
			cout << "cay NPTK duyet theo LRN la: ";
			DuyetLRN(root);
			break;
		case 8:
			cout << "cay NPTK nhu sau: ";
			Process_Tree();
			break;
		case 9:
			cout << "End.....!\n";
			break;
		default:
			break;
		}
	}while(choice!=9);
	system("pause");
	return 0;
}