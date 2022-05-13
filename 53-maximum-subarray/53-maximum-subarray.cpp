class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int cs = 0;
        int maxSum = INT_MIN;
        
        for(int i = 0; i < n; i++)
        {
            if(nums[i] <= cs + nums[i])
                cs += nums[i];
            else
                cs = nums[i];
            if(cs > maxSum)
                maxSum = cs;
        }
        return maxSum;
    }
};