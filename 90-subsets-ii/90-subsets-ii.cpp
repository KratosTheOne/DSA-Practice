class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        vector<int> ds;
        
        findSubsets(0, nums, ans, ds);
        
        return ans;
    }
    
    void findSubsets(int index, vector<int>& nums, vector<vector<int>> &ans, vector<int> &ds)
    {
        ans.push_back(ds);
        
        for(int i = index; i < nums.size(); i++)
        {
            if(i != index && nums[i] == nums[i-1]) continue;
        
            ds.push_back(nums[i]);
            findSubsets(i + 1, nums, ans, ds);
            ds.pop_back();
            //findSubsets(i + 1, nums, ans, ds);
        }
    }
};