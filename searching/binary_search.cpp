#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int binary_s(int arr[], int beg, int end, int x)
{

    int mid = (beg + end)/2;
    if(end<beg)
        return -1;
    else
    {
        if (arr[mid] == x)
            return mid;

        else if (arr[mid] > x)
            return binary_s(arr, beg, mid - 1, x);

        else
            return binary_s(arr, mid + 1, end, x);
    }
    
}

int main()
{
    int n, x;
    cout << "Enter No. of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    cout << "Enter the no. to search: ";
    cin >> x;

    int ind = binary_s(arr, 0, n-1, x);
    if(ind==-1)
        cout << x << " Not found in array" << endl;
    else
        cout << x << " found at index " << ind;
}