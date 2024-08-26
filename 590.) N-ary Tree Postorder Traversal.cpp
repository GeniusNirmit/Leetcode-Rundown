class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    void traverse(Node *root, vector<int> &traversal)
    {
        if (!root)
            return;

        int n = root->children.size();
        for (int i = 0; i < n; i++)
            traverse(root->children[i], traversal);
        traversal.push_back(root->val);
    }
    vector<int> postorder(Node *root)
    {
        vector<int> traversal;
        traverse(root, traversal);
        return traversal;
    }
};