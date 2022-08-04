/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        unordered_set<ListNode*> set;
        
        ListNode* dummy = head;
        
        while(dummy)
        {
            if(set.find(dummy) != set.end())
                return true;
            
            set.insert(dummy);
            dummy = dummy -> next;
        }
        
        return false;
    }
};