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
    bool isPalindrome(ListNode* head) {
        ListNode *p = head;
        ListNode *q = head;
        while(q)
        {
            p = p->next;
            q = q->next;
            if(q)
                q = q->next;
        }
        ListNode *first = p;
        p = first;
        q = NULL;
        ListNode *r = NULL;
        while(p)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        first = q;
        p = head;
        while(first)
        {
            if(first->val != p->val)
                return false;
            p = p->next;
            first = first->next;
        }
        return true;
    }
};