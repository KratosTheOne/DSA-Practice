class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //T.C & S.C -> O(n) & O(1);
        
        int slow = nums[0];
        int fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while(slow != fast);
        
        fast = nums[0];
        
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
        
        /*
        //T.C & S.C -> O(n) & O(n);
        int n = nums.size();
        vector<int> freq(n, 0);
        int ans = 0; 
        
        for(int i = 0; i < n; i++)
        {
            if(freq[nums[i]] == 0)
                freq[nums[i]]++;
            else
                ans = nums[i];
        }
        return ans;
        */
    }
};