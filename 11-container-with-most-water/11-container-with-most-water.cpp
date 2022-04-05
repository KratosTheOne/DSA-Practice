class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size();
        int maxWater = 0, left = 0, right = n - 1;
        
        while(left < right)
        {
            //water = max(water, currWater);
            //currWater = height * length;
            //height = min(height[left], height[right])
            //length = right - left;
            maxWater = max(maxWater, min(height[left], height[right]) * (right - left));
            
            if(height[left] > height[right])
                right--;
            else
                left++;
        }
        
        return maxWater;
    }
};