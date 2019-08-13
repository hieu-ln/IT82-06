//bai 4 chuong 6
#include <stdio.h>
#include <iostream>
#include<fstream>
#include<iomanip>
using namespace std;
//Khai Bao
# define MAX 20
int a[MAX][MAX];
int n;
char verter[MAX];
void inipgraph()
{
	n=0;
}
void inphtgraphfromtext()
{
	string line;
	ifstream myfile("mtts1.txt");
	if(myfile.is_open())
	{
		myfile>>n;
		for(int i=0;i<n;i++)
			myfile>>verter[i];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				myfile>>a[i][j];
		}
	}
}
//Nhap Ma tRan Cua Do Thi
void inputgraph()
{
	cout<<"Nhap so dinh cua do thi n: ";
	cin>>n;
	cout<<"Nhap ten dinh: ";
	for(int i=0;i<n;i++)
		cin>>verter[i];
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap vao dong thu "<<i+1<<": ";
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	}
}
//Xuat Ma Tran Ke Cua Do Thi
void outputgraph()
{
	cout<<setw(6)<<left;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<setw(6)<<left;
		cout<<endl;
	}
}
// Khai Bao Tap E
int e1[MAX];
int e2[MAX];
int we[MAX];
int ne=0; //so Phan Tu Tap
//Khai Bao Tap T
int t1[MAX];
int t2[MAX];
int wt[MAX];
int nt=0;
int tontai(int d,int D[],int nD)
{
	for(int i=0;i<nD;i++)
		if(D[i]==d)
			return 1;
	return 0;
}
void xoavitrie(int i)
{
	for(int j=i;j<ne;j++)
	{
		e1[j]=e1[j+1];
		e2[j]=e2[j+1];
		we[j]=we[j+1];
	}
	ne--;
}
void xoacanhe(int u,int v)
{
	for(int i=0;i<ne;i++)
		if(e1[i]==u&&e2[i]==v)
		{
			xoavitrie(i);
			break;
		}
}
void prim(int s)
{
	int u=s,min,i,d1,d2;
	while(nt<n-1)
	{
		for(int v=0;v<n;v++)
			if(a[u][v]!=0)
				if(tontai(v,t2,nt)==0)
				{
					e1[ne]=u;
					e2[ne]=v;
					we[ne]=a[u][v];
					ne++;
				}
		for (i=0;i<ne;i++)
			if (tontai(e2[i],t2,nt)==0)
			{
				min=we[i];
				d1=e1[i];
				d2=e2[i];
				break;
			}
		for(i=0;i<ne;i++)
			if (tontai(e2[i],t2,nt)==0)
				if(min>we[i])
				{
					min=we[i];
					d1=e1[i];
					d2=e2[i];
				}
		t1[nt]=d1;
		t2[nt]=d2;
		wt[nt]=a[d1][d2];
		a[d1][d2]=0;
		a[d2][d1]=0;
		nt++;
		xoacanhe(d1,d2);
		u=d2;
	}
}
void output(bool vertername)
{
	int tong=0;
	for(int i=0;i<nt;i++)
	{
		if(vertername)
			cout<<endl<<"("<<verter[t1[i]]<<","<<verter[t2[i]]<<") = "<<	wt[i];
		else
			cout<<endl<<"("<<t1[i]<<","<<t2[i]<<") = "<<wt[i];
		tong+=wt[i];
	}
	cout<<"\n Tong = "<<tong;
}
int main()
{
	int choise,x,i;
	system("cls");
	cout<<"----------Bai Tap 4, Chuong 6------------";
	cout<<"1. Khoi Tao MA TRAN KE Rong"<<endl;
	cout<<"2. Nhap MA TRAN KE Tu File Text"<<endl;
	cout<<"3. Nhap MA TRAN KE"<<endl;
	cout<<"4. Xuat MA TRAN KE"<<endl;
	cout<<"5. Tim CAY KHUNG TOI THIEU Bang PRIM"<<endl;
	cout<<"6. Thoat"<<endl;
	do
	{
		cout<<"\nVui long chon so de thuc hien: ";
		cin>>choise;
		switch(choise)
		{
		case 1:
			inipgraph();
			cout<<"Ban vua khoi tao MA TRAN KE thanh cong!\n";
			break;
		case 2:
			inphtgraphfromtext();
			cout<<"Ban vua nhap mA TRAN KT tu file: \n";
			outputgraph();
			break;
		case 3:
			inputgraph();
			break;
		case 4:
			outputgraph();
			break;
		case 5:
			cout<<"vui long nhap dinh xuat phat: ";
			cin>>x;
			prim(x);
			cout<<"Cay khung toi thiu voi PRIM: "<<endl;
			output(true);
			break;
		case 6:
			cout<<"------ GOOD BYE--------";
			break;
		default:
			break;
		}
	}while("pause");
	return 0;
}