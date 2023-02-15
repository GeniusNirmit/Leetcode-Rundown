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
    int leftHeight(TreeNode* root) {
        int height = 0;
        while(root)
        {
            height++;
            root = root->left;
        }
        return height;
    }
    int rightHeight(TreeNode* root) {
        int height = 0;
        while(root)
        {
            height++;
            root = root->right;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int heightLeft = leftHeight(root);
        int heightRight = rightHeight(root);

        if(heightLeft == heightRight)
            return pow(2, heightLeft) - 1;
        
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};