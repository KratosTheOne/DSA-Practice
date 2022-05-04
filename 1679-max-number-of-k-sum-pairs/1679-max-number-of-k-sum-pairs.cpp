class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> mape;
        for(int i = 0; i < nums.size(); i++)
        {
            int temp = k - nums[i];
            if(mape[temp] > 0)
            {
                count++;
                mape[temp]--;
            }
            else
                mape[nums[i]]++;
        }
        return count;
    }
};