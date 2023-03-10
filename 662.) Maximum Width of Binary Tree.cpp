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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int width = 0;
        queue<pair<TreeNode* , int>> q;
        q.push({root, 0});
        while(!q.empty())
        {
            int size = q.size();
            int min = q.front().second;
            int first, last;
            for(int i=0;i<size;i++)
            {
                long long currentId = q.front().second - min;
                TreeNode* current = q.front().first;
                q.pop();
                if(i == 0)
                    first = currentId;
                if(i == size-1)
                    last = currentId;
                if(current->left)
                    q.push({current->left, 2*currentId + 1});
                if(current->right)
                    q.push({current->right, 2*currentId + 2});
            }
            width = max(width, last - first + 1);
        }
        return width;
    }
};