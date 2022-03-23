class Solution {
public:
    string getSmallestString(int n, int k) {
        string str ="";
        // append all 'a' in the string;
        for(int i = 0; i < n; i++)
        {
            str += 'a';
        }
        // reduce the value of k by n;
        k -= n;
        // iterate from the last to get lexicographically smallest string;
        for(int i = n-1; i >= 0; i--)
        {
            if(k == 0)
                break;
            else if(k > 25)
            {
                str[i] = (char)('a' + 25);
                k -= 25;
            }
            else
            {
                str[i] = (char)('a' + k);
                k = 0;
            }
        }
        return str;
    }
};