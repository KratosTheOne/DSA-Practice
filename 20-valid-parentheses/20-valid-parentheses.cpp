class Solution {
public:
    //T.C & S.C -> O(n) & O(n);
    
    bool check(char a, char b)
    {
        if(a == '(' && b == ')') return true;
        if(a == '{' && b == '}') return true;
        if(a == '[' && b == ']') return true;
        else return false;
    }
    
    bool isValid(string s) {
        
        stack<int> st;
        
        for(int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            
            if(c == '(' || c == '{' || c == '[')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty() || !check(st.top(), s[i]))
                {
                    return false;
                }
                else
                {
                    st.pop();
                }
            }
        }
        
        if(!st.empty())
            return false;
        
        return true;
    }
};