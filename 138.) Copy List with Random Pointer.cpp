/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return NULL;

        Node *p = head;
        while (p)
        {
            Node *temp = new Node(p->val);
            temp->next = p->next;
            p->next = temp;
            p = p->next->next;
        }

        p = head;
        while (p)
        {
            if (p->random)
                p->next->random = p->random->next;
            else
                p->next->random = NULL;
            p = p->next->next;
        }

        p = head;
        Node *q = head->next;
        Node *newHead = head->next;
        while (p)
        {
            p->next = p->next->next;

            if (q->next)
                q->next = q->next->next;
            else
                q->next = NULL;

            q = q->next;
            p = p->next;
        }

        return newHead;
    }
};