/*
Print the key withe max freq and
if there are several such keys then
print the lexicographicaly smallest string
*/

#include<bits/stdc++.h>
using namespace std;
void highestFrequency(vector<string> vec, int n)
{
    unordered_map<string, int> umape;
    for(int i = 0; i < n; i++)
    {
        umape[vec[i]]++;
    }
    int maxFreq = 0;
    string winner;
    for(auto it = umape.begin(); it != umape.end(); it++)
    {
        if(it -> second > maxFreq)
        {
            maxFreq = it -> second;
            winner = it -> first;
        }
        else if(it -> second == maxFreq && it -> first < winner)
        {
            winner = it -> first;
        }
    }
    cout << winner << "\n";
}
int main()
{
    vector<string> vec = {"abc", "xyz", "abc", "pqr"};
    int n = vec.size();
    for(int i = 0; i < n; i++)
    {
        cout << vec[i] << " ";
    }
    cout << "\n";
    highestFrequency(vec, n);
    return 0;
}

