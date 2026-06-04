#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
class Stack{
  private:
    char* st;
    int size;
    int top;
  public:
    Stack(int=100);
    void push(char);
    char pop();
    int isfull();
    int isempty();
};
Stack::Stack(int s)
{
 size=s;
 top=-1;
 st=new char[size];
}
void Stack::push(char Operator)
{
 if(!isfull())
   st[++top]=Operator;
 else
  {
   clrscr();
   cout<<"eror";
   exit(1);
  }
}
char Stack::pop()
{
 if(!isempty())
  return st[top--];
 else
 {
  clrscr();
  cout<<"eror";
  exit(1);
 }
}
int Stack::isfull()
{
 if(top==size)
   return 1;
 return 0;
}
int Stack::isempty()
{
 if(top==-1)
  return 1;
 return 0;
}
int isp(char x)
{
  switch(x){
      case '!':  return 1;
      case '*':
      case '/':
      case '%':  return 2;
      case '+':
      case '-':  return 3;
      case '<':
      case '>':
      case '<=':
      case '>=': return 4;
      case '==':
      case '!=': return 5;
      case '&&': return 6;
      case '||': return 7;
      case '(':  return 8;
      case '#':  return 9;
      default:  cout<<"eror";
	       exit(1);

      }
return 0;
}
int icp(char x)
{
  switch(x){
      case '(':  return 0;
      case '!':  return 1;
      case '*':
      case '/':
      case '%':  return 2;
      case '+':
      case '-':  return 3;
      case '<':
      case '>':
      case '<=':
      case '>=': return 4;
      case '==':
      case '!=': return 5;
      case '&&': return 6;
      case '||': return 7;
      default:  cout<<"eror";
	       exit(1);

      }
return 0;
}
char* postfix(char expression[])
{
  Stack stack;
  char x,y;
  char postfix[100];
  stack.push('#');
  int i=0,j=0;
  for(x=expression[i];x!='#';x=expression[++i])
  {
    if(isalpha(x))
    {
      postfix[j]=x;
      j++;
    }
    else
	 if(x==')')
	  for(y=stack.pop();y!='(';y=stack.pop())
	  {
	   postfix[j]=y;
	   j++;
	  }
	 else
	 {
	   for(y=stack.pop();isp(y)<=icp(x);y=stack.pop())
	     {
	      postfix[j]=y;
	      j++;
	     }
	  stack.push(y);
	  stack.push(x);
	}
  }
 while(!stack.isempty())
   {
    postfix[j]=stack.pop();
    j++;
   }
 return postfix;
}
void machine(char* post)
{
 char pst[100];
 for(float i=0;post[i]!='#';i++)
       pst[i]=post[i];
 pst[i]='#';
 Stack s;
 char x;
 char op1,op2;
 i=0;
 int j=0;
 for(x=pst[j];x!='#';x=pst[++j])
 {
  if(isalpha(x))
     s.push(x);
  else
  {
   op1=s.pop();
   op2=s.pop();
   switch(x)
   {
   case'*': cout<<"LD     ";
	    if(op2=='t')
	     {
	      cout<<"TEMP";
	      cout<<i-1<<'\n';
	     }
	    else
	      cout<<op2<<'\n';
	    cout<<"ML     ";
	    if(op1=='t')
	     {
	      cout<<"TEMP";
	      cout<<i<<'\n';
	     }
	    else
	      cout<<op1<<'\n';
	    break;
   case'+': cout<<"LD     ";
	    if(op2=='t')
	     {
	      cout<<"TEMP";
	      cout<<i-1<<'\n';
	     }
	    else
	      cout<<op2<<'\n';
	    cout<<"AD     ";
	    if(op1=='t')
	     {
	      cout<<"TEMP";
	      cout<<i<<'\n';
	     }
	    else
	      cout<<op1<<'\n';
	    break;
   case'/': cout<<"LD     ";
	    if(op2=='t')
	     {
	      cout<<"TEMP";
	      cout<<i-1<<'\n';
	     }
	    else
	      cout<<op2<<'\n';
	    cout<<"DV     ";
	    if(op1=='t')
	     {
	      cout<<"TEMP";
	      cout<<i<<'\n';
	     }
	    else
	      cout<<op1<<'\n';
	    break;
   case'-': cout<<"LD     ";
	     if(op2=='t')
	     {
	      cout<<"TEMP";
	      cout<<i-1<<'\n';
	     }
	     else
	      cout<<op2<<'\n';
	    cout<<"SB     ";
	    if(op1=='t')
	     {
	      cout<<"TEMP";
	      cout<<i<<'\n';
	     }
	    else
	      cout<<op1<<'\n';
	    break;
	}//end switch
   i++;
   cout<<"ST     TEMP";
   cout<<i<<'\n';
   s.push('t');
  }//end else
 }//end for
}//end machine
float oper(char c,int op1,int op2)
{
 switch(c)
   {
    case'+': return (op1+op2);
    case'-': return (op1-op2);
    case'*': return (op1*op2);
    case'/': return (op1/op2);
    default:cout<<"illagle operation";
	    exit(1);
   }
}
float evaluation()
{
 Stack s;
 int op1,op2;
 float value;
 char c;
 char* exp;
 cout<<"enter expression for evaluation\n";
 cin>>exp;
 for(int i=0;exp[i]!='\0';i++)
 {
   c=exp[i];
   if(isdigit(c))
       s.push(c);
   else
   {
    op2=s.pop()-48;
    op1=s.pop()-48;
    value=oper(c,op1,op2);
    s.push(value);
   }
 }
 return s.pop();
}
void main()
{
 clrscr();
 cout<<"infix--->postfix:\n";
 gotoxy(15,2);
 cout<<"the last character should be #\n";
 char expression[100];
 cin>>expression;
 char* pos=postfix(expression);
 for(int i=0;pos[i]!='#';i++)
      cout<<pos[i];
 cout<<'\n';
 machine(pos);
 cout<<evaluation();
 getch();
}