class Solution {
public:
    
    //T.C & S.C -> O(n) & O(n)
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int> st;
        int n = heights.size();
        int maxA = 0;
        
        for(int i = 0; i <= n; i++)
        {
            while(!st.empty() && (i == n || heights[st.top()] >= heights[i]))
            {
                int height = heights[st.top()];
                st.pop();
                int width;
                
                if(st.empty()) width = i;
                else width = i - st.top() - 1;
                
                maxA = max(maxA, height * width);
            }
            
            st.push(i);
        }
        
        return maxA;
    }
    
    /*
    //T.C -> O(n^2) TLE
    int largestRectangleArea(vector<int>& heights) {
        
        int maxArea = 0;
        
        for(int i = 0; i < heights.size(); i++)
        {
            int minHeight = INT_MAX;
            for(int j = i; j < heights.size(); j++)
            {
                minHeight = min(minHeight, heights[j]);
                maxArea = max(maxArea, minHeight * (j - i + 1));
            }
        }
        
        return maxArea;
    }
    */
};