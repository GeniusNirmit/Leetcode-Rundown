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
    int pairSum(ListNode* head) {
        ListNode* reverseHead = NULL;
        ListNode* p = head;
        ListNode* q = head;
        int maxSum = 0;

        while(q && q->next)
        {
            q = q->next;
            p = p->next;
            if(q)
                q = q->next;
        }

        q = NULL;
        ListNode* r = NULL;

        while(p)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }

        reverseHead = q;

        p = head;
        q = reverseHead;

        while(q)
        {
            maxSum = max(maxSum, p->val + q->val);
            p = p->next;
            q = q->next;
        }

        return maxSum;
    }
};