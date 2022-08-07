class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //T.C & S.C -> O(logn) & O(1)
        
        int low = 0, high = nums.size() - 2;
        
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            
            if(nums[mid] == nums[mid ^ 1])
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        return nums[low];
        
        /*
        //T.C & S.C -> O(n) & O(1)
        int xorr = nums[0];
        
        for(int i = 1; i < nums.size(); i++)
            xorr ^= nums[i];
        
        return xorr;
        */
    }
};