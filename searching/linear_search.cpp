#include<bits/stdc++.h>
using namespace std;

int linear_search(int arr[],int n, int x)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==x)
            return(i);
    }
    return(-1);
}


int main()
{
    int n, x;
    cout<<"Enter No. of elements: ";
    cin>> n;

    int arr[n];
    cout<<"Enter elements: "<<endl;
    for(int i=0; i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the no. to search: ";
    cin>>x;

    int ind = linear_search(arr,n, x);
    if(ind == -1)
        cout<<x<<" Not found in array"<<endl;
    else
        cout<<x<<" found at index "<<ind;
}