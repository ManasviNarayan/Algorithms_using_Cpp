#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {

        for (int j = 0; j < n-1-i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int t;
                t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
        cout<<endl;
    }

    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
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
    
    bubble_sort(a, n);

    return 0;
}