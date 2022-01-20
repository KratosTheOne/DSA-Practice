#include<bits/stdc++.h>
using namespace std;
void printAllPairs(int a[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            cout << a[i] << ',' << a[j] << "\n";
        }
        cout << "\n";
    }
}
int main()
{
    int a[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(a) / sizeof(int);
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    printAllPairs(a, n);
}
