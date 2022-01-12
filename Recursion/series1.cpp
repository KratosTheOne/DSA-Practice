#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 10;
    int deno = 0;
    int nume = 1;
    for(int i = 1; i <= n; i++)
    {
        deno = pow(2, i);
        cout << nume << '/' << deno << " ";
        if(i != n)
            cout << '+' << " ";
    }
    return 0;
}
