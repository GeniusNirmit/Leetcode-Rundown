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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1 = reverse(l1);
        ListNode* head2 = reverse(l2);
        ListNode* head = new ListNode();

        ListNode* p = head1;
        ListNode* q = head2;
        int carry = 0;
        int sum = 0;

        while(p || q)
        {
            if(p)
            {
                sum += p->val;
                p = p->next;
            }
            if(q)
            {
                sum += q->val;
                q = q->next;
            }

            head->val = sum % 10;
            carry = sum / 10;
            ListNode* temp = new ListNode(carry);
            temp->next = head;
            head = temp;
            sum = carry;
        }

        if(!carry)
            return head->next;
        return head;
    }
    ListNode* reverse(ListNode* head) {
        ListNode* p = head;
        ListNode* q = NULL;
        ListNode* r = NULL;

        while(p)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }

        return q;
    }
};