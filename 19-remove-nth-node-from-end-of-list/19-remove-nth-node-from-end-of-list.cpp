/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        
        //Two Traversal
        
        if(head == NULL)
            return NULL;
        
        ListNode *dummy = head;
        ListNode *curr = head;
        int sz = 0;
        
        while(curr)
        {
            sz++;
            curr = curr -> next;
        }
        
        sz -= n;
        curr = head;
        
        if(sz == 0)
        {
            head = head -> next;
            return head;
        }
        
        for(int i = 0; i < sz - 1; i++)
        {
            curr = curr -> next;
        }
        
        dummy = curr -> next;
        curr -> next = dummy -> next;
        
        delete(dummy);
        
        return head;
        
        
    }
};