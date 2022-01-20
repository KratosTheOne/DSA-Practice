/*
Count the number of distinct elements in every window of size k
windows in a array of size k => n - k + 1
*/
#include<bits/stdc++.h>
using namespace std;
void countdistinct(int a[], int n, int k)
{
    unordered_map<int, int> freq;
    for(int i = 0; i < k; i++)
    {
        freq[a[i]]++;
    }
    cout << freq.size() << " ";
    for(int i = k; i < n; i++)
    {
        freq[a[i - k]]--;
        if(freq[a[i - k]] == 0)
            freq.erase(a[i - k]);
        freq[a[i]]++;
        cout << freq.size() << " ";
    }
    cout << "\n";
}
int main()
{
    int a[] = {10, 20, 20, 10, 30, 40, 10};
    int n = sizeof(a) / sizeof(int);
    int k = 4;
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    cout << k << "\n";
    countdistinct(a, n, k);
    return 0;
}
