//T.C & S.C -> O(n ^ 3) & O(1) 

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> res;
        
        if(nums.size() == 0)
        {
            return res;
        }
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                long sum = nums[i] + nums[j];
                long new_target = target - sum;
                int front = j + 1;
                int back = n - 1;
                
                while(front < back)
                {
                    long two_sum = nums[front] + nums[back];
                    
                    if(two_sum < new_target)
                        front++;
                    else if(two_sum > new_target)
                        back--;
                    else
                    {
                        vector<int> quad(4, 0);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[front];
                        quad[3] = nums[back];
                        
                        res.push_back(quad);
                        
                        // check for duplicates of front
                        while(front < back && nums[front] == quad[2]) ++front;
                        
                        // check for duplicates of back
                        while(front < back && nums[back] == quad[3]) --back;
                    }
                }
                // check for duplicates of j
                while(j + 1 < n && nums[j + 1] == nums[j]) ++j;
            }
            // check for duplicates of i
            while(i + 1 < n && nums[i + 1] == nums[i]) ++i;
        }
        return res;
    }
};