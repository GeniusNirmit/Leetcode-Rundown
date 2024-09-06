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
    ListNode *modifiedList(vector<int> &a, ListNode *head)
    {
        int n = a.size();
        unordered_set<int> st(a.begin(), a.end());
        ListNode *newHead = new ListNode();
        ListNode *p = head;
        ListNode *q = newHead;

        while (p)
        {
            if (st.find(p->val) != st.end())
                p = p->next;
            else
            {
                q->next = p;
                p = p->next;
                q = q->next;
            }
        }

        q->next = NULL;
        return newHead->next;
    }
};