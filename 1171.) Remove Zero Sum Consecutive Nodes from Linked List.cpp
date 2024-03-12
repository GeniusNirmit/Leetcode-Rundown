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
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        stack<pair<int, ListNode *>> st;
        unordered_set<int> sum;
        ListNode *p = head;

        while (p)
        {
            if (st.empty() && p->val != 0)
            {
                st.push({p->val, p});
                sum.insert(p->val);
            }
            else if (!st.empty())
            {
                int currentSum = st.top().first + p->val;
                if (sum.count(currentSum) || currentSum == 0)
                {
                    while (!st.empty() && st.top().first != currentSum)
                    {
                        sum.erase(st.top().first);
                        st.pop();
                    }
                }
                else
                {
                    st.push({currentSum, p});
                    sum.insert(currentSum);
                }
            }
            p = p->next;
        }

        if (st.empty())
            return NULL;

        ListNode *prev = st.top().second;
        prev->next = NULL;
        st.pop();

        while (!st.empty())
        {
            st.top().second->next = prev;
            prev = st.top().second;
            st.pop();
        }
        return head = prev;
    }
};