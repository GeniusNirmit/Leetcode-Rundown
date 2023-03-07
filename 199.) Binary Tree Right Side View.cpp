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

// Approach-1 Breadth First Search

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;
        if(!root)   
            return rightView;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            int levelRight;
            while(size--)
            {
                auto current = q.front();
                q.pop();
                levelRight = current->val;
                if(current->left)
                    q.push(current->left);
                if(current->right)
                    q.push(current->right);
            }
            rightView.push_back(levelRight);
        }
        return rightView;
    }
};

// Approach-2 Depth First Search

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;
        dfs(root, 0, rightView);
        return rightView;
    }
    void dfs(TreeNode* root, int level, vector<int>& rightView) {
        if(!root)
            return ;
        if(rightView.size() == level)
            rightView.push_back(root->val);
        dfs(root->right, level+1, rightView);
        dfs(root->left, level+1, rightView);
    }
};