#include<iostream>
#include<queue>
#include<conio.h>
using namespace std;
int main()
{
    int arr[5]={1,3,5,7,8};
    priority_queue<int>pq;
    cout<<"the array elements are:";
    for(int i=0;i<=5;i++)
    {
        cout<<arr[i]<<" ";

    }
    cout<<"\n";
    for(int i=0;i<=5;i++)
    {
        pq.push(arr[i]);
    }
    cout<<"priority queue elements:";
    while(!pq.empty())
    {
        cout<<pq.top()<<"";
        pq.pop();
    }
    getch();
    return 0;
}
