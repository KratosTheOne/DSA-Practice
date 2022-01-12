#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 10;
    for(int i = 1; i <= n; i++)
    {
        cout << i << '^' << i << " ";
        if(i != n)
            cout << '+' << " ";
    }
    return 0;
}
