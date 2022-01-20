#include<bits/stdc++.h>
using namespace std;
void printDistinctElements(int a[], int n)
{
    // In any manner
    unordered_set<int> freq;
    for(int i = 0; i < n; i++)
        freq.insert(a[i]);
    for(auto it = freq.begin(); it != freq.end(); it++)
    {
        cout << (*it) << " ";
    }
    cout << "\n";
    // In sorted manner
    unordered_set<int> freq1;
    for(int i = 0; i < n; i++)
    {
        if(freq1.find(a[i]) == freq1.end())
        {
            cout << a[i] << " ";
            freq1.insert(a[i]);
        }
    }
    cout << "\n";
}
int main()
{
    int a[] = {4, 8, 5, 8, 7, 5};
    int n = sizeof(a) / sizeof(int);
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    printDistinctElements(a, n);
}
