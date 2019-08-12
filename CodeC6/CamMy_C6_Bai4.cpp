#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;
//khai bao ma tran bang mang hai chieu
#define MAX 20
int A[MAX][MAX];
int n;
char vertex[MAX];
//khoi tao ma tran ke
void InitGraph()
{
	n=0;
}
//nhap ma tran ke
void inputGraphFromText()
{
	string line;
	ifstream myfile("matranke1.txt");
	if(myfile.is_open())
	{
		myfile >> n;
		for(int i=0; i<n; i++)
			myfile>>vertex[i];
		for(int i=0;i<n;i++)
		{
			for(int j=0; j<n; j++)
				myfile>>A[i][j];
		}
	}
}
void inputGraph()
{
	cout << "Nhap so dinh do thi n: ";
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cout << "Nhap ten dinh: ";
		cin >> vertex[i];
		cout << "Nhap vao dong thu " << i+1 << ": ";
		for(int j=0; j<n; j++)
			cin >> A[i][j];
	}
}
//xuat ma tran ke
void outputGraph()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout << A[i][j]<< " ";
		cout << endl;
	}
}

//khai bao TapE
int E1[MAX];
int E2[MAX];
int wE[MAX];
int nE=0; //so phan tu tu tap E
//khai bao TapE
int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT=0; //so phan tu tap T

int TonTai(int d, int D[], int nD)
{
	for(int i=0; i<nD; i++)
		if(D[i]==d)
			return 1;
	return 0;
}
void XoaViTriE(int i)
{
	for(int j=i; j<nE; j++)
	{
		E1[j] = E1[j+1];
		E2[j] = E2[j+1];
		wE[j] = wE[j+1];
	}
	nE--;
}
void XoaCanhE(int u, int v)
{
	for(int i=0; i<nE; i++)
		if(E1[i]==u && E2[i]==v)
		{
			XoaViTriE(i);
			break;
		}
}
void prim(int s)//s la dinh bat dau
{
	int u=s, min, i, d1=0, d2=0;
	while(nT<n-1)
	{
		for(int v=0; v<n; v++)
			if(A[u][v]!=0)
				if(TonTai(v, T2, nT)==0)
				{
					E1[nE] = u;
					E2[nE] = v;
					wE[nE] = A[u][v];
					nE++;
				}
		for(i=0; i<nE; i++)
		if(TonTai(E2[i], T2, nT)==0)
		{
			min = wE[i];
			d1 = E1[i];
			d2 = E2[i];
			break;
		}
		for(i=0; i<nE;i++)
			if(TonTai(E2[i], T2, nT)==0)
				if(min > wE[i])
				{
					min = wE[i];
					d1 = E1[i];
					d2 = E2[i];
				}
		T1[nT] = d1;
		T2[nT] = d2;
		wT[nT] = A[d1][d2];
		A[d1][d2]=0;
		A[d2][d1]=0;
		nT++;
		XoaCanhE(d1, d2);
		u = d2;
	}
}
void output()
{
	int tong=0;
	for(int i=0; i<nT; i++)
	{
		cout << endl << "(" << T1[i] << "," << T2[i] << ") = " << wT[i];
		tong += wT[i];
	}
	cout << "\n Tong = " << tong;
}

int main()
{
	int choice;
	system("cls");
	cout << "----- BAI TAP 4 - CHUONG 6 -----\n";
	cout << "1. Khoi tao Ma Tran Ke rong\n";
	cout << "2. Nhap Ma Tran Ke\n";
	cout << "3. Xuat Ma Tran Ke\n";
	cout << "4. Tim cay khung toi tieu bang thuat giai PRIM\n";
	cout << "5. Thoat\n";
	do{
		cout << "\nVui long nhap so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			InitGraph();
			cout << "Ban vua khoi tao thanh cong Ma Tran Ke!\n";
			break;
		case 2:
			inputGraph();
			break;
		case 3:
			outputGraph();
			break;
		case 4:
			prim(vertex[0]);
			cout << "Cay khung toi tieu:";
			output();
			break;
		case 5:
			cout << "Good bye ...!\n";
			break;
		default:
			break;
		}
	}while(choice!=5);
	system("pause");
	return 0;
}