#include<bits/stdc++.h>
using namespace std;
void reverseArray(int a[], int n)
{
    int start = 0;
    int end = n-1;
    while(start < end)
    {
        swap(a[start], a[end]);
        start++;
        end--;
    }
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int a[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n = sizeof(a) / sizeof(int);
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    reverseArray(a, n);
}
