/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return NULL;

        unordered_map<Node *, Node *> mp;
        queue<Node *> q;

        q.push(node);
        mp[node] = new Node(node->val);

        while (!q.empty())
        {
            Node *current = q.front();
            q.pop();
            int n = current->neighbors.size();

            for (int i = 0; i < n; i++)
            {
                if (mp.find(current->neighbors[i]) == mp.end())
                {
                    mp[current->neighbors[i]] = new Node(current->neighbors[i]->val);
                    q.push(current->neighbors[i]);
                }
                mp[current]->neighbors.push_back(mp[current->neighbors[i]]);
            }
        }

        return mp[node];
    }
};