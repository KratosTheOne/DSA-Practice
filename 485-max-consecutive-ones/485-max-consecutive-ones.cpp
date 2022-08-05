class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        //T.C & S.C -> O(n) & O(1)
        
        int cnt = 0;
        int maxi = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1)
                cnt++;
            else
                cnt = 0;
            maxi = max(maxi, cnt);
        }
        
        return maxi;
    }
};