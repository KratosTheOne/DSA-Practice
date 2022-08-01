// T.C & S.C -> O(n) & O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxPro = 0;
        int mini = INT_MAX;
        
        for(int i = 0; i < prices.size(); i++)
        {
            mini = min(mini, prices[i]);
            maxPro = max(maxPro, prices[i] - mini);
        }
        
        return maxPro;
    }
};