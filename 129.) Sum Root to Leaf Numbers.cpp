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
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        int number = 0;
        int sum = 0;
        dfs(root,sum,number);
        return sum;
    }
    void dfs(TreeNode* root, int& sum, int number) {
        if(!root)
            return ;
        number = (number*10) + root->val;
        if(!root->left && !root->right)
        {
            sum += number;
            return ;
        }
        dfs(root->left, sum, number);
        dfs(root->right, sum, number);
    }
};