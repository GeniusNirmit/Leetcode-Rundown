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
    bool isValidBST(TreeNode* root) {
        return valid(root, NULL, NULL);
    }
    bool valid(TreeNode* root, TreeNode* currentLeft, TreeNode* currentRight) {
        if(!root)
            return true;
        if(currentLeft && root->val <= currentLeft->val)
            return false;
        if(currentRight && currentRight->val <= root->val)
            return false;
        return valid(root->left,currentLeft,root) && valid(root->right,root,currentRight);
    }
};