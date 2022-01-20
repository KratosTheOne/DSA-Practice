#include<bits/stdc++.h>
using namespace std;
void intersection(int a[], int n, int b[], int m)
{
    unordered_set<int> s;
    for(int i = 0; i < m; i++)
    {
        s.insert(b[i]);
    }
    for(int i = 0; i < n; i++)
    {
        if(s.find(a[i]) != s.end())
        {
            cout << a[i] << " ";
        }
    }
    cout << "\n";
}
int main()
{
    int a[] = {10, 15, 20, 25, 30, 50};
    int b[] = {30, 5, 15, 80};
    int n = sizeof(a) / sizeof(int);
    int m = sizeof(b) / sizeof(int);
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    for(int i = 0; i < m; i++)
    {
        cout << b[i] << " ";
    }
    cout << "\n";
    intersection(a, n, b ,m);
}


