#include<bits/stdc++.h>
using namespace std;
int fact(int f)
{
    if(f <= 1)
        return f;
    return f * fact(f-1);
}
int main()
{
    int n = 3;
    int x;
    cin >> x;
    if(n == 1)
        cout << 1 << "\n";
    long long int sum = 1;
    long long int oSum = 0, eSum = 0;
    for(int i = 1; i < n; i++)
    {
        if(i % 2 != 0)
        {
            oSum += -((x * pow(2, i)) / fact(i * 2));
        }
        else
            eSum += ((x * pow(2, i)) / fact(i * 2));
    }
    sum = oSum + eSum;
    cout << sum << "\n";
}
