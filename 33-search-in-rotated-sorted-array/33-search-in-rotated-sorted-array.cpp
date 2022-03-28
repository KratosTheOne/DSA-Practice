class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), indi = 0;
        bool flag = false;
        
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == target)
            {
                flag = true;
                indi = i;
                break;
            }
        }
        
        return ((flag) ? (indi) : -1);
    }
};