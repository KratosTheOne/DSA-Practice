class Solution {
public:
    string countAndSay(int n) {
        //T.C & S.C -> O(n^2) & O(1)
        
        if(n == 1) return "1";   
        string s = "1";
        for(int i = 2;i <= n; i++)
        {
            string t = "";
            int cnt = 1;
            for(int i = 0; i <s.size(); i++)
            {
                if(s[i] != s[i + 1])
                {
                    t += to_string(cnt);
                    t += s[i];
                    cnt = 1;
                }
                else cnt++;
            }
            s = t;
        }  
        return s;
    }
};