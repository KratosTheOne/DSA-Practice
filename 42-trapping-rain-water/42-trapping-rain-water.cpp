class Solution {
public:
    int trap(vector<int>& height) {
        //T.C & S.C -> O(n) & O(1)
        
        int n = height.size();
        int left = 0, right = n - 1;
        int maxWater = 0;
        int maxLeft = 0, maxRight = 0;
        
        while(left <= right)
        {
            if(height[left] <= height[right])
            {
                if(height[left] >= maxLeft)
                    maxLeft = height[left];
                else
                    maxWater += maxLeft - height[left];
                left++;
            }
            else
            {
                if(height[right] >= maxRight)
                    maxRight = height[right];
                else
                    maxWater += maxRight - height[right];
                right--;
            }
        }
        
        return maxWater;
    }
};