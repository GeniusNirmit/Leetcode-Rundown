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
public:
    string tree2str(TreeNode *root)
    {
        if (!root)
            return "";

        string left = tree2str(root->left);
        string right = tree2str(root->right);
        if (!root->left && !root->right)
            return to_string(root->val);
        if (!root->right)
            return to_string(root->val) + "(" + left + ")";
        return to_string(root->val) + "(" + left + ")(" + right + ")";
    }
};