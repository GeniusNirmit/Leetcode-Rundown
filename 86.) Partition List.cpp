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
    ListNode *partition(ListNode *head, int x)
    {
        if (!head)
            return head;
        ListNode *head1 = new ListNode();
        ListNode *head2 = new ListNode();
        ListNode *p = head1;
        ListNode *q = head2;
        ListNode *it = head;

        while (it)
        {
            if (it->val >= x)
            {
                q->next = it;
                q = q->next;
            }
            else
            {
                p->next = it;
                p = p->next;
            }
            it = it->next;
        }
        p->next = NULL;
        q->next = NULL;

        p->next = head2->next;
        head = head1->next;
        return head;
    }
};