#include<bits/stdc++.h>
using namespace std;
// T.C -> O(N^2)
void largestSubArraySum(int a[], int n)
{
    // build a prefix array
    int prefix[n] = {0};
    prefix[0] = a[0];
    for(int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + a[i];
    }
    int largest_sum = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            int subArray_sum = i > 0 ? prefix[j] - prefix[i-1] : prefix[j];

            largest_sum = max(largest_sum, subArray_sum);
        }
    }
    cout << largest_sum << "\n";
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
