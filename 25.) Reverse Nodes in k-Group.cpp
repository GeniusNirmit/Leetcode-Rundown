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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)
            return NULL;
        ListNode* p = head;
        ListNode* q = head;
        ListNode* r = NULL;
        int counter = 0;
        while(p && counter < k)
        {
            p = p->next;
            counter++;
        }
        if(counter < k)
            return q;
        
        p = NULL;
        q = head;
        while(q && counter--)
        {
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }

        if(r)
            head->next = reverseKGroup(r, k);
        
        return p;
    }
};