//#include <iostream>
//#include <stdio.h>
//#include <fstream>
//#include <iomanip>
//#include <sstream>
//using namespace std;
//
//#define MAX 20
//int n;	//so dinh cua do thi
//char vertex[MAX];	// ten dinh
//
//// dslk dung STACK va QUEUE
//struct node {
//	int info;
//	node *link;
//};
//node *sp;
//node *front, *rear;
//node *first[MAX];
//
////STACK
//void Init_stack() {
//	sp = NULL;
//}
//int isEmpty_stack() {
//	if (sp == NULL)
//		return 1;
//	return 0;
//}
//void Push_stack(int x) {
//	node *p = new node;
//	p->info = x;
//	p->link = sp;
//	sp = p;
//}
//int Pop_stack(int &x) {
//	if (sp != NULL) {
//		node *p = sp;
//		x = p->info;
//		sp = p->link;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//
//// QUEUE
//void Init_queue() {
//	front = NULL;
//	rear = NULL;
//}
//int isEmpty_queue() {
//	if (front == NULL)
//		return 1;
//	return 0;
//}
//void Push_queue(int x) {
//	node *p = new node;
//	p->info = x;
//	p->link = NULL;
//	if (rear == NULL)
//		front = p;
//	else
//		rear->link = p;
//	rear = p;
//}
//int Pop_queue(int &x) {
//	if (front != NULL) {
//		node *p = front;
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
//// GRAPH
//void Init_Graph() {
//	n = 0;
//}
//void InsertLast(node *&first, node *p)
//{
//	if (first == NULL)
//		first = p;
//	else {
//		node *q = first;
//		while (q->link != NULL)
//			q = q->link;
//		q->link = p;
//	}
//}
//void input_Grap_front_text() {
//	string line, str;
//	ifstream myfile ("danhsachke1.txt");
//	if (myfile.is_open()) {
//		myfile >> n;
//		for (int i = 0; i < n; i++)
//			myfile >> vertex[i];
//		int i = 0;
//		while(getline(myfile,str)) 
//		{
//			istringstream ss(str);
//			int u;
//			while (ss >> u) {
//				node *p = new node;
//				p->info = u;
//				p->link = NULL;
//				InsertLast(first[i-1],p);
//			}
//			i++;
//		}
//	}
//}
////void input() {
////	int d,x,m;
////	cout << "Nhap so dinh cua do thi: ";
////	cin >> n;
////	for (int i = 0; i < n; i++) {
////		cout << "Nhap dinh thu " << i + 1 << ": ";
////		cin >> d;
////		insert_first(first[i],d);
////		cout << "Nhap vao so dinh ke cua " << d << ": ";
////		cin >> m;
////		for (int j = 0; j < m; j++) {
////			cin >> x;
////			insert_first(first[i],x);
////		}
////	}
////}
//void outputGraph()
//{
//	for (int i = 0; i < n; i++) {
//		cout << "Dinh " << i << " (" << vertex[i] << "): ";
//		node *p = first[i];
//		while(p != NULL) {
//			cout << p->info << setw(4);
//			p = p->link;
//		}
//		cout << endl;
//	}
//}
//void output(int a[], int n) {
//	for (int  i = 0; i < n; i++)
//		cout << setw(4) << vertex[a[i]];
//	cout << endl;
//}
//// Duyet Graph theo BFS - queue - dslk
//int C[100], bfs[100];
//int nbfs = 0;
//void InitC() {
//	for (int i = 0; i < n; i++)
//		C[i] = 1;
//}
//void BFS(int v) {
//	int p;
//	node *w;
//	Push_queue(v);
//	C[v] = 0;
//	while (front != NULL) {
//		Pop_queue(p);
//		bfs[nbfs] = p;
//		w = first[p];
//		nbfs++;
//		while (w != NULL) {
//			if (C[w->info]) {
//				Push_queue(w->info);
//				C[w->info] = 0;
//			}
//			w =w->link;
//		}
//	}
//}
//
//// Duyet Grap theo DFS - stack - dslk
//int dfs[100];
//int ndfs = 0;
//void DFS(int s) {
//	Push_stack(s);
//	dfs[ndfs] = s;
//	ndfs++;
//	C[s] = 0;
//	int u = s;
//	node *v = NULL;
//	while (isEmpty_stack() == 0) {
//		if (v == NULL)
//			Pop_stack(u);
//		v = first[u];
//		while (v != NULL) {
//			if (C[v->info] == 1) {
//				Push_stack(u);
//				Push_stack(v->info);
//				dfs[ndfs] = v->info;
//				ndfs++;
//				C[v->info] = 0;
//				u = v->info;
//				break;
//			}
//			v = v->link;
//		}			
//	}
//}
//void Search_by_bfs(int x, int v) // v la dinh bat dau
//{
//	int p;
//	node *w;
//	Push_queue(v);
//	C[v] = 0;
//	while(front != NULL) {
//		Pop_queue(p);
//		if (x == p) {
//			cout << "Tim thay!" << endl;
//			return;
//		}
//		w = first[p];
//		while (w != NULL) {
//			if (C[w->info]) {
//				Push_queue(w->info);
//				C[w->info] = 0;
//			}
//			w = w->link;
//		}
//	}
//}
//int main()
//{
//	int choice, x;
//	system("cls");
//	cout << "---------- BAT TAP 4, CHUONG 5, DO THI ----------" << endl;
//	cout << "1. Khoi tao ma tran ke rong." << endl;
//	cout << "2. Nhap ma tran ke tu file text." << endl;
//	//cout << "3. Nhap ma tran ke bang tay." << endl;
//	cout << "4. Xuat ma tran ke." << endl;
//	cout << "5. Duyet do thi theo BFS-dslk." << endl;
//	cout << "6. Duyet do thi theo DFS-dslk." << endl;
//	cout << "7. Tim dinh co gia tri x." << endl;
//	cout << "8. Thoat." << endl;
//	do {
//		cout << "Nhap muc: ";
//		cin >> choice;
//		switch(choice) {
//		case 1:
//			Init_Graph();
//			cout << "Khoi toa MA TRAN KE thanh cong!" << endl;
//			break;
//		case 2:
//			input_Grap_front_text();
//			cout << "Da nhap ma tran ke tu file:" << endl;;
//			outputGraph();
//			break;
//		/*case 3:
//			input();
//			break;*/
//		case 4:
//			outputGraph();
//			break;
//		case 5:
//			Init_queue();
//			InitC();
//			cout << "Vui long nhap dinh xuat phat: ";
//			cin >> x;
//			nbfs = 0;
//			BFS(x);
//			cout << "thu tu danh sach sau khi duyet BFS: " << endl;
//			output(bfs,n);
//			break;
//		case 6:
//			Init_stack();
//			InitC();
//			cout << "Vui long nhap dinh xuat phat: ";
//			cin >> x;
//			ndfs = 0;
//			DFS(x);
//			cout << "thu tu danh sach sau khi duyet DFS: " << endl;
//			output(dfs,n);
//			break;
//		case 7:
//			cout << "Nhap gia tri x can tim: ";
//			cin >> x;
//			Search_by_bfs(x,0);
//			break;
//		case 8:
//			cout << "Tam biet!" << endl;
//			break;
//		default:
//			break;
//		}
//	} while (choice != 8);
//	system("pause");
//	return 0;
//}