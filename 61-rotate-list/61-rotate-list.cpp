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
    //T.C -> O(n) & O(1)
    
    ListNode* rotateRight(ListNode* head, int k) {
        //edge cases
        if(!head || !head -> next || k == 0)
            return head;
        
        //find length
        ListNode* curr = head;
        int len = 1;
        
        while(curr -> next != NULL && ++len)
            curr = curr -> next;
        
        //move to that node
        curr -> next = head;
        k = k % len;
        k = len - k;
        
        while(k--) curr = curr -> next;
        
        //point to head and make connection
        head = curr -> next;
        curr -> next = NULL;
        
        return head;
        
        /*
        //T.C & S.C -> O(n * k) & O(1)
        //Results in tle
        
        if(head == NULL || head -> next == NULL)
            return head;
        
        for(int i = 0; i < k; i++)
        {
            ListNode* temp = head;
            
            while(temp -> next -> next)
                temp = temp -> next;
            
            ListNode* end = temp -> next;
            temp -> next = NULL;
            end -> next = head;
            head = end;
        }
        
        return head;
        */
    }
};