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
    int maxPathSum(TreeNode* root) {
        int max = INT_MIN;
        maxPathSumFromNode(root,max);
        return max;
    }
    int maxPathSumFromNode(TreeNode* root,int &max) {
        if(!root)
            return 0;
        int leftSum = maxPathSumFromNode(root->left,max);
        if(leftSum < 0)
            leftSum = 0;
        int rightSum = maxPathSumFromNode(root->right,max);
        if(rightSum < 0)
            rightSum = 0;
        if(max < (root->val + leftSum + rightSum))
            max = root->val + leftSum + rightSum;
        if(leftSum > rightSum)
            return root->val + leftSum;
        return root->val + rightSum;
    }
};