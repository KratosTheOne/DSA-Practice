class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> freq(n, 0);
        int ans = 0; 
        
        for(int i = 0; i < n; i++)
        {
            if(freq[nums[i]] == 0)
                freq[nums[i]]++;
            else
                ans = nums[i];
        }
        return ans;
        
    }
};