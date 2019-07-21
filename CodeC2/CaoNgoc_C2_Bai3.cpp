////Chuong 2 Bai 3
//#include <iostream>
//using namespace std;
//
////3.1 Khai bao cau truc 
//struct Node
//{
//	int info;
//	Node* link;
//};
//Node* first;
////3.2 Khoi tao rong
//void init()
//{
//	first = NULL;
//}
////3.3 Duyet danh sach
//void Process_list()
//{
//	Node* p = first;
//	cout << "Danh sach hien tai la:\n";
//	while (p != NULL)
//	{
//		cout << p->info << "	";
//		p = p->link;
//	}
//	cout << endl;
//}
////3.4 Tim kiem phan tu
//Node* Search(int x)
//{
//	Node* p = first;
//	while (p != NULL && p->info != x)
//		p = p->link;
//	return p;
//}
////3.5 Them dau danh sach
//void Insert_first(int x)
//{
//	Node* p = new Node;
//	p->info = x;
//	p->link = first;
//	first = p;
//}
////3.6 Xoa dau danh sach
//int Delete_first()
//{
//	if (first != NULL)
//	{
//		Node* p = first;
//		first = p->link;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
////3.7 Them cuoi danh sach
//void Insert_last(int x)
//{
//	Node* p = new Node;
//	p->info = x;
//	p->link = NULL;
//	if (first == NULL)
//		first = p;
//	else
//	{
//		Node* q = first;
//		while (q->link != NULL)
//			q = q->link;
//		q->link = p;
//	}
//}
////3.8 Xoa cuoi danh sach
//int Delete_last()
//{
//	if (first != NULL)
//	{
//		Node* p, * q;
//		p = q = first;
//		while (p->link != NULL)
//		{
//			q = p;
//			p = p->link;
//		}
//		if (p != first)
//			q->link = NULL;
//		else first = NULL;
//		delete p;
//		return 1;
//	}
//	else return 0;
//}
////3.9 Tim kiem va xoa
//void Search_n_delete(int x)
//{
//	int soLan = 0;
//	Node* p, * q;
//	p = q = first;
//	do {
//		while (p->link != NULL && p->info != x)
//		{
//			q = p;
//			p = p->link;
//		}
//		if (p == first && p->info == x) // Neu la dau danh sach
//		{
//			first = p->link;
//			soLan++;
//		}
//		else if (p->info == x)
//		{
//			q->link = p->link;
//			p = p->link;
//			soLan++;
//		}
//		else
//			p = p->link;
//	} while (p != NULL);
//	delete p, q;
//	if (soLan != 0)
//	{
//		cout << "Da xoa thanh cong!! ";
//		Process_list();
//	}
//	else cout << "Gia tri " << x << " khong ton tai trong danh sach!!!\n";
//}
////Ham swap info 2 node
//void swap(Node* a, Node* b)
//{
//	int temp = a->info;
//	a->info = b->info;
//	b->info = temp;
//}
////3.10 Sap xep tang dan (SELECTION SORT)
//void sort()
//{
//	Node* p, * q, * min;
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
//		swap(min, p);
//		p = p->link;
//	}
//}
////3.11 Sap xep giam dan (SELECTION SORT)
//void sortDesc()
//{
//	Node* p, * q, * max;
//	p = first;
//	while (p != NULL)
//	{
//		max = p;
//		q = p->link;
//		while (q != NULL)
//		{
//			if (q->info > max->info)
//				max = q;
//			q = q->link;
//		}
//		swap(max, p);
//		p = p->link;
//	}
//}
//
//int main()
//{
//	int choice, x, i;
//	Node* p;
//	cout << "----- Bai 3 Chuong 2: DANH SACH LIEN KET DON -----\n";
//	cout << "1) Khoi tao danh sach rong\n";
//	cout << "2) Them phan tu dau danh sach\n";
//	cout << "3) Xoa phan tu dau danh sach\n";
//	cout << "4) Them phan tu cuoi danh sach\n";
//	cout << "5) Xoa phan tu cuoi danh sach\n";
//	cout << "6) Xuat danh sach\n";
//	cout << "7) Tim kiem mot phan tu\n";
//	cout << "8) Tim kiem va xoa phan tu\n";
//	cout << "9) Sap xep danh sach tang dan (SELECTION SORT)\n";
//	cout << "10) Sap xep danh sach giam dan (SELECTION SORT)\n";
//	cout << "-) Nhap ki tu bat ky de thoat\n";
//	do {
//		cout << "Lua chon cua ban: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			init();
//			cout << "Ban da khoi tao DSLK DON\n";
//			break;
//		case 2:
//			cout << "Nhap gia tri muon them dau: ";
//			cin >> x;
//			Insert_first(x);
//			Process_list();
//			break;
//		case 3:
//			p = first;
//			if (p != NULL)
//			{
//				Delete_first();
//				Process_list();
//			}
//			else
//				cout << "Danh sach rong. Khong the thuc hien thao tac!!!\n";
//			break;
//		case 4:
//			cout << "Nhap gia tri muon them cuoi: ";
//			cin >> x;
//			Insert_last(x);
//			Process_list();
//			break;
//		case 5:
//			p = first;
//			if (p != NULL)
//			{
//				Delete_last();
//				Process_list();
//			}
//			else cout << "Danh sach rong. Khong the thuc hien thao tac!!!\n";
//			break;
//		case 6:
//			p = first;
//			if (p != NULL)
//				Process_list();
//			else cout << "Danh sach rong. Khong the thuc hien thao tac!!!\n";
//			break;
//		case 7:
//			p = first;
//			if (p != NULL)
//			{
//				cout << "Nhap gia tri can tim: ";
//				cin >> x;
//				if (Search(x) != NULL)
//					cout << "Gia tri " << x << " co ton tai trong danh sach!\n";
//				else cout << "Gia tri " << x << " khong ton tai trong danh sach!\n";
//			}
//			else cout << "Danh sach rong. Khong the thuc hien tao tac!!!\n";
//			break;
//		case 8:
//			p = first;
//			if (p != NULL)
//			{
//				cout << "Nhap gia tri can tim: ";
//				cin >> x;
//				Search_n_delete(x);
//			}
//			else cout << "Danh sach rong. Khong the thuc hien thao tac!!!\n";
//			break;
//		case 9:
//			sort();
//			Process_list();
//			break;
//		case 10:
//			sortDesc();
//			Process_list();
//			break;
//		default:
//			cout << "Goodbye!!!\n";
//			choice = 99;
//			break;
//		}
//	} while (choice != 99);
//	return 0;
//}