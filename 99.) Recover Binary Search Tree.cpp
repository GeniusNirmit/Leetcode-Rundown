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
    void recoverTree(TreeNode* root) {
        TreeNode* mistakeOne = NULL; 
        TreeNode* mistakeTwo = NULL;
        TreeNode* prev = NULL;
        dfs(root, prev, mistakeOne, mistakeTwo);
        swap(mistakeOne->val, mistakeTwo->val);
    }
    void dfs(TreeNode* root, TreeNode*& prev, TreeNode*& mistakeOne, TreeNode*& mistakeTwo) {
        if(!root)   
            return;
        if(root->left)
            dfs(root->left, prev, mistakeOne, mistakeTwo);

        if(prev && root->val < prev->val)
        {
            if(!mistakeOne)
                mistakeOne = prev;
            mistakeTwo = root;
        }
        prev = root;

        if(root->right)
            dfs(root->right, prev, mistakeOne, mistakeTwo);
    }
};