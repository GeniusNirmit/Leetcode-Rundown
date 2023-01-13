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
    int diameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        findDiameter(root);
        return diameter;
    }
    int findDiameter(TreeNode* root) {
        if(root)
        {
            int left = findDiameter(root->left);
            int right = findDiameter(root->right);
            diameter = max(diameter, left+right);
            return max(left,right) + 1;
        }
        return 0;
    }
};