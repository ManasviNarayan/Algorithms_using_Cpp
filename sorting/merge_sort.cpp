#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int beg, int mid, int end, int n)
{
    int i=beg, j=mid+1, index=0;
    int temp[n];

    while(i<= mid && j<=end)
    {
        if(arr[i]<arr[j])
        {
            temp[index] = arr[i];
            i = i + 1;
        }
        else
        {
            temp[index]= arr[j];
            j = j + 1;
        }
        index ++;
    }
    
    if(i>mid)
    {
        while(j<=end)
        {
            temp[index]= arr[j];
            index ++;
            j++;
        }
    }
    else
    {
        while(i<=mid)
        {
            temp[index] = arr[i];
            index++;
            i++;
        }
    }

    int k=0;
    while(k<index)
    {
        arr[k] = temp[k];
        k++;
    }
}

void merge_sort(int arr[], int beg, int end, int n)
{
    int mid;
    if(beg<end)
    {
        mid = (beg+end)/2;
        merge_sort(arr,beg,mid, n);
        merge_sort(arr,mid +1, end, n);
        merge(arr, beg, mid, end, n);
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

    merge_sort(a, 0, n+1, n);

    cout << "Sorted array: " << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}