#include<iostream.h>
#include<conio.h>
void main()
{
 float x[20];
 float y[20];
 float a0,a1,sx=0,sx2=0,sy=0,sxy=0,m;
 clrscr();
 cout<<"INPUT m";
 cin>>m;
  for(int i=0;i<m;i++)
 {
  cout<<'x'<<i<<':';
  cin>>x[i];
  cout<<'\n';
  cout<<'y'<<i<<':';
  cin>>y[i];
  cout<<'\n';
 }
 for(i=0;i<m;i++)
 {
  sx=sx+x[i];
  sy=sy+y[i];
  sxy=sxy+(x[i]*y[i]);
  sx2=sx2+(x[i]*x[i]);
 }
 a0=(sy*sx2-sx*sxy)/(m*sx2-sx*sx);
 a1=(m*sxy-sx*sy)/(m*sx2-sx*sx);
 cout<<"y="<<a1<<"x+"<<a0;
 getch();
}