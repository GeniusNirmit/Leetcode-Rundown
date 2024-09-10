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
class Solution
{
public:
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *p = head;
        ListNode *q = head->next;

        while (q)
        {
            int gcd = __gcd(p->val, q->val);
            ListNode *temp = new ListNode(gcd);
            p->next = temp;
            temp->next = q;
            p = q;
            q = q->next;
        }

        return head;
    }
};