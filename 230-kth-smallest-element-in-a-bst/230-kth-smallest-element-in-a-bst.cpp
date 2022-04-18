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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> St;
        int count = 0;
        TreeNode *node = root;
        while(not St.empty() || node)
        {
            if(node)
            {
                St.push(node);
                node = node->left;
            }
            else
            {
                node = St.top();
                St.pop();
                if(++count==k) 
                    return node->val;
                node = node->right;
            }
        }
        return INT_MIN;
    }
};