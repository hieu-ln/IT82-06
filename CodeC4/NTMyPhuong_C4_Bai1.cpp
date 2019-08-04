//CHUONG 4-CAY NHI PHAN TIM KIEM
#include<iostream>
#include<math.h>
using namespace std;
#define count 8
//1.1
struct Node
{
	int info;
	Node *left;
	Node *right;
};
Node *root;
//1.2 khoi tao cay rong
void tree_empty()
{
	root = NULL;
}
//Them mot phan tu vao cay NPTK
void Insert_Node(Node *&p, int x)
{
	if( p == NULL)
	{
		p = new Node;
		p -> info = x;
		p -> left = NULL;
		p -> right = NULL;
	}
	else
	{
		if(p -> info == x)
			return;
		else if( p -> info > x)
			return  Insert_Node(p -> left , x);
		else
			return  Insert_Node(p -> right , x);
	}
}
//Tim mot phan tu su dung DE QUY
Node *search( Node *p, int x)
{
	if( p != NULL)
	{
		if( p -> info == x)
			return p;
		else
			if( x > p -> info)
				return search( p -> right, x);
			else
				return search( p -> left , x);
	}
	return NULL;
}
//1.5 Xoa mot phan tu dung DE QUY
void SearchStandFor(Node *&p, Node*&q)
{
	if(q ->left == NULL)
	{
		p -> info = q -> info;
		p = q;
		q = q -> right;

	}
	else
		SearchStandFor( p, q -> left);
}
int Delete(Node *&T, int x)
{
	if( T == NULL)
		return 0;
	if(T -> info == x)
	{
		Node *p = T;
		if(T -> left == NULL)
			T = T -> right;
		else if(T -> right == NULL)
			T = T -> left;
		else
			SearchStandFor(p, T -> right);
		delete p;
		return 1;
	}
	else if(T -> info < x)
		return Delete(T -> right, x);
	else
		return Delete(T -> left, x);
}
// Duyet LNR
void DuyetLNR(Node *p)
{
	if( p != NULL)
	{
		DuyetLNR(p -> left);
		cout << p -> info << " ";
		DuyetLNR( p -> right);
	}
}
//Duyet NLR
void DuyetNLR(Node *p)
{
	if( p != NULL)
	{
		cout << p -> info << " ";
		DuyetNLR( p -> left);
		DuyetNLR( p -> right);
	}
}
//DuyetLRN
void DuyetLRN(Node *p)
{
	if( p != NULL)
	{
		DuyetLRN( p -> left);
		DuyetLRN( p -> right);
		cout << p -> info << " ";
	}
}

void print2DUtil(Node *p, int space)
{
	if(p == NULL)
		return;
	space += count;
	print2DUtil(p -> right , space);
	cout << endl;
	for( int i = count; i < space ; i++)
		cout << " ";
	cout << p -> info << "\n";
	print2DUtil( p -> left, space);
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
	cout <<"--BAI TAP THUC HANH CHUONG 4- CAY NHI PHAN TIM KIEM--\n";
	cout <<"1.Khoi tao cay NPTK rong\n";
	cout <<"2.Them phan tu vao cay NPTK\n";
	cout <<"3.Tim phan tu co gia tri x trong cay NPTK\n";
	cout <<"4.Xoa phan tu co gia tri x trong cay NPTK\n";
	cout <<"5.Duyet cay NPTK theo LNR\n";
	cout <<"6.Duyet cay NPTK theo NLR\n";
	cout <<"7.Duyet cay NPTK theo LRN\n";
	cout <<"8.Xuat cay NPTK\n";
	cout <<"9.Thoat" << endl;
	do{
		cout <<"\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			tree_empty();
			cout <<"Ban vua khoi tao cay rong thanh cong\n";
			break;
		case 2:
			cout <<"Nhap gia tri x can them x= ";
			cin >> x;
			Insert_Node(root, x);
			cout <<"Cay NPTK sau khi them la: ";
			Process_Tree();
			break;
		case 3:
			cout <<"Nhap x can tim x= ";
			cin >> x;
			p = search(root, x);
			if(p != NULL)
				cout << "Tim thay x= "<< x << " trong cay NPTK" << endl;
			else
				cout <<"Khong tim thay phan tu co gia tri " << x << " trong cay NPTK" << endl;
			break;
		case 4:
			cout <<"Vui long nhap x can xoa x= ";
			cin >> x;
			i = Delete(root ,x);
			if( i == 0)
				cout << "Khong tim thay x de xoa" << endl;
			else
			{
				cout << "Da xoa thanh cong phan tu x= " << x << " trong cay NPTK" << endl;
				cout <<"Cay NPYK sau khi xoa la: ";
				Process_Tree();
			}
			break;
		case 5:
			cout <<"Cay NPTK duyet theo LNR la: ";
			DuyetLNR(root);
			break;
		case 6:
			cout <<"Cay NPTK duyet theo NLR la: ";
			DuyetNLR(root);
			break;
		case 7:
			cout <<"Cay NPTK duyet theo LRN la: ";
			DuyetLRN(root);
			break;
		case 8:
			cout << "Cay nhi phan tim kiem nhu sau: ";
			Process_Tree();
			break;
		case 9:
			cout <<"Thoat\n";
			break;
		default:
			break;
		}
	}while(choice != 9);
	system("pause");
	return 0;
}
