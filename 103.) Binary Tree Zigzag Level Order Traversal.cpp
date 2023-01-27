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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> data;
        if(!root)
            return data;
        queue<TreeNode *> q;
        q.push(root);
        bool zigZag = false;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> levelData;
            for(int i=0;i<size;i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                levelData.push_back(temp->val);
            }
            if(zigZag)
                reverse(levelData.begin(),levelData.end());
            data.push_back(levelData);
            zigZag = !zigZag;
        }
        return data;
    }
};