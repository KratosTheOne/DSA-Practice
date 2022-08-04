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
        //T.C & S.C -> O(n) & O(1)
        if(head == NULL)
            return false;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast -> next != NULL && fast -> next -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            
            if(slow == fast)
                return true;
        }
        
        return false;
        
        /*
        //T.C & S.C -> O(n) & O(n)
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
        */
    }
};