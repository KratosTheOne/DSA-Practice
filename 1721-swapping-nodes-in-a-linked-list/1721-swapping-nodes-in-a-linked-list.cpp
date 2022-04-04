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
    ListNode* swapNodes(ListNode* head, int k) {
        
        int c = 0;
        
        ListNode *ptr1 = head, *ptr2 = head;
        
        ListNode* curr = head;
        
        while(curr != NULL)
        {
            c++;
            curr = curr -> next;
        }
        //cout << c;
        int front = k;
        while(--front && ptr1 -> next != NULL)
        {
            ptr1 = ptr1 -> next;
        }
        
        int back = c - k + 1;
        //cout << k << " " << back;
        while(--back && ptr2 -> next != NULL)
        {
            ptr2 = ptr2 -> next;
        }
        
        swap(ptr1 -> val, ptr2 -> val);
        
        return head;
    }
};