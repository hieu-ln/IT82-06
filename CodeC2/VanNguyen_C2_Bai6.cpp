#include<iostream>
using namespace std;

// khai báo  node
struct node
{
	int data;
	struct node *pNext;
};
typedef struct node NODE;
// khai báo cấu trúc  stack
struct stack
{
	NODE *pTop; // con trỏ quản lí đầu stack
};
typedef struct stack STACK;

// hàm khởi tạo stack
void KhoiTaoStack(STACK &s)
{
	s.pTop = NULL;
}

// hàm khởi tạo 1 cái node
NODE *KhoiTaoNode(int x)
{
	NODE *p = new NODE();
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data = x; // đưa dữ liệu của biến x vào trong cái data của node p
	p->pNext = NULL;
	return p;
}

/* ================= KIỂM TRA STACK RỖNG =================*/ 
int IsEmpty(STACK s)
{
	// nếu stack rỗng
	if (s.pTop == NULL)
	{
		return 0;
	}
	return 1;
}
int Push(STACK &s, NODE *p)
{
	// node p đang rỗng
	if (p == NULL)
	{
		return 0;
	}

	// nếu danh sách rỗng
	if (IsEmpty(s) == 0)
	{
		s.pTop = p;// node p cũng chính là node pTop <=>chính là node đầu stack
	}
	else
	{
		p->pNext = s.pTop; // B1: cho con trỏ của node p trỏ đến node pTop
		s.pTop = p;// cập nhật lại node đầu chính là node p
	}
	return 1;// thêm thành công
}

int Pop(STACK &s, int &x) // x chính là giá trị cần lấy ra
{
	// nếu danh sách rỗng
	if (IsEmpty(s) == 0)
	{
		return 0; // lấy thất bại <=> danh sách đang rỗng
	}
	NODE *p = s.pTop; // gán node đầu danh sách vào node p <=> node p chính là node mà tí nữa ta sẽ xóa nó
	s.pTop = s.pTop->pNext; // cập nhật lại node đầu 
	x = p->data; // lấy giá trị của node đầu ra gán vào biến x
	return true; // lấy phần tử thành công
}
int Top(STACK s, int &x) // x chính là giá trị cần xem
{
	// nếu danh sách rỗng

	if (IsEmpty(s) == 0)
	{
		return 0;
	}
	x = s.pTop->data;
	return 1;
}

// HÀM ĐỔI CƠ SỐ 10 SANG CƠ SỐ 2 8 16
void Chuyen_So_So(STACK &s, int hethapphan)
{
	while (hethapphan != 0)
	{
		int x = hethapphan % 2;
		NODE *p = KhoiTaoNode(x); // thêm x vào node p
		Push(s, p); // thêm node p vào stack
		hethapphan /= 2;
	}
}

// xuất danh sách stack
void XuatStack(STACK &s)
{
	while (IsEmpty(s) == 1)
	{
		int x;
		Pop(s, x);
		if (x < 10)
		{
			cout << x;
		}
		else
		{
			if (x == 10)
			{
				cout << "A";
			}
			else if (x == 11)
			{
				cout << "B";
			}
			else if (x == 12)
			{
				cout << "C";
			}
			else if (x == 13)
			{
				cout << "D";
			}
			else if (x == 14)
			{
				cout << "E";
			}
			else if (x == 15)
			{
				cout << "F";
			}
			
		}
	}
}



int main()
{
	STACK s;
	KhoiTaoStack(s);
	int hethapphan;
	cout << "\nNhap gia tri he thap phan(10) can chuyen: ";
	cin >> hethapphan;
	int cosocandoi;
	Chuyen_So_So(s, hethapphan);
	cout << "\nKET QUA\n";
	XuatStack(s);
	cout << endl;
	system("pause");
	return 0;
}

