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
    vector<int> inorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> st;
        TreeNode *node = root;
        vector<int> inOrder;
        
        while(true)
        {
            if(node != NULL)
            {
                st.push(node);
                node = node -> left;
            }
            else
            {
                if(st.empty() == true) break;
                node = st.top();
                st.pop();
                
                inOrder.push_back(node -> val);
                
                node = node -> right;
            }
        }
        
        return inOrder;
    }
    
    
    /*
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
    */
};