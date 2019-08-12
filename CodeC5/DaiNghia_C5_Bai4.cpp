//Chuong 5 Bai 4
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define MAX 20
int A[MAX][MAX]; //mang ma tran
int n;// so dinh
char vertex[MAX];// ten dinh

//Cau truc DSLK don
struct Node {
	int info;
	Node *link;
};
//con tro STACK va QUEUE
Node *sp;
Node *front, *rear;
///STACK
void initS () {
	sp = NULL;
}
int isEmptyS ()
{
	if (sp == NULL)
		return 1;
	else return 0;
}
void PushS (int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}
int PopS (int &x)
{
	if (isEmptyS() != 1)
	{
		Node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	else return 0;
}
///QUEUE
void initQ ()
{
	front = NULL;
	rear = NULL;
}
int isEmptyQ ()
{
	if (front == NULL)
		return 1;
	else return 0;
}
void PushQ (int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else rear->link = p;
	rear = p;
}
int PopQ (int &x)
{
	if (isEmptyQ() != 1)
	{
		Node *p = front;
		x = p->info;
		front = front->link;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	else return 0;
}
///Khoi tao do thi
void initGraph () {
	n = 0;
}
//4.1 Nhap ma tran ke cua do thi 5.1
void inputGraphFromText ()
{
	ifstream Data;
	Data.open("matranke1.txt", ios::in);
	if (Data.is_open())
	{
		Data >> n;
		for (int i = 0; i < n; i++)
			Data >> vertex[i];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				Data >> A[i][j];
		Data.close();
	}
	else cout << "Khong the mo file!!!\n";
}
//Nhap ma tran ke cua do thi
void inputGraph ()
{
	string line;
	cout << "Nhap so dinh cua do thi: ";
	do {
		cin >> n;
		if (n <= 0 || n > MAX)
			cout << "Nhap sai! Nhap lai: ";
	} while (n <= 0 || n > MAX);
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap ten dinh: ";
		do {
			cin >> vertex[i];
			if (!(isalpha(vertex[i])))
				cout << "Ten dinh phai la chu cai! Nhap lai: ";
		} while (isalpha(vertex[i]) == 0);
		cout << "Nhap " << n << " gia tri cho dong " << i+1 << ": ";
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	}
}
//Xuat ma tran ke
void outputGraph ()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << A[i][j] << "	";
		cout << endl;
	}
}
//Xuat cac dinh
void outputVertex (int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << vertex[a[i]] << "	";
	cout << endl;
}
//Duyet do thi theo chieu rong BFS (dung QUEUE va DSLK don)
int C[MAX]; // Cac dinh chua xet. 1 la chua xet, 0 la da xet
int bfs[MAX]; // Cac phan tu da xet
int nbfs = 0; // So dinh da xet
void initC ()
{
	for (int i = 0; i < n; i++) // n la so dinh
		C[i] = 1;
}
void BFS (int v) // v la dinh bat dau
{
	int w, p;
	PushQ(v); // Dua dinh hien tai vao Queue
	C[v] = 0; // Trang thai cua dinh hien tai -> da xet
	while (front != NULL)
	{
		PopQ(p); // Lay phan tu trong Queue gan cho gia tri p
		bfs[nbfs++] = p; //luu dinh da xet vao mang bfs tai vi tri chi so dinh da xet dong thoi tang nbfs
		for (w = 0; w < n; w++)
		{
			if (C[w] == 1 && A[p][w] == 1) // Neu dinh thu C[w] la chua xet va dinh C[w] co cac dinh ke
			{
				PushQ(w);
				C[w] = 0;
			}
		}
	}
}
//Duyet do thi theo chieu sau DFS (dung STACK va DSLK don)
int dfs[MAX]; // cac phan tu da xet
int ndfs = 0; // So dinh da xet
void DFS (int s)
{
	PushS(s);
	dfs[ndfs++] = s;
	C[s] = 0;
	int v = -1, u = s;
	while (isEmptyS() != 1)
	{
		if (v == n)
			PopS(u);
		for (v = 0; v < n; v++)
			if (A[u][v] == 1 && C[v] == 1)
			{
				PushS(u); PushS(v);
				dfs[ndfs++] = v;
				C[v] = 0;
				u = v;
				break;
			}
	}
}
//Dung BFS de tim kiem tren do thi
void Search_by_BFS (int x, int v) // v la dinh bat dau
{
	int w, p;
	PushQ(v);
	C[v] = 0;
	while (front != NULL)
	{
		PopQ(p);
		if (x == p) {
			cout << "Tim thay x = " << x << endl;
			return;
		}
		for (w = 0; w < n; w++)
			if (C[w] == 1 && A[p][w] == 1)
			{
				PushQ(w);
				C[w] = 0;
			}

	}
}
//Xuat Menu
void outMenu ()
{
	cout << "----- CHUONG 5 BAI 4 -----\n";
	cout << "1) Khoi tao MA TRAN KE rong\n";
	cout << "2) Khoi tao MA TRAN KE tu file text\n";
	cout << "3) Nhap MA TRAN KE\n";
	cout << "4) Xuat MA TRAN KE\n";
	cout << "5) Duyet do thi theo chieu rong BFS\n";
	cout << "6) Duyet do thi theo chieu sau DFS\n";
	cout << "7) Tim kiem mot gia tri bang BFS\n";
	cout << "8) Clear man hinh console\n";
	cout << "9) Thoat\n";
}
int main()
{
	int a[MAX], b[MAX];
	int choice, sp, sp2, x, i;
	outMenu();
	do {
		cout << "Nhap so de chon thao tac: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			initGraph();
			cout << "Khoi tao MA TRAN KE rong thanh cong!!!\n";
			break;
		case 2:
			inputGraphFromText();
			cout << "Khoi tao MA TRAN KE tu file thanh cong!!!\n";
			break;
		case 3:
			inputGraph();
			break;
		case 4:
			outputGraph();
			break;
		case 5:
			initQ();
			initC();
			cout << "Hay nhap dinh xuat phat: ";
			do {
				cin >> x;
				if (x <= 0 || x > MAX)
					cout << "Nhap sai!!! Nhap lai: ";
			} while (x <= 0 || x > MAX);
			nbfs = 0;
			BFS(x-1);
			cout << "Thu tu duyet dinh BFS la: ";
			outputVertex(bfs, n);
			break;
		case 6:
			initS();
			initC();
			cout << "Hay nhap dinh xuat phat: ";
			do {
				cin >> x;
				if (x <= 0 || x > MAX)
					cout << "Nhap sai!!! Nhap lai: ";
			} while (x <= 0 || x > MAX);
			ndfs = 0;
			DFS(x-1);
			cout << "Thu tu duyet dinh DFS la: ";
			outputVertex(dfs, n);
			break;
		case 7:
			cout << "Hay nhap gia tri can tim: ";
			cin >> x;
			Search_by_BFS(x,0);
			break;
		case 8:
			system("cls");
			outMenu();
			break;
		default:
			cout << "Goodbye!!!\n";
			choice = 100;
			break;
		}
	} while (choice != 100);
	return 0;
}