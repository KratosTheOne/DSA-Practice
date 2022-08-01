// T.C & S.C -> O(3 * n) & O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size(), k, l;

        //iterate from the back and find the first index lesser than its right element i.e index1
        for(k = n - 2; k >= 0; k--)
        {
            if(nums[k] < nums[k + 1])
            {
                break;
            }
        }

        //edge case if the array is strictly increasing
        if(k < 0)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            // iterate from the back and find the first index where value is greater than the value of index1;
            for(l = n - 1; l > k; l--)
            {
                if(nums[l] > nums[k])
                {
                    break;
                }
            }
            swap(nums[k], nums[l]);
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};
