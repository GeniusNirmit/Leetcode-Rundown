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

// Approach - 1

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> listElements;
        ListNode* newHead = new ListNode(0);
        ListNode* it = newHead;
        while(head)
        {
            listElements.push_back(head->val);
            head = head->next;
        }
        swap(listElements[k-1],listElements[listElements.size()-k]);
        for(int i=0;i<listElements.size();i++)
        {
            ListNode* temp = new ListNode(listElements[i]);
            it->next = temp;
            it = it->next;
        }
        return newHead->next;
    }
};