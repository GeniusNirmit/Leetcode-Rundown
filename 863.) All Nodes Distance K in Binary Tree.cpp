/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, unordered_set<int>> adj;
        vector<int> targetValues;
        queue<pair<int, int>> q;

        generateGraph(adj, root);
        vector<bool> visited(adj.size() + 1, false);

        q.push({0, target->val});
        visited[target->val] = true;

        while(!q.empty())
        {
            int distance = q.front().first;
            int current = q.front().second;
            q.pop();

            if(distance == k)
                targetValues.push_back(current);
            if(distance > k)
                return targetValues;
            for(auto i:adj[current])
            {
                if(!visited[i])
                {
                    q.push({distance + 1, i});
                    visited[i] = true;
                }
            }
        }
        return targetValues;
    }
    void generateGraph(unordered_map<int, unordered_set<int>>& adj, TreeNode* root) {
        if(!root)
            return;
        if(root->left)
        {
            adj[root->val].insert(root->left->val);
            adj[root->left->val].insert(root->val);
            generateGraph(adj, root->left);
        }
        if(root->right)
        {
            adj[root->val].insert(root->right->val);
            adj[root->right->val].insert(root->val);
            generateGraph(adj, root->right);
        }
    }
};