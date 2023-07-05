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
    void flatten(TreeNode* root) {
        dfs(root);
    }
    TreeNode* dfs(TreeNode* root) {
        if(!root)
            return NULL;
        if(root->left)
        {
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = NULL;
            TreeNode* last = dfs(root->right);
            last->right = temp;
            if(last->right)
                return dfs(root->right);
            return last;
        }
        else
        {
            if(root->right)
                return dfs(root->right);
            return root;
        }
    }
};