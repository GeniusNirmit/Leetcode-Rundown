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
    int averageOfSubtree(TreeNode *root)
    {
        int counter = 0;
        calculateAverage(root, counter);
        return counter;
    }
    pair<int, int> calculateAverage(TreeNode *root, int &counter)
    {
        if (!root)
            return {0, 0};

        pair<int, int> leftValue = calculateAverage(root->left, counter);
        pair<int, int> rightValue = calculateAverage(root->right, counter);

        int sum = leftValue.first + rightValue.first + root->val;
        int nodes = leftValue.second + rightValue.second + 1;

        if (sum / nodes == root->val)
            counter++;

        return {sum, nodes};
    }
};