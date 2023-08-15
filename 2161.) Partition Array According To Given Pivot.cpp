class Solution
{
public:
    vector<int> pivotArray(vector<int> &a, int pivot)
    {
        ListNode *head = new ListNode(a[0]);
        vector<int> updatedArray;

        generateList(a, head);
        head = partition(head, pivot);

        while (head)
        {
            updatedArray.push_back(head->val);
            head = head->next;
        }

        return updatedArray;
    }
    void generateList(vector<int> &a, ListNode *head)
    {
        ListNode *p = head;
        int n = a.size();
        for (int i = 1; i < n; i++)
        {
            p->next = new ListNode(a[i]);
            p = p->next;
        }
    }
    ListNode *partition(ListNode *head, int x)
    {
        if (!head)
            return head;
        ListNode *head1 = new ListNode();
        ListNode *head2 = new ListNode();
        ListNode *head3 = new ListNode();
        ListNode *p = head1;
        ListNode *q = head2;
        ListNode *r = head3;
        ListNode *it = head;

        while (it)
        {
            if (it->val == x)
            {
                r->next = it;
                r = r->next;
            }
            else if (it->val > x)
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
        r->next = NULL;

        p->next = head3->next;
        r->next = head2->next;

        return head1->next;
    }
};