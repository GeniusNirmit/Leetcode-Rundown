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
    int kthSmallest(TreeNode* root, int k) {
        multiset<int> s;
        inOrder(root,s);
        auto i = s.begin();
        k--;
        while(k--)
            i++;
        return *i;
    }
    void inOrder(TreeNode* root,multiset<int> &s) {
        if(root)
        {
            inOrder(root->left,s);
            s.insert(root->val);
            inOrder(root->right,s);
        }
    }
};