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
    int maxHeightAfterRemoval[100001];
    int currentMaxHeight = 0;

    vector<int> treeQueries(TreeNode *root, vector<int> &queries)
    {
        traverseLeftToRight(root, 0);
        currentMaxHeight = 0;
        traverseRightToLeft(root, 0);

        int n = queries.size();
        vector<int> queryResults(n);
        for (int i = 0; i < n; i++)
            queryResults[i] = maxHeightAfterRemoval[queries[i]];

        return queryResults;
    }
    void traverseLeftToRight(TreeNode *node, int currentHeight)
    {
        if (!node)
            return;

        maxHeightAfterRemoval[node->val] = currentMaxHeight;

        currentMaxHeight = max(currentMaxHeight, currentHeight);

        traverseLeftToRight(node->left, currentHeight + 1);
        traverseLeftToRight(node->right, currentHeight + 1);
    }

    void traverseRightToLeft(TreeNode *node, int currentHeight)
    {
        if (!node)
            return;

        maxHeightAfterRemoval[node->val] = max(maxHeightAfterRemoval[node->val], currentMaxHeight);

        currentMaxHeight = max(currentHeight, currentMaxHeight);

        traverseRightToLeft(node->right, currentHeight + 1);
        traverseRightToLeft(node->left, currentHeight + 1);
    }
};