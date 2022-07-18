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
    
    void traversePreOrder(TreeNode * curr, vector<int> &preOrder)
    {
        if(curr == NULL)
            return;
        
        preOrder.push_back(curr -> val);
        traversePreOrder(curr -> left, preOrder);
        traversePreOrder(curr -> right, preOrder);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> preOrder;
        
        traversePreOrder(root, preOrder);
        
        return preOrder;
    }
};