#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 10;
    int sum = 0;
    int totalSum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += i;
        totalSum += sum;
    }
    cout << totalSum << "\n";
    return 0;
}

