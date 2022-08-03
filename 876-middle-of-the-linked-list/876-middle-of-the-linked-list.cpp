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
    
    //T.C -> O(n)
    ListNode* middleNode(ListNode* head) {
        
        ListNode* tortoise = head;
        ListNode* hare = head;
        
        while(hare != NULL and hare -> next != NULL)
        {
            tortoise = tortoise -> next;
            hare = hare -> next -> next;
        }
        
        return tortoise;
        
        /*
        //T.C -> O(n)
        ListNode* temp = head;
        int n = 0;
        
        while(temp)
        {
            n++;
            temp = temp -> next;
        }
        
        temp = head;
        
        for(int i = 0; i < n / 2; i++)
            temp = temp -> next;
        
        return temp;
        */
    }
};