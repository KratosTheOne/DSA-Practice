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
    ListNode *detectCycle(ListNode *head) {
        
        if(head == NULL)
            return 0;
        
        unordered_set<ListNode*> set;
        ListNode* dummy = head;
        
        while(dummy)
        {
            if(set.find(dummy) != set.end())
                return dummy;
            
            set.insert(dummy);
            dummy = dummy -> next;
        }
        
        return 0;
    }
};