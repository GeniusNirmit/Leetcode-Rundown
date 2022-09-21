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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *p = list1;
        ListNode *q = list2;
        ListNode *t = NULL;
        ListNode *head = NULL;
        if(!p)
            return list2;
        else if(!q)
            return list1;
        else
        {
            if(list1->val > list2->val)
            {
                t = q;
                head = t;
                q = q->next;
            }
            else
            {
                t = p;
                head = p;
                p = p->next;
            }
            while(p && q)
            {
                if(p->val < q->val)
                {
                    t->next = p;
                    p = p->next;
                }
                else
                {
                    t->next = q;
                    q = q->next;
                }
                t = t->next;
            }
            while(p)
            {
                t->next = p;
                t = t->next;
                p = p->next;
            }
            while(q)
            {
                t->next = q;
                t = t->next;
                q = q->next;
            }
            return head;
        }
    }
};