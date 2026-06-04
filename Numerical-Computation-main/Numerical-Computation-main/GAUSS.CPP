#include<iostream.h>
#include<conio.h>
#include<math.h>
void main()
{
 double a[10][10],x[10],m,k,g;
 int n,i,j,t;
 clrscr();
 for(i=0;i<10;i++) x[i];
 cout<<"input the nomber of matrix :";
 cin>>n;
 cout<<"input matrix A:\n";
// cout.precision(5);
 for(i=0;i<n;i++)
   for(j=0;j<n+1;j++)
	 cin>>a[i][j];
 for(i=0;i<n-1;i++){
     for(j=i+1;j<n;j++)
	 if(fabs(a[i][i])<fabs(a[j][i])){
	     for(t=0;t<=n;t++){
	       k=a[i][t];
	       a[i][t]=a[j][t];
	       a[j][t]=k;
	  }
      }
     for(j=i+1;j<n;j++){
	g=-a[j][i]/a[i][i];
	if(g!=0)
	for(t=i;t<=n;t++){
	    a[j][t]=a[i][t]*g+a[i][t];
     }
   }
 }
 for(j=n-1;j>=0;j--){
  g=a[j][j];
  m=0;
  for(t=j+1;t<n;t++){
	      m=m+a[j][t]*x[t];
  }
  if(g!=0) x[j]=(a[j][n]-m)/g;
 }
 for(i=0;i<n;i++)
  cout<<"x["<<i<<"]="<<x[i]<<"\n";
 getch();
}
