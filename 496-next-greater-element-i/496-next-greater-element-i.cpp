class Solution {
public:
    
    //T.C & S.C -> O(n * m) & O(1)
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    bool f=true;
                    for(int k=j;k<nums2.size();k++){
                        if(nums2[j]<nums2[k]){ 
                            ans.push_back(nums2[k]);
                            f=false;
                            break;
                        }
                    }
                    if(f) ans.push_back(-1);
                }
            }
        }
        return ans;
    }
};