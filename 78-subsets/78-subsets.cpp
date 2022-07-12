class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> ds;
        
        findSubsets(0, nums, ans, ds);
        
        return ans;
    }
    
    void findSubsets(int index, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds)
    {
        if(index == nums.size())
        {
            ans.push_back(ds);
            return;
        }
        
        // pick
        ds.push_back(nums[index]);
        findSubsets(index + 1, nums, ans, ds);
        
        ds.pop_back();
        
        // not pick
        findSubsets(index + 1, nums, ans, ds);
    }
};