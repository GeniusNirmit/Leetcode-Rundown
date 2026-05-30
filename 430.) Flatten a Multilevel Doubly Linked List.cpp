/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
    Node* flatLL(Node* head) {
        if(head == NULL) {
            return head;
        }

        Node* q = NULL;
        Node* p = head;

        while(p != NULL) {
            Node* nextNode = p->next;
            Node* lastNode = NULL;
            if(p->child != NULL) {
                lastNode = flatLL(p->child);
                p->next = p->child;
                p->child->prev = p;

                p->child = NULL;

                if(nextNode != NULL) {
                    lastNode->next = nextNode;
                    nextNode->prev = lastNode;
                }

                q = lastNode;
            } else {
                q = p;
            }
        
            p = nextNode;
        }

        return q;
    }
public:
    Node* flatten(Node* head) {
        flatLL(head);
        return head;
    }
};