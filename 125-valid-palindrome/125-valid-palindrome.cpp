class Solution {
public:
    bool isPalindrome(string s) {
        
        int n = s.size();
        vector<char> vec;
        bool flag = false;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        if(n == 1)
            return true;
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9')
                vec.push_back(s[i]);
        }
        
        if(vec.size() == 0)
            return true;
        
        int left = 0, right = vec.size() - 1;
        
        while(left <= right)
        {
            if(vec[left] == vec[right])
            {
                flag = true;
                left++;
                right--;
            }
            else
            {
                flag = false;
                break;
            }
        }
        
        return flag;
    }
};