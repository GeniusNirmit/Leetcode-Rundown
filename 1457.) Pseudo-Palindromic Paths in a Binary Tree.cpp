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
    int pseudoPalindromicPaths(TreeNode *root)
    {
        vector<int> mp(10, 0);
        int counter = 0;
        mp[root->val]++;
        traverse(root, mp, counter);
        return counter;
    }
    void traverse(TreeNode *root, vector<int> &mp, int &counter)
    {
        int odd = false;
        if (!root->left && !root->right)
        {
            for (int i = 0; i <= 9; i++)
            {
                if (odd && mp[i] % 2 == 1)
                    return;
                else if (mp[i] % 2 == 1)
                    odd = true;
            }
            counter++;
        }

        if (root->left)
        {
            mp[root->left->val]++;
            traverse(root->left, mp, counter);
            mp[root->left->val]--;
        }

        if (root->right)
        {
            mp[root->right->val]++;
            traverse(root->right, mp, counter);
            mp[root->right->val]--;
        }
    }
};