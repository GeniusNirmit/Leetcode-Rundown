/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Depth First Search

class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, bool> visited;
        generateGraph(root, adj);

        return dfs(adj, visited, start);
    }
    void generateGraph(TreeNode* root, unordered_map<int, vector<int>>& adj) {
        if(!root)
            return;
        
        if(root->left)
        {
            adj[root->left->val].push_back(root->val);
            adj[root->val].push_back(root->left->val);
            generateGraph(root->left, adj);
        }

        if(root->right)
        {
            adj[root->right->val].push_back(root->val);
            adj[root->val].push_back(root->right->val);
            generateGraph(root->right, adj);
        }
    }
    int dfs(unordered_map<int, vector<int>>& adj, unordered_map<int, bool>& visited, int current) {
        visited[current] = true;
        int maxTime = 0;
        int adder = 0;

        for(int i=0; i<adj[current].size(); i++)
        {
            if(!visited[adj[current][i]])
            {
                adder = 1;
                maxTime = max(maxTime, dfs(adj, visited, adj[current][i]));
            }
        }

        return maxTime + adder;
    }
};

// Breadth First Search

class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, bool> visited;
        queue<int> q;
        int maxTime = 0;
        generateGraph(root, adj);

        q.push(start);
    
        while(!q.empty())
        {
            int size = q.size();
            maxTime++;
            while(size--)
            {
                int current = q.front();
                visited[current] = true;
                q.pop();

                for(int i=0; i<adj[current].size(); i++)
                {
                    if(!visited[adj[current][i]])
                        q.push(adj[current][i]);
                }
            }
        }

        return maxTime - 1;
    }
    void generateGraph(TreeNode* root, unordered_map<int, vector<int>>& adj) {
        if(!root)
            return;
        
        if(root->left)
        {
            adj[root->left->val].push_back(root->val);
            adj[root->val].push_back(root->left->val);
            generateGraph(root->left, adj);
        }

        if(root->right)
        {
            adj[root->right->val].push_back(root->val);
            adj[root->val].push_back(root->right->val);
            generateGraph(root->right, adj);
        }
    }
};