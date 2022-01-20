#include<bits/stdc++.h>
using namespace std;
// T.C -> O(N)
void largestSubArraySum(int a[], int n)
{
    int cs = 0;
    int maxSum = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        if(a[i] <= cs + a[i])
            cs += a[i];
        else
            cs = a[i];
        if(cs > maxSum)
            maxSum = cs;
    }
    cout << maxSum << "\n";
}
int main()
{
    int a[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(a) / sizeof(int);
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    largestSubArraySum(a, n);
}

