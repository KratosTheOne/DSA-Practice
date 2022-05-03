class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        vector<int> check(nums.begin(), nums.end());
        sort(check.begin(), check.end());
        
        int n = nums.size(), s = 0, e = n - 1;
        
        while(s < n && nums[s] == check[s])
            s++;
        
        while(e > s && nums[e] == check[e])
            e--;
        
        return (e - s + 1);
    }
};