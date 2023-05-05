/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> levelOrder;
        if(!root)
            return levelOrder;
        queue<Node* > q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            vector<int> level;
            while(size--)
            {
                auto current = q.front();
                q.pop();

                for(auto i: current->children)
                    q.push(i);
                
                level.push_back(current->val);
            }
            levelOrder.push_back(level);
        }
        return levelOrder;
    }
};