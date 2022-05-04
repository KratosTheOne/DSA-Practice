class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // O(N) & O(N)
        // int count = 0;
        // unordered_map<int, int> mape;
        // for(int i = 0; i < nums.size(); i++)
        // {
        //     int temp = k - nums[i];
        //     if(mape[temp] > 0)
        //     {
        //         count++;
        //         mape[temp]--;
        //     }
        //     else
        //         mape[nums[i]]++;
        // }
        // return count;
        
        // O(n log n) & O(1)
        sort(nums.begin(), nums.end());
        int count = 0;
        int i = 0, j = nums.size() - 1;
        
        while(i < j)
        {
            if(nums[i] + nums[j] > k)
            {
                j--;
                continue;
            }
            else if(nums[i] + nums[j] == k)
            {
                count++;
                i++;
                j--;
            }
            else
            {
                i++;
                continue;
            }
        }
        return count;
    }
};