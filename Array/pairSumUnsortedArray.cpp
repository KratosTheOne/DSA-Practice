#include<bits/stdc++.h>
using namespace std;
void pairSum(int a[], int n, int s)
{
    unordered_set<int> umape;
    bool is_sum = false;
    for(int i = 0; i < n; i++)
    {
        int temp = s - a[i];
        if(umape.find(temp) == umape.end())
        {
            umape.insert(a[i]);
        }
        else
            is_sum = true;
    }
    if(is_sum)
        cout << "YES";
    else
        cout << "NO";
    cout << "\n";
}
int main()
{
    int a[] = {10, 8, 10, 7, 7, 6}; // {2, 4, 6, 3} -> NO
    int n = sizeof(a) / sizeof(int);
    int s = 17;
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << s << "\n";
    cout << "\n";
    pairSum(a, n, s);
}


