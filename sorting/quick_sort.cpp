#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int beg, int end)
{
    int pivot = arr[end];

    int i = beg-1;
    for(int j=beg;j<end;j++)
    {
        if (arr[j]<=pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp; 
        }
        
    } 
    int temp2 = arr[i+1];
    arr[i+1] = arr[end];
    arr[end] = temp2;

    return i+1;
}


void quick_sort(int arr[], int beg, int end)
{
    if(beg<end)
    {
        int par = partition(arr, beg, end);
        quick_sort(arr, beg, par-1);
        quick_sort(arr, par+1, end);
    }
}

int main()
{
    int n;
    cout << "Enter no of elements: ";
    cin >> n;
    int a[n], i;
    cout << "Enter elements:" << endl;
    for (i = 0; i < n; i++)
        cin >> a[i];

    quick_sort(a, 0, n - 1);

    cout << "Sorted array: " << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}