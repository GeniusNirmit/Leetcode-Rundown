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
    void reorderList(ListNode* head) {
        
        ListNode *p = head;
        ListNode *q = head;
        while(p && p->next)
        {
            q = q->next;
            p = p->next->next;
        }
        ListNode *mid = q;
        
        p = mid;
        q = NULL;
        ListNode *r = NULL;
        while(p)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        
        
        ListNode *first = head;
        ListNode *last = q;
        ListNode *it = head;
        while(last->next)
        {
            first = first->next;
            it->next = last;
            it = it->next;
            last = last->next;
            it->next = first;
            it = it->next;
        }
    }
};