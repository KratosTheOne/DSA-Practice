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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //T.C & S.C -> O(2 * m) & O(n)
        if(headA == NULL || headB == NULL)
            return NULL;
        
        ListNode* a = headA;
        ListNode* b = headB;
        
        while(a != b)
        {
            a = (a == NULL) ? headB : a -> next;
            b = (b == NULL) ? headA : b -> next;
        }
        
        return a;
        
        /*
        //T.C & S.C -> O(n + m) & o(n)
        unordered_set<ListNode*> set;
        while(headA)
        {
            set.insert(headA);
            headA = headA -> next;
        }
        while(headB)
        {
            if(set.find(headB) != set.end())
                return headB;
            headB = headB -> next;
        }
        
        return NULL;
        
        // T.C -> O(n * m)
        while(headB)
        {
            ListNode* temp = headA;
            while(temp)
            {
                if(temp == headB)
                    return headB;
                temp = temp -> next;
            }
            headB = headB -> next;
        }
        
        return headB;
        */
    }
};