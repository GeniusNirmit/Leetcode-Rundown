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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *p = head;
        ListNode *q = head;
        int size = 0;
        if(!p)
            return head;
        while(p->next)
        {
            p = p->next;
            size++;
        }
        p->next = head;
        size++;
        k %= size;
        k = size - k - 1;
        while(k--)
            q = q->next;
        p = q->next;
        head = p;
        q->next = NULL;
        return head;
    }
};