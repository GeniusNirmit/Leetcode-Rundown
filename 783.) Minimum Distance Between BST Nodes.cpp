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
    int prev = -1;
    int min = INT_MAX;
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return min;
    }
    void dfs(TreeNode* root) {
        if(!root)
            return ;
        dfs(root->left);
        if(prev != -1 && abs(root->val - prev) < min)
            min = abs(root->val - prev);
        prev = root->val;
        dfs(root->right);
    }
};