// Learning Map
// Count the greater elements for element in an array
#include<bits/stdc++.h>
using namespace std;
/*
// T.C -> O(N^2)
void printCount(int a[], int n)
{
    sort(a, a+n);
    for(int i = 0; i < n; i++)
    {
        int counter = 0;
        for(int j = 0; j < n; j++)
        {
            if(j != i && a[j] > a[i])
                counter++;
        }
        cout << counter << " ";
    }
    cout << "\n";
}
*/
// T.C -> O(N * log N)
void printCount(int a[], int n)
{
    map<int, int> mape;
    for(int i = 0; i < n; i++)
    {
        mape[a[i]]++;
    }
    int cum_freq = 0;
    for(auto it = mape.rbegin(); it != mape.rend(); it++)
    {
        int freq = it -> second;
        it -> second = cum_freq;
        cum_freq += freq;
    }
    for(int i = 0; i < n; i++)
    {
        cout << mape[a[i]] << " ";
    }
    cout << "\n";
}
int main()
{
     int a[] = {10, 5, 8, 20, 30, 8};
     int n = sizeof(a) / sizeof(int);
     for(int i = 0; i < n; i++)
     {
         cout << a[i] << " ";
     }
     cout << "\n";
     printCount(a, n);
}
