//T.C & S.C -> O(n) & O(n)

class Solution {
public:
    string reverseWords(string s) {
        
        string ans = "";
        
        int i = s.length() - 1;
        
        while(i >= 0)
        {
            if(s[i] == ' ') i--;
            else
            {
                if(ans.length() > 0)
                    ans.push_back(' ');
                
                int j = i;
                
                while(j >= 0 && s[j] != ' ')
                    j--;
                
                ans.append(s.substr(j + 1, i - j));
                i = j;
            }
        }
        
        return ans;
    }
};