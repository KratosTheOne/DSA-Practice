#include<bits/stdc++.h>
using namespace std;
void printRepeatingElements(int a[], int n)
{
    unordered_set<int> freq;
    for(int i = 0; i < n; i++)
    {
        if(freq.find(a[i]) == freq.end())
        {
            freq.insert(a[i]);
        }
        else
            cout << a[i] << " ";
    }
    cout << "\n";
}
int main()
{
    int a[] = {10, 8, 10, 7, 7, 6};
    int n = sizeof(a) / sizeof(int);
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    printRepeatingElements(a, n);
}

