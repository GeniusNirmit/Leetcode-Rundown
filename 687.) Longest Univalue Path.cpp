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
    int longestUnivaluePath(TreeNode* root) {
        if(!root)
            return 0;
        int maxCounter = 0;
        int left = longestUnivalue(root->left, root->val, maxCounter);
        int right = longestUnivalue(root->right, root->val, maxCounter);
        maxCounter = max(maxCounter, left + right);
        return maxCounter;
    }
    int longestUnivalue(TreeNode* root, int prev, int& maxCounter) {
        if(!root)
            return 0;
        
        int left = longestUnivalue(root->left, root->val, maxCounter);
        int right = longestUnivalue(root->right, root->val, maxCounter);
        maxCounter = max(maxCounter, left + right);
        
        if(root->val == prev)
            return max(left, right) + 1;
        else
            return 0;
    }
};