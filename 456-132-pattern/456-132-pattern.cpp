class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int sMax = INT_MIN;
        int n = nums.size();
        stack<int> s;
        
        for(int i = n - 1; i >= 0; i--)
        {
            while(!s.empty() && nums[i] > s.top())
            {
                sMax= max(sMax, s.top());
                s.pop();
            }
            s.push(nums[i]);
            
            if(nums[i] < sMax && !s.empty())
                return true;
        }
        return false;
    }
};