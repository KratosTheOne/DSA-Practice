#include<bits/stdc++.h>
using namespace std;
void frequencyOfElements(int a[], int n)
{
    unordered_map<int, int> umape;
    for(int i = 0; i < n; i++)
    {
        umape[a[i]]++;
    }
    for(auto it = umape.begin(); it != umape.end(); it++)
    {
        cout << it -> first << " " << it -> second;
        cout << "\n";
    }
}
int main()
{
    int a[] = {10, 5, 20, 5, 10, 5};
    int n = sizeof(a) / sizeof(int);
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    frequencyOfElements(a, n);
    return 0;
}
