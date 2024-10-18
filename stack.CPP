#include<iostream.h>
#include<conio.h>
#define max 4
int stack[max];
int size=max;
int top=-1;
void push(int n)
{
if(top==size-1)
{
cout<<"stack owerflow"<<endl;
}
else
{
top=top+1;
stack[top]=n;
//cout<<"The new element in stack:"<<n<<endl;
cout<<"Element inserted successfully"<<endl;
}
}
void pop()
{
if(top==-1)
{
cout<<"Stack underflow"<<endl;
}
else
{
cout<<"The poped element is:"<<stack[top]<<endl;
top=top-1;
}
}
void display()
{
if(top>=0)
{
cout<<"The elements of stack are:";
for(int i=top;i>=0;i--)
{
cout<<stack[i]<<" ";
}
cout<<endl;
}
else
{
cout<<"The stack is empty"<<endl;
}
}
int main()
{
clrscr();
int choice,p;
while(1)
{
cout<<"1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice:";
cin>>choice;
switch(choice)
{
case 1:
cout<<"Enter the element to push:";
cin>>p;
push(p);
break;
case 2:
pop();
break;
case 3:
display();
break;
case 4:
cout<<"Exiting...\n";
return 0;
break;
default:
cout<<"Enter the valid choice..please Try again.."<<endl;
}
}
getch();
return 1;
}