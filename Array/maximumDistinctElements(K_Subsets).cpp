#include<bits/stdc++.h>
using namespace std;
void inKSubsets(int a[], int n, int k)
{
    unordered_set<int> ans;
    for(int i = 0; i < n; i++)
    {
        ans.insert(a[i]);
    }
    if(ans.size() >= n / k)
        cout << n / k << "\n";
    else
        cout << ans.size() << "\n";
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
        int k;
        cin >> k;
        inKSubsets(a, n, k);
    }
}
/*
3
6
1 1 2 1 3 1
2
6
1 1 2 1 3 1
3
8
1 1 1 1 1 1 1 1
4
*/
