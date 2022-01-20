#include<bits/stdc++.h>
using namespace std;
// T.C -> O(N^3)
void largestSubArraySum(int a[], int n)
{
    int largest_sum = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            int subArray_sum = 0;
            for(int k = i; k <= j; k++)
            {
                subArray_sum += a[k];
            }
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
