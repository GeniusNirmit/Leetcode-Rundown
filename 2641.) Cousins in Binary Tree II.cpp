class Solution
{
public:
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        if (!root)
            return root;

        queue<TreeNode *> q;
        q.push(root);
        int prevSum = root->val;

        while (!q.empty())
        {
            int n = q.size();
            int currentSum = 0;

            for (int i = 0; i < n; i++)
            {
                TreeNode *current = q.front();
                q.pop();
                current->val = prevSum - current->val;

                int nextSum = 0;

                if (current->left)
                    nextSum += current->left->val;
                if (current->right)
                    nextSum += current->right->val;

                if (current->left)
                {
                    currentSum += current->left->val;
                    current->left->val = nextSum;
                    q.push(current->left);
                }
                if (current->right)
                {
                    currentSum += current->right->val;
                    current->right->val = nextSum;
                    q.push(current->right);
                }
            }

            prevSum = currentSum;
        }
        return root;
    }
};