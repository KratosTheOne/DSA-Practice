class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        int start = 0, curr_petrol = 0, prev_petrol = 0;
        
        for(int i = 0; i < n; i++)
        {
            curr_petrol += (gas[i] - cost[i]);
            if(curr_petrol < 0)
            {
                start = i + 1;
                prev_petrol += curr_petrol;
                curr_petrol = 0;
            }
        }
        return ((curr_petrol + prev_petrol >= 0) ? (start) : -1);
    }
};