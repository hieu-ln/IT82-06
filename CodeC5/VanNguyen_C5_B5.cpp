#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
#define MAX 20
int n;
char verter[MAX];
struct node
{
	int info;
	node *link;
};
node *sp;
node *front,*rear;
node *first[MAX];
void initstack()
{
	sp=NULL;
}
int isemptys()
{
	if(sp==NULL)
		return 1;
	return 0;
}
void pushs(int x)
{
	node *p = new node;
	p->info=x;
	p->link=sp;
	sp=p;
}
int pops(int &x)
{
	if (sp!=NULL)
	{
		node *p=sp;
		x=p->info;
		sp=p->link;
		delete p;
		return 1;
	}
	return 0;
}
void initqueue()
{
	front=NULL;
	rear=NULL;
}
int isemptyq()
{
	if (front ==NULL)
		return 1;
	return 0;
}
void pushq(int x)
{
	node *p = new node;
	p->info=x;
	p->link=NULL;
	if(rear==NULL)
		front =p;
	else
		rear->link=p;
	rear=p;
}
int popq(int &x)
{
	if (front!=NULL)
	{
		node *p=front;
		front = p->link;
		x=p->info;
		if (front ==NULL)
			rear=NULL;
		delete p;
		return 1;
	}
	return 0;
}
void initgraph()
{
	n=0;
}
void insertlast(node *&first,node *p)
{
	if(first==NULL)
		first=p;
	else{
		node*q=first;
		while(q->link!=NULL)
		{
			q=q->link;
		}
		q->link=p;
	}
}
void initgraphfromtext()
{
	string line;
	ifstream myfile ("danhsachke1.txt");
	if (myfile.is_open())
	{
		myfile>>n;
		for (int i=0;i<n;i++)
			myfile>>verter[i];
		string str;
		int i=0;
		while(getline(myfile,str))
		{
			istringstream ss(str);
			int u;
			while(ss>>u)
			{
				node *p=new node;
				p->info=u;
				p->link=NULL;
				insertlast(first[i-1],p);
			}
			i++;
		}
	}
}
void inputgraph()
{
	cout<<"nhap so dinh do thi n: ";
	cin>>n;
	cout<<"nhap ten dinh: ";
	for(int i=0;i<n;i++)
		cin>>verter[i];
	for(int i=0;i<n;i++)
	{
		if(i>0)
			cout<<"nhap dsk cua dinh thu"<<i-1<<" ("<<verter[i-1]<<") : ";
		int u;
		string str;
		while(getline(cin,str))
		{
			istringstream ss(str);
			while(ss>>u)
			{
				node *p=new node;
				p->info=u;
				p->link=NULL;
				insertlast(first[i-1],p);
			}
			break;
		}
	}
}
void outputgraph()
{
	for (int i=0;i<n;i++)
	{
		cout<<"dinh "<<i<<" ("<<verter[i]<<"): ";
		node *p=first[i];
		while(p!=NULL)
		{
			cout<<p->info<<" ";
			p=p->link;
		}
		cout<<endl;
	}
}
void output(int a[],int n)
{
	for (int i=0;i<n;i++)
		cout<<verter[a[i]]<<" ";
}
int c[100];
int bfs[100];
int nbfs=0;
void initc()
{
	for(int i=0;i<n;i++)
		c[i]=1;
}
void BFS(int v)
{
	int p;
	node *w;
	pushq(v);
	c[v]=0;
	while(front!= NULL)
	{
		popq(p);
		bfs[nbfs]=p;
		w=first[p];
		nbfs++;
		while(w!=NULL)
		{
			if (c[w->info])
			{
				pushq(w->info);
				c[w->info]=0;
			}
			w=w->link;
		}
	}
}
void outputbfs()
{
	for (int i=0;i<n;i++)
		cout<<bfs[i]<<" ";
}
int dfs[100];
int ndfs=0;
void DFS(int s)
{
	pushs(s);
	dfs[ndfs]=s;
	ndfs++;
	c[s]=0;
	int u=s;
	node *v =NULL;
	while(isemptys()==0)
	{
		if(v==NULL)
			pops(u);
		v=first[u];
		while(v!=NULL)
		{
			if (c[v->info]==1)
			{
				pushs(u);
 				dfs[ndfs]=v->info;
				ndfs++;
				c[v->info]=0;
				u=v->info;
				break;
			}
			v=v->link;
		}
	}
}
void searchbfs(int v,int x)
{
	int p;
	node *w;
	pushq(v);
	c[v]=0;
	while(front!=NULL)
	{
		popq(p);
		if(x==p)
		{
			cout<<"tim thay x="<<x<<endl;
			return;
		}
		w=first[p];
		while(front!=NULL)
		{
				if(c[w->info])
				{
					pushq(w->info);
					c[w->info]=0;
				}
				w=w->link;
		}
	}
}
int main()
{
	int choice,x;
	system("cls");
	cout<<"------------bai tap chuong 5, bai6------------"<<endl;
	cout<<"1. khoi tao ma tran ke rong"<<endl;
	cout<<"2. nhap danh sach ke tu fule text"<<endl;
	cout<<"3. nhap danh sach ke"<<endl;
	cout<<"4. xuat danh sach ke"<<endl;
	cout<<"5. duyet ma tran ke theo chieu rong BFS - DSLK"<<endl;
	cout<<"6. duyet ma tran ke theo chieu sau DFS - DSLK"<<endl;
	cout<<"7. tim dinh co gia tri x theo BFS"<<endl;
	cout<<"8. thoat"<<endl;
	do
	{
		cout<<endl<<"vui long chon so de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			initgraph();
			cout<<"ban vua khoi trao ma tran ke thanh cong";
			break;
		case 2:
			initgraphfromtext();
			cout<<"ban vua nhap ma tran ke tu file: \n";
			outputgraph();
			break;
		case 3:
			inputgraph();
			break;
		case 4:
			outputgraph();
			break;
		case 5:
			initqueue();
			initc();
			cout<<"vui long nhap dinh xuat phat: ";
			cin>>x;
			nbfs=0;
			BFS(x);
			cout<<"thu tu cac dinh sau khi duyet BFS: ";
			output(bfs,n);
			break;
		case 6:
			initstack();
			initc();
			cout<<"vui long nhap dinh xuat phat: ";
			cin>>x;
			ndfs=0;
			DFS(x);
			cout<<"thu tu cac dinh sau khi duyet DFS: ";
			output(dfs,n);
			break;
		case 7:
			initqueue();
			initc();
			nbfs=0;
			cout<<"vui long nhap gia tri x can tim: ";
			cin>>x;
			searchbfs(x,0);
			break;
		case 8:
			cout<<"goodbye"<<endl;
			break;
		default:
			break;
		}
	}while(choice!=8);
	system("pause");
	return 0;
}