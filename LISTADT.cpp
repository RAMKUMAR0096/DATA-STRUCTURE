#include <iostream.h>
#include <conio.h>

int arr[100];
int lin[100];
int size = 4;
int top = -1;
int t = -1;
void insert(int n)
{
    if (top == size)
    {
        cout << "arrray is full" << endl;
    }
    else
    {
        top = top + 1;
        cout << "Inserted" << n << "Into Array List";
        arr[top] = n;
    }
}
void insertt(int n)
{
    if (t == size)
    {
        cout << "arrray is full" << endl;
    }
    else
    {
        t = t + 1;
        cout << "Inserted" << n << "Into Linkedlist List";
        lin[t] = n;
    }
}
void display()
{
    if (top == -1)
    {
        cout << "Array List is empty";
    }
    else
    {
        for (int i = 0; i < top; i++)
        {
            cout << arr[i] << " ";
        }
    }
}
void displayy()
{
    if (t == -1)
    {
        cout << "Linkedlist is empty List is empty";
    }
    else
    {
        for (int i = t; t>i; i--)
        {
            cout << lin[i] << " ";
        }
    }
}
void main()
{

    clrscr();
    insert(10);
    insert(20);
    insert(30);
    display();
    insertt(90);
    insertt(100);
    insertt(110);
    displayy();
    getch();
}