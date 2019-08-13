//#include <iostream>
//#include <stdio.h>
//#include <fstream>
//#include <string>
//using namespace std;
//#define MAX 100
//int a[MAX][MAX];
//int n;
//char verter[MAX];
//struct node
//{
//	int info;
//	node *link;
//};
//node *sp;
//node *front,*rear;
//void initstack()
//{
//	sp=NULL;
//}
//int isemptys()
//{
//	if(sp==NULL)
//		return 1;
//	return 0;
//}
//void pushs(int x)
//{
//	node *p = new node;
//	p->info=x;
//	p->link=sp;
//	sp=p;
//}
//int pops(int &x)
//{
//	if (sp!=NULL)
//	{
//		node *p=sp;
//		x=p->info;
//		sp=p->link;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//void initqueue()
//{
//	front=NULL;
//	rear=NULL;
//}
//int isemptyq()
//{
//	if (front ==NULL)
//		return 1;
//	return 0;
//}
//void pushq(int x)
//{
//	node *p = new node;
//	p->info=x;
//	p->link=NULL;
//	if(rear==NULL)
//		front =p;
//	else
//		rear->link=p;
//	rear=p;
//}
//int popq(int &x)
//{
//	if (front!=NULL)
//	{
//		node *p=front;
//		front = p->link;
//		x=p->info;
//		if (front ==NULL)
//			rear=NULL;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//void initgraph()
//{
//	n=0;
//}
//void initgraphfromtext()
//{
//	string line;
//	ifstream myfile ("matranke1.txt");
//	if (myfile.is_open())
//	{
//		myfile>>n;
//		for (int i=0;i<n;i++)
//			myfile>>verter[i];
//		for (int i=0;i<n;i++)
//		{
//			for (int j=0;j<n;j++)
//				myfile>>a[i][j];
//		}
//	}
//}
//void input()
//{
//	cout<<"nhap so dinh do thi n: ";
//	cin>>n;
//	for(int i=0;i<n;i++)
//	{
//		cout<<"nhap vao dong thu "<<i+1<<": ";
//		for(int j=0;j<n;j++)
//			cin>>a[i][j];
//	}
//}
//void output()
//{
//	for (int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++)
//			cout<<a[i][j];
//		cout<<endl;
//	}
//}
//void outp(int a[],int n)
//{
//	for (int i=0;i<n;i++)
//		cout<<verter[a[i]]<<" ";
//}
//int c[100];
//int bfs[100];
//int nbfs=0;
//void initc()
//{
//	for(int i=0;i<n;i++)
//		c[i]=1;
//}
//void BFS(int v)
//{
//	int w,p;
//	pushq(v);
//	c[v]=0;
//	while(front!= NULL)
//	{
//		popq(p);
//		bfs[nbfs]=p;
//		nbfs++;
//		for (w=0;w<n;w++)
//			if (c[w]&&a[p][w]==1)
//			{
//				pushq(w);
//				c[w]=0;
//			}
//	}
//}
//void outputbfs()
//{
//	for (int i=0;i<n;i++)
//		cout<<bfs[i]<<" ";
//}
//int dfs[100];
//int ndfs=0;
//void DFS(int s)
//{
//	pushs(s);
//	dfs[ndfs]=s;
//	ndfs++;
//	c[s]=0;
//	int v=-1,u=s;
//	while(isemptys()==0)
//	{
//		if(v==n)
//			pops(u);
//		for(v=0;v<n;v++)
//			if (a[u][v]!=0&&c[v]==1)
//			{
//				pushs(v);
//				dfs[ndfs]=v;
//				ndfs++;
//				c[v]=0;
//				u=v;
//				break;
//			}
//	}
//}
//void searchbfs(int v,int x)
//{
//	int w,p;
//	pushq(v);
//	while(front!=NULL)
//	{
//		popq(p);
//		if(x==p)
//		{
//			cout<<"tim thay x="<<x<<endl;
//			return;
//		}
//		for (w=0;w<n;w++)
//			if(c[w]&&a[p][w]==1)
//			{
//				pushq(w);
//				c[w]=0;
//			}
//	}
//}
//int main()
//{
//	int a[MAX],b[MAX];
//	int choice,sp,sp_b,x,i;
//	system("cls");
//	cout<<"------------bai tap chuong 4, bai65------------"<<endl;
//	cout<<"1. kho tao ma tran ke rong"<<endl;
//	cout<<"2. nhap ma tran ke tu fule text"<<endl;
//	cout<<"3. nhap matran ke"<<endl;
//	cout<<"4. xuat ma tran ke"<<endl;
//	cout<<"5. duyet ma tran ke theo chieu rong BFS - DSLK"<<endl;
//	cout<<"6. duyet ma tran ke theo chieu sau DFS - DSLK"<<endl;
//	cout<<"7. tim dinh co gia tri x theo BFS"<<endl;
//	cout<<"8. thoat"<<endl;
//	do
//	{
//		cout<<endl<<"vui long chon so de thuc hien: ";
//		cin>>choice;
//		switch(choice)
//		{
//		case 1:
//			initgraph();
//			cout<<"ban vua khoi trao ma tran ke thanh cong";
//			break;
//		case 2:
//			initgraphfromtext();
//			cout<<"ban vua nhap ma tran ke tu file: \n";
//			output();
//			break;
//		case 3:
//			input();
//			break;
//		case 4:
//			output();
//			break;
//		case 5:
//			initqueue();
//			initc();
//			cout<<"vui long nhap dinh xuat phat: ";
//			cin>>x;
//			nbfs=0;
//			BFS(x);
//			cout<<"thu tu cac dinh sau khi duyet BFS: ";
//			outp(bfs,n);
//			break;
//		case 6:
//			initstack();
//			initc();
//			cout<<"vui long nhap dinh xuat phat: ";
//			cin>>x;
//			ndfs=0;
//			DFS(x);
//			cout<<"thu tu cac dinh sau khi duyet DFS: ";
//			outp(dfs,n);
//			break;
//		case 7:
//			cout<<"vui long nhap gia tri  x can tim: ";
//			cin>>x;
//			searchbfs(x,0);
//			break;
//		case 8:
//			cout<<"goodbye"<<endl;
//			break;
//		default:
//			break;
//		}
//	}while(choice!=8);
//	system("pause");
//	return 0;
//}