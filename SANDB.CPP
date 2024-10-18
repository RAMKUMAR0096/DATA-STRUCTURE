#include<iostream.h>
#include<conio.h>
class search
{
    int a[100],i,f,l,n,mid,locn;
    public:
      void getdata(int n);
      void seq(int,int);
      void bin(int,int);
};
void search::getdata(int n)
{
    cout<<"enter the element:";
    for(i=0;i<n;i++)
    {
	cin>>a[i];
    }
}
void search::seq(int k,int n)
{
    i=0;
    while(i<n&&k!=a[i])
    {
	i=i+1;
    }
    locn=i;
    if(k==a[i])
    {
	cout<<k<<"is found in location "<<locn;
    }
    else
    {
	cout<<k<<"is not found";
    }
}
void search::bin(int k,int n)
{
    f=0;
    l=n;
    while(f<=l)
    {
	mid=(f+l)/2;
	if(k>a[mid])
	{
	    f=mid+1;
	}
	else if(k<a[mid])
	{
	    l=mid-1;
	}
	else
	{
	    f=l+1;
	}
	locn=mid;
    }
    if(k==a[mid])
    {
	cout<<k<<"is found in location"<<locn;
    }
    else
    {
	cout<<k<<"is not found";
    }
}
void main()
{
    clrscr();
    int k,n;
    search s;
    cout<<"\t\t\tSEQUENTIAL SEARCH"<<endl;
    cout<<"Enter how many elements:";
    cin>>n;
    s.getdata(n);
    cout<<"Enter the element to search:";
    cin>>k;
    s.seq(k,n);
    cout<<"\t\t\tBINARY SEARCH"<<endl;
    cout<<"Enter how many elements:";
    cin>>n;
    s.getdata(n);
    cout<<"Enter the element to search:";
    cin>>k;
    s.bin(k,n);
    getch();
}