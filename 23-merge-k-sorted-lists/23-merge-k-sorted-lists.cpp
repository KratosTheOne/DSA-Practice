//T.C & S.C -> O(N * K log K) & O(K)

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
class compare
{
    public:
        bool operator()(ListNode* a, ListNode* b)
        {
            return a -> val > b -> val;
        }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& listArray) {
        
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
    
        int k = listArray.size();

        if(k == 0)
            return NULL;

        for(int i = 0; i < k; i++)
        {
            if(listArray[i] != NULL)
                minHeap.push(listArray[i]);
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!minHeap.empty())
        {
            ListNode* top = minHeap.top();
            minHeap.pop();

            if(top -> next != NULL)
            {
                minHeap.push(top -> next);
            }

            if(head == NULL)
            {
                head = top;
                tail = top;
            }
            else
            {
                tail -> next = top;
                tail = top;
            }
        }

        return head;
    }
};