/**inition for a binary tree node.
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
    int traverse(TreeNode *root, int &counter)
    {
        if (!root)
            return 0;

        int leftVal = traverse(root->left, counter);
        int rightVal = traverse(root->right, counter);

        counter += abs(leftVal) + abs(rightVal);

        return leftVal + rightVal + root->val - 1;
    }

public:
    int distributeCoins(TreeNode *root)
    {
        int counter = 0;
        traverse(root, counter);

        return counter;
    }
};