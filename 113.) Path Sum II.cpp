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
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {    
        vector<vector<int>> paths;
        vector<int> path;
        dfs(root, targetSum, path, paths);
        return paths;
    }
    void dfs(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& paths) {
        if(root)
        {
            path.push_back(root->val);
            if(!root->left && !root->right && root->val == targetSum)
                paths.push_back(path);
            targetSum -= root->val;
            dfs(root->left,targetSum, path, paths);
            dfs(root->right,targetSum, path, paths);
            path.pop_back();
        }
    }
};