class Solution {
public:
    int search(vector<int>& nums, int target) {
        //T.C & S.C -> O(logn) & O(1)
        
        int low = 0, high = nums.size() - 1;
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            
            if(nums[mid] == target)
                return mid;
            
            if(nums[low] <= nums[mid])
            {
                if(target >= nums[low] && target <= nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
            {
                if(target >= nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        
        return -1;
            
        /*
        T.C & S.C -> O(n) & O(1)
        
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
        */
    }
};