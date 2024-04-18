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
class Solution
{
    string smallest;

    void dfs(TreeNode *root, string current)
    {
        if (!root)
            return;

        current = char(root->val + 'a') + current;

        if (!root->left && !root->right)
        {
            if (smallest == "" || smallest > current)
                smallest = current;
        }

        if (root->left)
            dfs(root->left, current);
        if (root->right)
            dfs(root->right, current);
    }

public:
    string smallestFromLeaf(TreeNode *root)
    {
        dfs(root, "");
        return smallest;
    }
};