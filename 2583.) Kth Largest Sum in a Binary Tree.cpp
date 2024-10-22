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
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        queue<TreeNode *> q;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            long long sum = 0;

            for (int i = 0; i < size; i++)
            {
                TreeNode *current = q.front();
                q.pop();

                sum += current->val;

                if (current->left)
                    q.push(current->left);
                if (current->right)
                    q.push(current->right);
            }

            pq.push(sum);

            if (pq.size() > k)
                pq.pop();
        }

        if (pq.size() < k)
            return -1;
        return pq.top();
    }
};