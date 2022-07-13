class Solution {
public:
    
    void allPermutations2(int index, vector<int> &nums,vector<vector<int>> &ans)
    {
        if(index == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            allPermutations2(index + 1, nums, ans);
            swap(nums[index], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        allPermutations2(0, nums, ans);
        
        return ans;
    }
    
    /*
    void allPermutations(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[])
    {
        if(ds.size() == nums.size())
        {
            ans.push_back(ds);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(!freq[i])
            {
                ds.push_back(nums[i]);
                freq[i] = 1;
                allPermutations(ds, nums, ans, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];
        
        for(int i = 0; i < nums.size(); i++)
            freq[i] = 0;
        
        allPermutations(ds, nums, ans, freq);
        
        return ans;
    }
    */
};