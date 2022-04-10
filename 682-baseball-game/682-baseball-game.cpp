class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> res;
        int sum = 0;
        
        for(auto& it : ops)
        {
            if(it == "C")
                res.pop();
            
            else if(it == "D")
            {
                int top = res.top();
                res.push(top * 2);
            }
            
            else if(it == "+")
            {
                int first = res.top();
                res.pop();
                int second = res.top();
                res.push(first);
                res.push(first + second);
            }
            
            else
            {
                res.push(stoi(it));
            }
            
        }
        
        while(!res.empty())
        {
            sum += res.top();
            res.pop();
        }
        
        return sum;
    }
};