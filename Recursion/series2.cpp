#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 10;
    int deno = 0;
    cout << 1 << " " << '+' << " ";
    for(int i = 1; i <= n; i++)
    {
        deno = pow(2, i);
        cout << deno << " ";
        if(i != n)
            cout << '+' << " ";
    }
    return 0;
}
