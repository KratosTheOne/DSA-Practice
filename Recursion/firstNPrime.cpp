#include<bits/stdc++.h>
using namespace std;
int CheckPrime(int i, int n)
{
    if(n == i)
        return 0;
    else
        if(n % i == 0)
            return 1;
    else
        return CheckPrime(i+1, n);
}
int main()
{
    int n = 20;
    for(int i = 2; i <= n; i++)
    {
        if(CheckPrime(2, i) == 0)
            cout << i << " ";
    }
}
