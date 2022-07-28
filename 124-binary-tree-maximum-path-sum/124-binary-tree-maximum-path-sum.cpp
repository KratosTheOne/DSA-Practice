/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int findMeSum(TreeNode* root, int& maxi)
    {
        if(root == NULL)
            return 0;
        
        int lh = max(0, findMeSum(root -> left, maxi));
        int rh = max(0, findMeSum(root -> right, maxi));
        
        maxi = max(maxi, lh + rh + root -> val);
        
        return (root -> val) + max(lh, rh); //this part decides which path(the one yielding max value) to take when on a specific node.
    }
    
    int maxPathSum(TreeNode* root) {
        
        int maxi = INT_MIN;
        
        findMeSum(root, maxi);
        
        return maxi;
    }
};