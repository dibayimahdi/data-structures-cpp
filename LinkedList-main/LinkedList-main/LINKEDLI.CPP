#include<iostream.h>
#include<conio.h>
struct node{
 float data;
 int next;
 int empty;
};
class linkedlist{
 private:
  int first[3];
  int size;
  node *L;
 public:
 linkedlist(int=100);
 void addfirst(float,int);
 void addnode(float,int);
 int count();
 int getnode();
 void traverse(int);
 void printreverse(int);
 void insafter(int,float,int);
 void insbefore(int,float,int);
 float Delete(int,int);
 ~linkedlist();
};
//-------------------------------------
linkedlist::linkedlist(int s)
{
 size=s;
 L=new node[size];
 for(int i=0;i<size;i++)
     L[i].empty= 1;
 for(i=0;i<3;i++)
       first[i]=-1;
}
linkedlist::~linkedlist()
{
 delete[] L;
}
int linkedlist::getnode()
{
  for(int i=0;i<size;i++)
  if(L[i].empty==1)
  {
   L[i].empty=0;
   break;
  }
 return i;
}
void linkedlist::addfirst(float f,int i)
{
 int p;
 p=getnode();
 L[p].data=f;
 L[p].next=first[i-1];
 first[i-1]=p;
}
int linkedlist::count()
{
 int c=0;
 for(int i=0;i<size;i++)
   if(L[i].empty==0)
      c++;
 return c;
}
void linkedlist::addnode(float f,int i)
{
 int t;
 int p;
 p=getnode();
 if(first[i-1]!=-1)
     {
     for(t=first[i-1];L[t].next!=-1;t=L[t].next);
     L[t].next=p;
     }
 else
     first[i-1]=p;
 L[p].data=f;
 L[p].next=-1;
}
void linkedlist::traverse(int i)
{
 int p;
 p=first[i-1];
 while(p!=-1)
 {
 cout<<L[p].data<<"  ";
 p=L[p].next;
 }
}
void linkedlist::printreverse(int i)
{
 int p;
 static int c=0;
 if(c==0)
      p=first[i-1];
 else
      p=i;
 c++;
 if(p==-1)
     return;
 printreverse(L[p].next);
 cout<<L[p].data<<"  ";
}
/*void linkedlist::reverse list (int i)
{
 int p,q,s;
 p=first[i-1];
 q=L[p].next;
 while(q!=-1)
 {
  s=L[q].next;
  L[q].next=p;
  p=q;
  q=s;
 }
 L[first[i-1]].next=-1;
 first[i-1]=p;
 traverse(i);
}*/
/*inser f after element j in list i*/
void linkedlist::insafter(int/*element j*/ j,float f,int/*in list*/ i)
{
 int p;
 int t;
 int counter=1;
 p=getnode();
 L[p].data=f;
 for(t=first[i-1];counter<j;t=L[t].next)
   counter++;
 L[p].next=L[t].next;
 L[t].next=p;
}
/*insert f before element j in list i*/
void linkedlist::insbefore(int/*element j*/j,float f,int/*in list*/i)
{
 int p;
 int t;
 int counter=1;
 p=getnode();
 L[p].data=f;
 for(t=first[i-1];counter<j-1;t=L[t].next)
   counter++;
 if(j==1)
 {
  L[p].next=first[i-1];
  first[i-1]=p;
 }
 else
 {
 L[p].next=L[t].next;
 L[t].next=p;
 }
}
float linkedlist::Delete(int j,int i)
{
 int t;
 float f;
 int counter=1;
 if(j==1)
 {
  f=L[first[i-1]].data;
  L[first[i-1]].empty=1;
  first[i-1]=L[first[i-1]].next;


 }
 else
 {
 for(t=first[i-1];counter<j-1;t=L[t].next)
   counter++;
  f=L[L[t].next].data;
  L[L[t].next].empty=1;
  L[t].next=L[L[t].next].next;
 }
 return f;
}
//----------------------------------
void main()
{
 char ch;
 clrscr();

 linkedlist z(100);
 float data;
 int act,list,node;
 cout<<"1)add node  2)add first  3)insert after  4)insert before  5)Delete  6)traverse  7)printreverse  8)count\n";
 do{
 cout<<"wich function do you want to do?\n";
 cin>>act;
 switch(act){
      case 1:
		cout<<"list:";
		cin>>list;
		cout<<"data:";
		cin>>data;
		z.addnode(data,list);
		break;
      case 2:

		cout<<"list:";
		cin>>list;
		cout<<"data:";
		cin>>data;
		z.addfirst(data,list);
		break;
      case 3:
		cout<<"list:";
		cin>>list;
		cout<<"node:";
		cin>>node;
		cout<<"data:";
		cin>>data;
		z.insafter(node,data,list);
	       break;
     case 4:
		cout<<"list:";
		cin>>list;
		cout<<"node:";
		cin>>node;
		cout<<"data:";
		cin>>data;
		z.insbefore(node,data,list);
		break;
      case 5:
		cout<<"list:";
		cin>>list;
		cout<<"node:";
		cin>>node;
		z.Delete(node,list);
		break;
      case 6:
		cout<<"list:";
		cin>>list;
		z.traverse(list);
		break;
      case 7:
		cout<<"list:";
		cin>>list;
		z.printreverse(list);
		break;
      case 8:
		cout<<z.count();
      }
  cout<<"c = countinue else = exit ";
  cin>>ch;
  }while(ch=='c'||ch=='C');
}