// T.C & S.C -> O(n * log(n)) & O(n); 

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> mergedIntervals;
        
        if(intervals.size() == 0)
            return mergedIntervals;
        
        sort(intervals.begin(), intervals.end());
        vector<int> tempIntervals = intervals[0]; // put first element to compare
        
        for(auto it : intervals)
        {
            if(it[0] <= tempIntervals[1]) // compare with next element
            {
                tempIntervals[1] = max(tempIntervals[1], it[1]); // merge if pair.second < pair2.first 
            }
            else
            {
                mergedIntervals.push_back(tempIntervals); // not merging means thats a valid pair so pushback in data structure
                tempIntervals = it; // assign it to new valid pair
            }
        }
        mergedIntervals.push_back(tempIntervals);
        return mergedIntervals;
    }
};