#include<iostream.h>
#include<conio.h>
#include<math.h>
double F(double x,double y)
{
 return sin(x)+y;
}
void main()
{
 clrscr();
 double x,y,x0,y0,h,k1,k2,k3,k4;
 int m;
 cout<<"input x0,y0,h\n";
 cin>>x0>>y0>>h;
 cout<<"input the number of using this method";
 cin>>m;
 x=x0;
 y=y0;
 for(int i=0;i<m;i++)
 {
  k1=h*F(x,y);
  k2=h*F(x+h/2,y+k1/2);
  k3=h*F(x+h/2,y+k2/2);
  k4=h*F(x+h,y+k3);
  y=y+(k1+2*k2+2*k3+k4)/6;
  x=x+h;
  cout<<"x:  "<<x<<endl;
  cout<<"y:  "<<y<<endl;

 }
 getch();
}