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
    int maxLevelSum(TreeNode* root) {
        int level = 0;
        int max = INT_MIN;
        int maxSumLevel = -1;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) 
        {
            int size = q.size();
            level++;
            int sum = 0;
            while(size--)
            {
                TreeNode *current = q.front();
                q.pop();
                sum += current->val;
                if (current->left)
                    q.push(current->left);
                if (current->right)
                    q.push(current->right);
            }
            if (sum > max) {
                max = sum;
                maxSumLevel = level;
            }
        }
        return maxSumLevel;
    }
};