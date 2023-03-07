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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(!root)
            return 0;
        queue<TreeNode* > q;
        vector<long long> levelSum;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            long long sum = 0;
            while(size--)
            {
                auto current = q.front();
                sum += current->val;
                q.pop();
                if(current->left)
                    q.push(current->left);
                if(current->right)
                    q.push(current->right);
            }
            cout<<sum<<endl;
            levelSum.push_back(sum);
        }
        sort(levelSum.begin(),levelSum.end());
        if(k > levelSum.size())
            return -1;
        return levelSum[levelSum.size()-k];
    }
};