////Chuong 2, Bai 5
//#include <iostream>
//using namespace std;
//
//#define MAX 100
////5.2 Khoi tao rong
//void init(int a[], int& sp) {
//	sp = -1;
//}
////5.3 Kiem tra rong
//int isEmpty(int a[], int sp)
//{
//	if (sp == -1)
//		return 1;
//	else return 0;
//}
////5.4 Kiem tra day
//int isFull(int a[], int sp)
//{
//	if (sp == MAX - 1)
//		return 1;
//	else return 0;
//}
////Xuat STACK
//void Process_Stack(int a[], int sp)
//{
//	if (isEmpty(a, sp) == 1)
//		cout << "STACK dang rong!!! Hay them phan tu!!!\n";
//	else
//	{
//		cout << "Danh sach hien tai la:\n";
//		for (int i = 0; i < sp + 1; i++)
//			cout << a[i] << "	";
//		cout << endl;
//	}
//}
////5.5 Them phan tu
//void Push(int a[], int& sp, int x)
//{
//	if (isFull(a, sp) != 1)
//	{
//		a[++sp] = x;
//		cout << "Them thanh cong!!!";
//		Process_Stack(a, sp);
//	}
//	else cout << "Danh sach day. Khong the thuc hien thao tac!!!\n";
//}
////5.6 Lay phan tu
//void Pop(int a[], int& sp)
//{
//	if (sp != -1)
//	{
//		cout << "Phan tu duoc lay ra: " << a[sp--] << endl;
//		Process_Stack(a, sp);
//	}
//	else cout << "Danh sach trong. Khong the thuc hien tao tac!!!\n";
//}
//
//int main()
//{
//	int a[MAX], choice, x, y, sp;
//	cout << "----- Chuong 2 Bai 5 -----\n";
//	cout << "1) Khoi tao STACK rong\n";
//	cout << "2) Them phan tu vao STACK\n";
//	cout << "3) Lay phan tu ra khoi STACK\n";
//	cout << "4) Kiem tra STACK co dang rong hay khong\n";
//	cout << "5) Kiem tra STACK co day hay khong\n";
//	cout << "6) Xuat STACK\n";
//	cout << "-) Ki tu bat ky de thoat\n";
//	do {
//		cout << "Lua chon cua ban: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			init(a, sp);
//			cout << "Khoi tao STACK thanh cong!!!\n";
//			break;
//		case 2:
//			cout << "Nhap gia tri muon them vao STACK: ";
//			cin >> x;
//			Push(a, sp, x);
//			break;
//		case 3:
//			Pop(a, sp);
//			break;
//		case 4:
//			if (isEmpty(a, sp) != 1)
//				cout << "STACK khong rong!\n";
//			else cout << "STACK rong!\n";
//			break;
//		case 5:
//			if (isFull(a, sp) != 1)
//				cout << "STACK chua day!\n";
//			else cout << "STACK da day!\n";
//			break;
//		case 6:
//			Process_Stack(a, sp);
//			break;
//		default:
//			cout << "Goodbye!!!\n";
//			choice = 7;
//			break;
//		}
//	} while (choice != 7);
//	return 0;
//}