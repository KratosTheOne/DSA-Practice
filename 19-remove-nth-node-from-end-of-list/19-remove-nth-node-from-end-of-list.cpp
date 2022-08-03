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
        //One Traversal T.C -> O(n)
        
        ListNode *start = new ListNode();
        start -> next = head;
        
        ListNode *slow = start;
        ListNode *fast = start;
        
        for(int i = 1; i <= n; i++)
            fast = fast -> next;
        
        while(fast -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
        
        slow -> next = slow -> next -> next;
        
        return start -> next;
        
        
        /*
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
        */
        
    }
};