//T.C && S.C -> O(n) & O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int sz = nums.size();
        int n1 = -1, n2 = -1, c1 = 0, c2 = 0, i;
        
        for(i = 0; i < sz; i++)
        {
            if(n1 == nums[i])
                c1++;
            else if(n2 == nums[i])
                c2++;
            else if(c1 == 0)
            {
                n1 = nums[i];
                c1 = 1;
            }
            else if(c2 == 0)
            {
                n2 = nums[i];
                c2 = 1;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        
        vector<int> ans;
        c1 = 0, c2 = 0;
        
        for(i = 0; i < sz; i++)
        {
            if(nums[i] == n1)
                c1++;
            else if(nums[i] == n2)
                c2++;
        }
        
        if(c1 > sz / 3)
            ans.push_back(n1);
        if(c2 > sz / 3)
            ans.push_back(n2);
        
        return ans;
    }
};