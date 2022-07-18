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
    
    void traverseInOrder(TreeNode *curr, vector<int> &inOrder)
    {
        if(curr == NULL)
            return;
        
        traverseInOrder(curr -> left, inOrder);
        inOrder.push_back(curr -> val);
        traverseInOrder(curr -> right, inOrder);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> inOrder;
        
        traverseInOrder(root, inOrder);
        
        return inOrder;
    }
};