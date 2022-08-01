// T.C & S.C -> O(n) & O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum = 0;
        int max_sum = INT_MIN;
        
        for(auto it : nums)
        {
            sum += it;
            max_sum = max(max_sum, sum);
            
            if(sum < 0) sum = 0;
        }
        return max_sum;
    }
};