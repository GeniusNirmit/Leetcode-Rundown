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
    vector<int> nextLargerNodes(ListNode* head) {

        ListNode* p = head;
        ListNode* q = NULL;
        ListNode* r = NULL;
        int counter = 0;
        while(p)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
            counter++;
        }
        head = q;

        stack<int> st;
        vector<int> nextGreaterElement(counter,0);
        int i = counter-1;
        while(head)
        {
            while(!st.empty() && head->val>=st.top())
                st.pop();
            if(!st.empty() && head->val<st.top())
                nextGreaterElement[i] = st.top();
            st.push(head->val);
            head = head->next;
            i--;
        }
        return nextGreaterElement;
    }
};