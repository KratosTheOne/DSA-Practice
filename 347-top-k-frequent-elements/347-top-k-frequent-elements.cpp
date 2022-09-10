//T.C & S.C -> O(n)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        
        for(int i : nums)
            mp[i]++;
        
        vector<vector<int>> buckets(nums.size() + 1);
        
        for(auto val : mp)
        {
            buckets[val.second].push_back(val.first);
        }
        
        vector<int> ans;
        
        for(int i = buckets.size() - 1; i >= 0 and ans.size() < k; i--)
        {
            for(auto x : buckets[i])
                ans.push_back(x);
        }
        
        return ans;
    }
};