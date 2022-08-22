//T.C & S.C -> O(n ^ 2) & O(1) 

class Solution {
public:
    string longestPalindrome(string s) {
        
        if (s.size() < 1) {
            return "";
        }
        
        int start = 0, end = 0, n = s.length();
        
        for(int i = 0; i < n; i++)
        {
            int odd = expand(s, i, i);
            int even = expand(s, i, i + 1);
            int len = max(odd, even);
            
            if(len > end - start)
            {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        
        return s.substr(start, end - start + 1);
    }
    
    int expand(string s, int left, int right)
    {
        while(left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }
        
        return right - left - 1;
    }
};