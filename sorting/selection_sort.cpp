#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min_indx = i;
        for(int j=i;j<n;j++)
        {
            if(arr[j]<arr[min_indx])
                min_indx = j;
        }
        int temp = arr[i];
        arr[i] = arr[min_indx];
        arr[min_indx] = temp;
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

    selection_sort(a, n);

    cout<<"Sorted array: "<<endl;
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";

    return 0;
}