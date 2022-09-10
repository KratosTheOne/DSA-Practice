//T.C & S.C -> O(n log n) & O(n)

#define pp pair<int, int>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        priority_queue<pp, vector<pp>, greater<pp>> minHeap;

        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            minHeap.push({it -> second, it -> first});

            if(minHeap.size() > k)
            {
                minHeap.pop();
            }
        }

        vector<int> ans;

        while(!minHeap.empty())
        {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans;
    }
};
