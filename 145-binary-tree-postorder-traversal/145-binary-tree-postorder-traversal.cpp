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
    
    void traversePostOrder(TreeNode * curr, vector<int> &postOrder)
    {
        if(curr == NULL)
            return;
        
        traversePostOrder(curr -> left, postOrder);
        traversePostOrder(curr -> right, postOrder);
        postOrder.push_back(curr -> val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> postOrder;
        
        traversePostOrder(root, postOrder);
        
        return postOrder;
    }
};