/*
Given an array of integers find the length of the longest consecutive subsequence.
Longest consecutive subsequence is the number of elements in contiguous order.
Like 1, 2, 3, 4, they may however appear in any order.
*/

#include<bits/stdc++.h>
using namespace std;
void longestConsecutiveSubsequence(int a[], int n)
{
    // Approach 1 Sorting -> O(n log n)
    /*
    sort(a, a+n);
    int res = 1, curr = 1;
    for(int i = 1; i < n; i++)
    {
        if(a[i] == a[i-1] + 1)
            curr++;
        else
        {
            res = max(res, curr);
            curr = 1;
        }
    }
    res = max(res, curr); // edge case 1,2,3,4,5
    cout << res << "\n";
    */
    // Approach 2 Hashing -> O(n)
    int res = 0;
    unordered_set<int> s;
    for(int i = 0; i < n; i++)
    {
        s.insert(a[i]);
    }
    for(int i = 0; i < n; i++)
    {
        if(s.find(a[i] - 1) == s.end())
        {
            int curr = 1;
            while(s.find(a[i] + curr) != s.end())
            {
                curr++;
            }
            res = max(res, curr);
        }
    }
    cout << res << "\n";
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
        longestConsecutiveSubsequence(a, n);
    }
}
/*
3
6
1 9 3 4 2 20
4
8 20 7 30
3
20 30 40
*/

