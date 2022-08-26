class Solution {
public:
    bool isAnagram(string s, string t) {
        //T.C & S.C -> O(n) & O(n)
        
        int n = s.size(), m = t.size();
        
        if(n != m)
            return false;
        
        unordered_map<char, int> mp;
        
        for(int i = 0; i < n; i++)
        {
            mp[s[i]]++;
        }
        
        for(int i = 0; i < m; i++)
        {
            if(mp.find(t[i]) != mp.end())
            {
                mp[t[i]]--;
            }
            if(mp[t[i]] == 0)
            {
                mp.erase(t[i]);
            }
        }
        
        if(mp.size() == 0)
            return true;
        
        return false;
        
        /* T.C & S.C -> O(n logn) & O(1)
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        int n = s.size(), m = t.size();
        
        if(n != m)
            return false;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != t[i])
            {
                return false;
                break;
            }
        }
        
        return true;
        */
    }
};