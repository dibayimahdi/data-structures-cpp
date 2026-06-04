#include<iostream.h>
#include<conio.h>
void main()
{
 int n,m,i,j,k,x,y,l,b,v=0;
 int c[10][10];
 int a[10][10];
 int r[10];
 int av[10]={0,0,0,0,0,0,0,0,0,0} ;
 clrscr();
 cout<<"enter number of process";
 cin>>n;
 cout<<"enter number of resourses";
 cin>>m;
 cout<<"enter claim matrix";
  for(i=1;i<=n;i++)
   for(j=1;j<=m;j++)
   {
     gotoxy(8*j+1,i+4);
     cin>>c[i][j];
   }
 cout<<"enter allocation matrix";
  for(i=1;i<=n;i++)
   for(j=1;j<=m;j++)
   {
     gotoxy(8*j+1,i+5+n);
     cin>>a[i][j];
   }
 cout<<"enter resources matrix";
 for(i=1;i<=m;i++)
   {
    gotoxy(8*i+1,2*n+7);
    cin>>r[i];
   }
 for(i=1;i<=m;i++)
  {
   k=0;
   for(j=1;j<=n;j++)
    k=k+a[j][i];
   av[i]=r[i]-k;
  }
cout<<endl;
k=0;
for(y=1;y<=n;y++){
l=0;
 for(i=1;i<=n;i++){
  k=0;
  b=0;
  for(j=1;j<=m;j++)
  {
     if(a[i][j]==0) b++;
     if(a[i][j]+av[j]>=c[i][j])
	k++;
  }
  if(b==m) continue;
  if(k==m){
    v++;
    cout<<'p'<<i ;
  for(x=1;x<=m;x++){
     c[i][x]=0;
     av[x]=av[x]+a[i][x];
     a[i][x]=0;
     l=1;
   }
  }
  if(l==1) break;
 }
}
if(v==n) cout<<" is one of the safe states";
else cout<<"\n there is not safe state because all processes didn't complete";
getch();
}