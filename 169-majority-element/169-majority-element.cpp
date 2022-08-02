//T.C & S.C -> O(n) & O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int cnt = 0;
        int candidate = 0;
        
        for(int num : nums)
        {
            if(cnt == 0)
                candidate = num;
            
            if(num == candidate)
                cnt++;
            
            else
                cnt--;
        }
        
        return candidate;
    }
};