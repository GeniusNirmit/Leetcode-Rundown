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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (!head)
            return NULL;

        ListNode *first = NULL, *last, *firstReverse, *lastReverse = head;

        while (left > 1)
        {
            first = lastReverse;
            lastReverse = lastReverse->next;
            left--;
            right--;
        }

        firstReverse = first;
        last = lastReverse;
        ListNode *p = NULL;
        while (right--)
        {
            p = last->next;
            last->next = firstReverse;
            firstReverse = last;
            last = p;
        }

        if (first)
            first->next = firstReverse;
        else
            head = firstReverse;

        lastReverse->next = last;

        return head;
    }
};