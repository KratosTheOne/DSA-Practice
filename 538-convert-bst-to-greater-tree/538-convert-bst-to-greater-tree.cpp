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
    void solve(TreeNode *root, int &num)
    {
		// Base Condition
        if(root == NULL)
            return;
		// Solve for RST first.
        solve(root->right, num);
		// Assigning sum of RST to root.
        root->val = num + root->val;
		// Maintaining sum of RST.
        num = root->val;
		// Once done with RST go to LST.
        solve(root->left, num);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        // keeps sum of RightSubTree of current Node.
        int num = 0;
        solve(root, num);
        return root;
    }
};