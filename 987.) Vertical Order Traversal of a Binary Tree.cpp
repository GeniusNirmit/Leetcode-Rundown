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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> values;
        queue< pair<TreeNode* ,pair<int,int>>> q;
        vector<vector<int>> verticalData;
        q.push({root, {0,0}});
        while(!q.empty())
        {
            auto current = q.front();
            q.pop();
            TreeNode* currentNode = current.first;
            int x = current.second.first, y = current.second.second;
            values[x][y].insert(currentNode->val);
            if(currentNode->left)
                q.push({ currentNode->left , {x-1, y+1}});
            if(currentNode->right)
                q.push({ currentNode->right, {x+1, y+1}});
        }
        for(auto i:values)
        {
            vector<int> temp;
            for(auto j:i.second)
                temp.insert(temp.end(), j.second.begin(), j.second.end());
            verticalData.push_back(temp);
        }
        return verticalData;
    }
};