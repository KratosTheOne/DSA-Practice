class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        vector<int> res;
        vector<pair<int, int>> temp;
        
        for(int i = 0; i < mat.size(); i++)
        {
            int sum = 0;
            for(int j = 0; j < mat[0].size(); j++)
            {
                sum += mat[i][j];
            }
            temp.push_back({i, sum});
        }
        
        sort(temp.begin(), temp.end(), [](pair<int, int> a, pair<int, int> b){
            if(a.second == b.second)
                return a.first < b.first;
            else
                return a.second < b.second;
        });
        
        for(int i = 0; i < k; i++)
        {
            res.push_back(temp[i].first);
        }
        
        return res;
    }
};