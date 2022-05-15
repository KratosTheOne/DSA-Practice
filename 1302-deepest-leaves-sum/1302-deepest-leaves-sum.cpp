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
    //Since BFS traverse through the tree level-wise so we store the sum of each level
    //when we reach next level we again initialize the sum and store the sum of that level nodes
    //At the end, for the last level we store sum and return it.  
    int deepestLeavesSum(TreeNode* root) 
    {
        //leave_sum store the sum of each level nodes
        int leave_sum;
        
        //store the nodes of each level for BFS
        queue<TreeNode*> q; 
        
        if(root)
            q.push(root);
        
        //traverse until queue gets empty
        while(!q.empty())
        {
            int size = q.size(); //size store the no. of node on the level
            leave_sum = 0;
            
            //cover each node of the level
            for(int i=0; i<size; i++)
            {
                TreeNode* curr = q.front(); q.pop();
                
                leave_sum += curr->val; //store the node value in the leave_sum
                
                if(curr->left) q.push(curr->left); //if left child exists add it into the queue
                
                if(curr->right) q.push(curr->right); //if right child exists add it into the queue
            }
        }
        return leave_sum;
    }
};