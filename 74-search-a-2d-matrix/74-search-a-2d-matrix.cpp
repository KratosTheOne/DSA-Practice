//T.C & S.C -> O(n) & O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size(), m = matrix[0].size();
        
        int lo = 0, hi = n * m - 1;
        
        while(lo <= hi)
        {
            int mid = (lo + (hi - lo) / 2);
            
            if(matrix[mid / m][mid % m] == target)
                return true;
            
            if(matrix[mid / m][mid % m] < target)
                lo = mid + 1;
            
            else
                hi = mid - 1;
        }
        return false;
    }
};