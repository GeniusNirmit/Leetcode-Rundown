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
    vector<int> largestValues(TreeNode* root) {
        vector<int> maxValues;
        if(!root)
            return maxValues;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            int max = INT_MIN;
            while(size--)
            {
                TreeNode* current = q.front();
                q.pop();
                if(current->left)
                    q.push(current->left);
                if(current->right)
                    q.push(current->right);
                if(current->val > max)
                    max = current->val;
            }
            maxValues.push_back(max);
        }
        return maxValues;
    }
};