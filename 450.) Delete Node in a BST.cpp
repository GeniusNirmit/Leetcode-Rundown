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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root; 
        
        if(key < root->val) 
            root->left = deleteNode(root->left, key); 
   	    else if(key > root->val) 
        	root->right = deleteNode(root->right, key); 
        else
        {   
            if(!root->left) 
            { 
            	TreeNode* temp = root->right; 
            	return temp; 
            } 
            else if(!root->right) 
            { 
    		    TreeNode* temp = root->left; 
		        return temp; 
            } 
        
            TreeNode* temp = minValueNode(root->right); 
            root->val = temp->val; 
            root->right = deleteNode(root->right, temp->val);   	
        } 	
        return root; 
    }
    TreeNode* minValueNode(TreeNode* root) { 
        TreeNode* current = root; 
        while(current && current->left) 
        	current = current->left; 
        return current; 
    }
};