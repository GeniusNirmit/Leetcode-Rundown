/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Approach-1

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA;
        ListNode *q = headB;
        int counter_A= 0 , counter_B = 0;
        while(p)
        {
            counter_A++;
            p = p->next;   
        }
        while(q)
        {
            counter_B++;
            q = q->next;
        }
        if(counter_A > counter_B)
        {
            counter_A -= counter_B;
            while(counter_A--)
                headA = headA->next;
        }
        else
        {
            counter_B -= counter_A;
            while(counter_B--)
                headB = headB->next;
        }
        while(headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};