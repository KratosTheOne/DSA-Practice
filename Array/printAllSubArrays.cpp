#include<bits/stdc++.h>
using namespace std;
void printAllPairs(int a[], int n)
{
    int sum = 0, maxSum = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            for(int k = i; k <= j; k++)
            {
                cout << a[k] << " ";
            }
            cout << "\n";
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

