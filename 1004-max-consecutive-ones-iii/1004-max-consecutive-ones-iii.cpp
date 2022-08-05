class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //T.C & S.C -> O(n) & O(1)
        
        int i = 0, j = 0, n = nums.size();
        int countZero = 0, maxi = INT_MIN;
        
        while(j < n)
        {
            if(nums[j] == 0)
                countZero++;
            
            while(countZero > k)
            {
                if(nums[i] == 0)
                    countZero--;
                
                i++;
            }
            
            maxi = max(maxi, j - i + 1);
            j++;
        }
        
        return maxi;
    }
};