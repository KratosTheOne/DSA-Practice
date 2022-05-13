class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // O(n logn)
        // sort(nums.begin(), nums.end());
        // for(int i = 0; i < nums.size() - 1; i++)
        // {
        //     if(nums[i] == nums[i+1])
        //     {
        //         return true;
        //         break;
        //     }
        // }
        // return false;
        
        // O(n) & O(n)
        unordered_map<int, int> mape;
        for(auto &x : nums)
            mape[x]++;
        
        for(auto &val : mape)
            if(val.second > 1)
            {   
                return true;
                break;
            }
        return false;
    }
};