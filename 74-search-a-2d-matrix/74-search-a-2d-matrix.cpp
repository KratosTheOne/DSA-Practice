class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int start = 0;
        int end = m - 1;
        
        while(start < n && end >= 0)
        {
            if(matrix[start][end] == target)
                return true;
            else if(matrix[start][end] < target)
                start++;
            else
                end--;
        }
        return false;
    }
};