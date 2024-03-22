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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *first = list1;
        ListNode *firstPrev = NULL;
        ListNode *second = list2;
        int diff = b - a;

        while (a--)
        {
            firstPrev = first;
            first = first->next;
        }

        firstPrev->next = list2;

        while (diff--)
            first = first->next;

        while (firstPrev->next)
            firstPrev = firstPrev->next;

        firstPrev->next = first->next;
        return list1;
    }
};