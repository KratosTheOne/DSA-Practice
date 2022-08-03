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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //T.C & S.C -> O(n + m) & O (1)
        
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1 -> val > l2 -> val) swap(l1, l2);
        
        ListNode* res = l1;
        
        while(l1 && l2)
        {
            ListNode* temp = NULL;
            
            while(l1 != NULL && l1 -> val <= l2 -> val)
            {
                temp = l1;
                l1 = l1 -> next;
            }
            
            temp -> next = l2;
            swap(l1, l2);
        }
        
        return res;
        
        /*
        T.C & S.C -> O(n + m) & O (n + m) 
        
        ListNode *dummy, *temp;
        dummy = new ListNode();
        temp = dummy;
        
        //when both list1 and list2 isn't empty
        while(list1 && list2){
            if(list1->val < list2->val){
                temp->next = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;   
            }
            temp = temp->next;
        }
        
        // we reached at the end of one of the list
        if(list1) temp->next = list1;
        if(list2) temp->next = list2;
        
        return dummy->next;
        */
    }
};