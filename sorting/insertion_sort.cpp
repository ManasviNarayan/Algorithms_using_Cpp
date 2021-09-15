#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n)
{
    for(int i=1; i<=n-1; i++)
    {
        cout<<"i="<<i<<"    ";
        int temp = arr[i];
        int j=i-1; 
        while(temp<=arr[j] && j>=0)
        {
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1] = temp;
        ////////////////////////////
        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }
        cout<<endl;
        ////////////////////////////
    }
    cout<<"Sorted array"<<endl;
    for(int i=0; i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int n;
    cout << "enter no of elements: ";
    cin >> n;
    int a[n], i;
    cout << "Enter elements:" << endl;
    for (i = 0; i < n; i++)
        cin >> a[i];

    insertion_sort(a,n);
    return 0;
}