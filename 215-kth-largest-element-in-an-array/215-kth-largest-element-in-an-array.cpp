class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        
        int ans = nums[k-1];
        
        return ans;
    }
};