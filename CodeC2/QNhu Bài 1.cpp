//#include <stdio.h>
//#include <iostream>
//using namespace std;
//
//#define Max 100
//// cau 1.1
//int a[Max];
//int n;
//
////cau 1.2
//void input (int a[], int &n)
//{
//	cout<<"nhap vao so luong phan tu cua danh sach: ";
//	cin>>n;
//	cout<<"nhap vao cac phan tu cua danh sach: "<<endl;
//	for (int i=0; i<n; i++)
//	{
//		cout<<"a["<<i<<"]=";
//		cin>>a[i];
//	}
//	cout<<endl;
//}
//
//// cau 1.3
//void output (int a[], int n)
//{
//	for (int i=0; i<n; i++)
//		cout<<a[i]<<"\t";
//}
//
////cau 1.4
//int search (int a[], int n, int x)
//{
//	int i=0;
//	while ((i<n) && (a[i]!=x))
//	{
//		i++;
//		if (i==n)
//			return -1;
//	}
//	return i;
//}
//
////cau 1.5
//int insert_last (int a[], int &n, int x)
//{
//	if (n<Max)
//	{
//		a[n]=x;
//		n++;
//		return 1;
//	}
//	else 
//		return 0;
//}
//
////cau 1.6
//int delete_last (int a[], int &n)
//{
//	if (n>0)
//	{
//		n--;
//		return 1;
//	}
//	return 0;
//}
//
////cau 1.7
//int delete_i (int a[], int &n, int i)
//{
//	if (i>=0 && i<n)
//	{
//		for (int j=i; j<n-1; j++)
//		{
//			a[j]=a[j+1];
//		}
//		n--;
//		return 1;
//	}
//	return 0;
//}
//
////cau 1.8
//int SearchAndDelete (int a[], int &n, int x)
//{
//	for (int i=0; i<n; i++)
//	{
//		if (a[i]==x)
//		{
//			delete_i (a, n, i);
//			return 1;
//		}
//	}
//	return 0;
//}
//
//int main ()
//{
//	int choice =0;
//	int x, i;
//	system ("cls");
//	cout <<"-----------	CHUONG2_B1 -----------"<<endl;
//	cout<<"1. Nhap danh sach"<<endl;
//	cout<<"2. Xuat danh sach"<<endl;
//	cout<<"3. tim phan tu co gia tri x"<<endl;
//	cout<<"4. Them phan tu cuoi danh sach"<<endl;
//	cout<<"5. Xoa phan tu cuoi danh sach"<<endl;
//	cout<<"6. Xoa phan tu tai vi tri i"<<endl;
//	cout<<"7. Tim phan tu gia tri x va xoa neu co"<<endl;
//	cout<<"8. Thoat"<<endl;
//
//	do{
//		cout<<"Vui long chon so: ";
//		cin>>choice;
//		switch (choice)
//		{
//		case 1:
//			input (a,n);
//			cout<<"Ban da nhap danh sach thanh cong:!\n";
//			break;
//		case 2:
//			cout<<"Danh sach moi: \n";
//			output (a,n);
//			cout<<endl;
//			break;
//		case 3:
//			cout<<"Nhap phan tu x can tim: !\n";
//			cin>>x;
//			i=search (a,n,x);
//			if (i==-1)
//				cout <<"tim khong thay phan tu x= "<<x<<endl;
//			else
//
//				cout<<"Vi tri phan tu x la i=: "<<i<<endl;
//			break;
//		case 4:
//			cout<<"Nhap x can them vao cuoi ds: ";
//				cin>>x;
//			i=insert_last(a,n,x);
//			if (i==0)
//				cout<<"Danh sach day, khong the them";
//			else
//			{
//				cout<<"Da them phan tu x "<<i<<" vao cuoi danh sach"<<endl;
//				cout<<"Danh sach moi: !\n";
//				output(a,n);
//			}
//			break;
//		case 5:
//			i=delete_last(a,n);
//			if (i>0)
//			{
//				cout<<"xoa thanh cong!"<<endl;
//				
//				cout<<"Danh sach moi: !\n";
//				output (a,n);
//			}break;
//		case 6:
//			cout<<"Nhap vi tri i can xoa: !\n";
//			cin>>i;
//			i=delete_i(a, n, i);
//			if (i==1)
//			{
//				cout<<"xoa thanh cong!"<<endl;
//				cout<<"Danh sach moi: !\n";
//				output (a,n);
//			}
//			else
//				cout<<"Khong co phan tu nao de xoa"<<endl;
//			break;
//		case 7:
//			cout<<cout<<"Nhap gia tri can xoa x=";
//			cin>>x;
//			i=SearchAndDelete(a,n,x);
//			if(i==1)
//			{
//				cout<<"xoa thanh cong gia tri x="<<endl;
//				cout<<"danh sach moi: \n";
//				output (a,n);
//			}
//			else
//				cout<<"Khong co phan tu nao de xoa! "<<endl;
//			break;
//		case 8:cout<<"\nEND>"<<endl;
//			break;
//		default:
//			break;
//		}
//	}while (choice !=8);
//	system ("pause");
//	return 0;
//}

