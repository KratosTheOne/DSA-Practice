class Solution {
public:
    //T.C & S.C -> O(n) & O(n)
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        stack<int> st;
        unordered_map<int, int> mp;
        for(int n:nums2){
            while(st.size() && st.top()<n){
                mp[st.top()]=n;
                st.pop();
            }
            st.push(n);
        }
        for(int n:nums1) res.push_back(mp.find(n)!=mp.end() ? mp[n] : -1);
        return res;
    }
    
    /*
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
    */
};