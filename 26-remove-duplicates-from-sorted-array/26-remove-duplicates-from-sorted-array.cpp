class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        //T.C & S.C-> O(n log n) & O(n)
        set<int> set;
        
        for(int i = 0; i < nums.size(); i++)
            set.insert(nums[i]);
        
        int j = 0;
        int k = set.size();
        for(int x : set)
            nums[j++] = x;
        
        return k;
        
        /*
        int i = 0, j = 1;
        int n = nums.size();
        
        while(j < n)
        {
            if(nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
            j++;
        }
        return i+1;
        */
    }
};