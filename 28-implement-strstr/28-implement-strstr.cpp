class Solution {
public: 
    int strStr(string haystack, string needle) {
        if(needle.length() == 0)
            return 0;
        
        int found = haystack.find(needle);
        
        if(found != string::npos)
            return found;
        return -1;
    }
};