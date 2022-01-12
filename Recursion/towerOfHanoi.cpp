#include<bits/stdc++.h>
using namespace std;
void towerOfHanoi(int n, char s, char d, char a)
{
    if(n == 0)
        cout << n;
    else
    {
        towerOfHanoi(n-1, s, a, d);
        cout << "Move disk " << n << " from rod " << s <<
                                " to rod " << d << "\n";
        towerOfHanoi(n-1, a, d, s);
    }
}
int main()
{
    int n = 3;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}
