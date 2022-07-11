class Solution {

    public:
    void findCombinations(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        if(target == 0)
        {
            ans.push_back(ds);
            return;
        }

        for(int i = ind; i < arr.size(); i++)
        {
            // not taking the same elements and index either to make it lexicographicaly small
            if(i > ind && arr[i] == arr[i-1]) continue;
            if(arr[i] > target) break;
            ds.push_back(arr[i]);
            findCombinations(i + 1, target - arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }
    
    public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> ans;
        vector<int> ds;
        
        findCombinations(0, target, candidates, ans, ds);
        
        return ans;
    }
};