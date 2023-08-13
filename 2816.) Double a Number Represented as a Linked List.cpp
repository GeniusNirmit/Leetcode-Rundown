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
    ListNode *doubleIt(ListNode *head)
    {
        ListNode *head1 = reverse(head);
        ListNode *head2 = head1;
        ListNode *headNode = new ListNode();

        ListNode *p = head1;
        ListNode *q = head2;

        int sum = 0;
        int carry = 0;

        while (p || q)
        {
            if (p)
            {
                sum += p->val;
                p = p->next;
            }
            if (q)
            {
                sum += q->val;
                q = q->next;
            }

            headNode->val = sum % 10;
            carry = sum / 10;
            ListNode *temp = new ListNode(carry);
            temp->next = headNode;
            headNode = temp;
            sum = carry;
        }

        if (!carry)
            return headNode->next;
        return headNode;
    }
    ListNode *reverse(ListNode *head)
    {
        ListNode *p = head;
        ListNode *q = NULL;
        ListNode *r = NULL;

        while (p)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        return q;
    }
};