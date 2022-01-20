/*
Given an array of integers find the length of the longest consecutive subsequence.
Longest consecutive subsequence is the number of elements in contiguous order.
Like 1, 2, 3, 4, they may however appear in any order.
*/

#include<bits/stdc++.h>
using namespace std;
bool subarray0Sum(int a[], int n)
{
    int prefix_sum = 0;
    unordered_set<int> s;
    for(int i = 0; i < n; i++)
    {
        prefix_sum += a[i];
        if(s.find(prefix_sum) != s.end())
        {
            return true;
        }
        if(prefix_sum == 0)
        {
            return true;
        }
        s.insert(prefix_sum);
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        subarray0Sum(a, n) ? cout << "Yes" : cout << "No";
        cout << "\n";
    }
}
/*
4
6
1 4 13 -3 -10 5
5
1 4 -3 1 2
5
3 -1 -2 5 6
4
5 6 0 8
*/


