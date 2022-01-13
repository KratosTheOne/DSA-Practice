#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 2;
    int nume = 1;
    int deno = 0;
    double sum = 0;
    for(int i = 0; i < n; i++)
    {
        deno = pow(2, i);
        sum += (double)nume/(double)deno;
    }
    cout << sum << "\n";
    return 0;
}
