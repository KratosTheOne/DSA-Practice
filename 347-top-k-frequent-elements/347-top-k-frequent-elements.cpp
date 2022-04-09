class Solution {
public:
    
    /*
    step 1-> store all the values of nums in hashmap to map them .
    step 2-> create a priority queue and store their corespond value using pair of int, int ;
    step 3-> itrate the queue till k and push the second value of pair in vector ans and return it ;
    */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int, int> mape;
        for(auto it : nums)
            mape[it]++;
        
        priority_queue<pair<int, int>> pq;
        for(auto i : mape)
            pq.push({i.second, i.first});
        
        vector<int> ans;
        while(k--)
        {
            pair<int, int> p = pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
        
        return ans;
    }
};