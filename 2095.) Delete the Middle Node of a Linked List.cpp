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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* p = head;
        ListNode* q = head;
        ListNode* r = NULL;
        if(!p->next)
            return NULL;
        else if(!p->next->next)
        {
            p->next = NULL;
            return head;
        }
        while(q->next)
        {
            r = p;
            p = p->next;
            q = q->next;
            if(q->next)
                q = q->next;
        }
        r->next = p->next;
        return head;
    }
};