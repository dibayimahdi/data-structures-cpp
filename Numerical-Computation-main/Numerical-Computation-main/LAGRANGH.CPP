#include<iostream.h>
#include<conio.h>
void main()
{
 float *x;
 float *y;
 float z,mulp,mulq,s=0;
 int n;
 cout<<"inputs is x[0]...x[n] and y[0]...y[n] enter n";
 cin>>n;
 cout<<"now enter x[0]...x[n] and y[0]...y[n]\n";
 for(int i=0;i<=n;i++)
  {
   cout<<"x["<<i<<"]:";
   cin>>x[i];
   cout<<"y["<<i<<"]:";
   cin>>y[i];
   cout<<"\n";
  }
 cout<<" you want p(z)for z=?";
 cin>>z;
 for(i=0;i<=n;i++)
 {
  mulp=1;mulq=1;
  for(int j=0;j<=n;j++)
   {
    if(i==j) continue;
    mulp=mulp*(z-x[j]);
    mulq=mulq*(x[i]-x[j]);

   }
  s=s+(mulp/mulq)*y[i];
 }
 cout<<s;
 getch();
}