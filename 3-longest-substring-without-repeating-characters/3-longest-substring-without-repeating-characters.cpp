class Solution {
public:
    
    //T.C & S.C -> O(n) & O(n)
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();
        vector<int> mp(256, -1);
        int l = 0, r = 0, len = 0;
        
        while(r < n)
        {
            if(mp[s[r]] != -1)
                l = max(l, mp[s[r]] + 1);
            
            mp[s[r]] = r;
            
            len = max(len, r - l + 1);
            
            r++;
        }
        return len;
            
    }
    /*
    //T.C & S.C -> O(2 * n) & O(n)
    int lengthOfLongestSubstring(string s) {
        
        if(s.size() == 0)
            return 0;
        
        unordered_set<char> set;
        int maxi = INT_MIN;
        int l = 0;
        
        for(int r = 0; r < s.size(); r++)
        {
            if(set.find(s[r]) != set.end())
            {
                while(l < r && set.find(s[r]) != set.end())
                {
                    set.erase(s[l]);
                    l++;
                }
            }
            set.insert(s[r]);
            maxi = max(maxi, r - l + 1);
        }
        
        return maxi;
    }
    */
};