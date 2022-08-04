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
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* entry = head;
        
        while(fast -> next && fast -> next -> next)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            
            if(slow == fast)
            {
                while(slow != entry)
                {
                    slow = slow -> next;
                    entry = entry -> next;
                }
                return slow;
            }
        }
        return 0;
         
        /*
        T.C & S.C -> O(n) & O(n)
        
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
        */
    }
};