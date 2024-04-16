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
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        queue<TreeNode *> q;
        int level = 1;
        q.push(root);

        while (!q.empty() && level < depth)
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                TreeNode *current = q.front();
                q.pop();

                if (level == depth - 1)
                {
                    TreeNode *newLeft = new TreeNode(val);
                    TreeNode *newRight = new TreeNode(val);
                    newLeft->left = current->left;
                    newRight->right = current->right;
                    current->left = newLeft;
                    current->right = newRight;
                }

                if (current->left)
                    q.push(current->left);

                if (current->right)
                    q.push(current->right);
            }
            level++;
        }

        return root;
    }
};