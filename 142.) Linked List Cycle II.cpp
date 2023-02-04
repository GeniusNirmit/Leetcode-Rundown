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
    ListNode *detectCycle(ListNode *head) {
        ListNode* p = head;
        ListNode* q = head;
        bool isLoop = false;
        while(p && p->next)
        {
            p = p->next->next;
            q = q->next;
            if(p == q)
            {
                isLoop = true;
                break;
            }
        }
        if(!isLoop)
            return NULL;
        p = head;
        while(p != q)
        {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};