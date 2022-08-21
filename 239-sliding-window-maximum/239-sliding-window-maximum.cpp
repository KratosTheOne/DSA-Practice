class Solution {
public:
    //T.C & S.C -> O(n) & O(n)
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq;
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(!dq.empty() && dq.front() == (i - k)) //condition to remove out of bound elements for every k size window
                dq.pop_front();
            
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            
            dq.push_back(i);
            
            if(i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }
        
        return ans;
    }
};