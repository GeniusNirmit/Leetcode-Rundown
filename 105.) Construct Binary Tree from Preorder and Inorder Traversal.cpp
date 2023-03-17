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
    TreeNode* construct(vector<int>& in, int inStart, int inEnd, vector<int>& pre, int preStart, int preEnd, map<int, int>& inMap) {
        if (inStart > inEnd || preStart > preEnd) 
            return NULL;
        TreeNode* root = new TreeNode(pre[preStart]);

        int inRoot = inMap[root -> val];
        int numsLeft = inRoot - inStart;
        root->left = construct(in, inStart, inRoot - 1, pre, preStart + 1, preStart + numsLeft, inMap);
        root->right = construct(in, inRoot + 1, inEnd, pre, preStart + numsLeft + 1, preEnd, inMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        map<int, int> inMap;
        for (int i = 0; i < in.size(); i++) 
            inMap[in[i]] = i;
        return construct(in, 0, in.size() - 1, pre, 0, pre.size() - 1, inMap);
    }
};