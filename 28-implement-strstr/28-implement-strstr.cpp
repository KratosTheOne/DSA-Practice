class Solution {
public: 
    int strStr(string haystack, string needle) {
        
        int lenHaystack = haystack.length();
        int lenNeedle = needle.length();
        int flag;
        
        for(int i = 0; i < lenHaystack; i++)
        {
            if(haystack[i] == needle[0])
            {
                flag = 0;
                
                for(int j = 0; j < lenNeedle; j++)
                {
                    if(haystack[i + j] != needle[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)
                    return i;
            }
        }
        
        return -1;
    }
};