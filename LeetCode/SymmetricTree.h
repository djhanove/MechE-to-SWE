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


/*
	Trick here is to add a helper function which checks to make sure that the left subtree of 		the left tree and the right subtree of the right tree have to be the same, the root node 		keys must be identical, and finally the right subtree of the left tree has to be 		equivalent to the left subtree of the right tree
*/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return helper(root->left, root->right);

    }
    
    bool helper(TreeNode* left, TreeNode* right) {
        if(!left && !right)
            return true;
        else if (!left || !right)
            return false;
        else if(left->val != right -> val)
            return false;
        return helper(left->left, right->right) && helper(left->right, right->left);
            
    }
};
