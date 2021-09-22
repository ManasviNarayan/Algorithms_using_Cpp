#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int beg, int mid, int end)
{
    int n1 = mid-beg+1;
    int n2 = end-beg;

    int L[n1], M[n2];

    for(int i =0; i<n1; i++)
        L[i] = arr[beg+i];
    for(int j=0; j<n2; j++)
        M[j] = arr[mid + 1 + j];

    int i=0, j=0, k=beg;

    while(i<n1 && j<n2)
    {
        if(L[i]<=M[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int beg, int end)
{
    int mid;
    if(beg<end)
    {
        mid = (beg+(end-1))/2;
        merge_sort(arr,beg,mid);
        merge_sort(arr,mid +1, end);
        merge(arr, beg, mid, end);
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

    merge_sort(a, 0, n-1);

    cout << "Sorted array: " << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}