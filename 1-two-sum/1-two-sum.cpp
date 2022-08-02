//T.C & S.C -> O(n) & O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mape;
        vector<int> res;
        for(int i = 0; i < n; i++)
        {
            int temp = target - nums[i];
            if(mape.find(temp) != mape.end())
            {
                res.push_back(mape[temp]);
                res.push_back(i);
                return res;
            }
            mape[nums[i]] = i;
        }
        return res;
    }
};