//#include <iostream>
//#include <stdio.h>
//using namespace std;
//void inputa(int a[],int n)
//{
//	cout<<"nhap vao cac phan tu cua danh sach: "<<endl;
//	for (int i=0;i<n;i++)
//	{
//		cout<<"a["<<i<<"]=";
//		cin>>a[i];
//	}
//}
//void outputa(int a[],int n)
//{
//	if (0<n)
//	{
//		cout<<"danh sach cac phan tu la: "<<endl;
//		for (int i=0;i<n;i++)
//		{
//			cout<<a[i]<<"\t";
//		}
//		return;
//	}
//	cout<<"khong co phan tu nao.";
//}
// void inputb(int b[],int n)
//{
//	cout<<"nhap vao cac phan tu cua danh sach: "<<endl;
//	for (int i=0;i<n;i++)
//	{
//		cout<<"b["<<i<<"]=";
//		cin>>b[i];
//	}
//}
//void outputb(int b[],int n)
//{
//	if (0<n)
//	{
//		cout<<"danh sach cac phan tu la: "<<endl;
//		for (int i=0;i<n;i++)
//		{
//			cout<<b[i]<<"\t";
//		}
//		return;
//	}
//	cout<<"khong co phan tu nao.";
//}
//void giao(int a[],int b[] , int n,int m){
//	for (int i=0;i<n;i++)
//		for (int j=0;j<m;j++)
//			if(a[i]==b[j])
//			{
//				cout<<a[i]<<" ";
//				break;
//			}
//}
//void bu(int a[],int b[] , int n,int m){
//	for (int i=0;i<n;i++)
//		for (int j=0;j<m;j++)
//			if(a[i]!=b[j])
//			{
//				cout<<a[i]<<" ";
//				break;
//			}
//}
//int main()
//{
//	int a[100];
//	int b[100];
//	int m,n;
//	int choice;
//	do{
//		cout<<"vui long chon so de thuc hien: "<<endl;
//		cin>>choice;
//		switch(choice)
//		{
//		case 1:
//			cout<<"nhap vao phan tu cac dnah sach: ";
//			cin>>n;
//			inputa(a,n);
//			break;
//		case 2:
//			cout<<"nhap vao phan tu cac dnah sach: ";
//			cin>>m;
//			inputa(b,m);
//			break;
//		case 3:
//			giao(a,b,n,m);
//			break;
//		case 4:
//			bu(a,b,n,m);
//			break;
//		default:
//			cout<<"nhap lai"<<endl;
//			break;
//		}
//		
//	}while(choice !=5);
//	system("pause");
//	return 0;
//}