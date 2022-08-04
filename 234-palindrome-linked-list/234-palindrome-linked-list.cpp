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
    //T.C & S.C -> O(n/2) & O(1)
    ListNode* reverse(ListNode* head)
    {
        ListNode *curr = head, *pre = NULL, *nex;
        while(curr)
        {
            nex = curr -> next;
            curr -> next = pre;
            pre = curr;
            curr = nex;
        }
        
        return pre;    
    }
    
    bool isPalindrome(ListNode* head) {
        
        if(head == NULL || head -> next == NULL)
            return true;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast -> next != NULL && fast -> next -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        slow -> next = reverse(slow -> next);
        slow = slow -> next;
        
        while(slow)
        {
            if(head -> val != slow -> val)
                return false;
            
            slow = slow -> next;
            head = head -> next;
        }
        
        return true;
    }
};