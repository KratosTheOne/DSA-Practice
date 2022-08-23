//T.C && S.C -> O(n) && O(1)

class Solution {
public:
    int myAtoi(string s) {
        
        if(s.length() == 0) return 0;
        int i = 0;
        
        while(i < s.length() && s[i] == ' ')
        {
            i++;
        }
        
        s = s.substr(i);
        
        int sign = +1;
        long ans = 0;
        
        if(s[0] == '-') sign = -1;
        
        int Max = INT_MAX, Min = INT_MIN;
        
        i = (s[0] == '+' || s[0] == '-') ? 1 : 0;
        
        while(i < s.length())
        {
            if(s[i] == ' ' || !isdigit(s[i])) break;
            
            ans = ans * 10 + (s[i] - '0');
            
            if(sign == -1 && -1 * ans < Min) return Min;
            if(sign == 1 && ans > Max) return Max;
            
            i++;
        }
        
        return (int)(sign * ans);
    }
};