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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode* > q;
        vector<int> lastLevel;
        int levelSum = 0;
        q.push(root);

        while(!q.empty())
        {
            lastLevel.clear();
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                lastLevel.push_back(temp->val);
            }
        }

        for(int i=0; i<lastLevel.size(); i++)
            levelSum += lastLevel[i];
        return levelSum;
    }
};