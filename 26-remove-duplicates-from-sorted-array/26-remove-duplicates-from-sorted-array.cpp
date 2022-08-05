class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //T.C & S.C -> O(n) & O(1)
        if(nums.size() == 0)
            return 0;
        
        int i = 0;
        
        for(int j = 1; j < nums.size(); j++)
        {
            if(nums[j] != nums[i])
            {
                i++;
                nums[i] = nums[j];
            }
        }
        
        return i + 1;
        
        /*
        //T.C & S.C-> O(n log n) & O(n)
        set<int> set;
        
        for(int i = 0; i < nums.size(); i++)
            set.insert(nums[i]);
        
        int j = 0;
        int k = set.size();
        for(int x : set)
            nums[j++] = x;
        
        return k;
        */
    }
};