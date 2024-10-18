#include<iostream.h>
#include<conio.h>
#define max 4
int queue[max];
int size=max;
int top=-1;
int front=0;
void push(int n)
{
if(top==size-1)
{
cout<<"Queue owerflow"<<endl;
}
else
{
top=top+1;
queue[top]=n;
//cout<<"The new element in stack:"<<n<<endl;
cout<<"Element inserted successfully"<<endl;
}
}
void pop()
{
if(top==-1)
{
cout<<"Queue underflow"<<endl;
}
else
{
cout<<"The poped element is:"<<queue[front]<<endl;
for(int j=0;j<size-1;j++)
{
    queue[j]=queue[j+1];
}
top--;
}
}
void display()
{
if(top>=0)
{
cout<<"The elements of queue are:";
for(int i=front;top>=i;i++)
{
cout<<queue[i]<<" ";
}
cout<<endl;
}
else
{
cout<<"The queue is empty"<<endl;
}
}
int main()
{
clrscr();
int choice,p;
cout<<"\t\t---------queue--------\t\t"<<endl;
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