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
    ListNode *findMiddleElement(ListNode *head)
    {
        ListNode *p = head->next;
        ListNode *q = head;

        while (p && p->next)
        {
            q = q->next;
            p = p->next->next;
        }

        return q;
    }
    ListNode *mergeList(ListNode *left, ListNode *right)
    {
        ListNode *temp = new ListNode();
        ListNode *current = temp;

        while (left && right)
        {
            if (left->val <= right->val)
            {
                current->next = left;
                left = left->next;
            }
            else
            {
                current->next = right;
                right = right->next;
            }
            current = current->next;
        }

        if (left)
            current->next = left;
        if (right)
            current->next = right;

        return temp->next;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *mid = findMiddleElement(head);
        ListNode *right = mid->next;
        mid->next = NULL;

        ListNode *leftSorted = sortList(head);
        ListNode *rightSorted = sortList(right);

        return mergeList(leftSorted, rightSorted);
    }
};