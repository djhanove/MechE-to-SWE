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
    bool isValidBSTRecursion(TreeNode* root) {
        return bstUtil(root, LONG_MIN, LONG_MAX);
            
    }
    bool bstUtil(TreeNode* root, long min, long max)
    {
        if(!root)
            return true;
        if(root->val <= min || root->val >= max)
            return false;
        return bstUtil(root->left, min, root->val) &&
            bstUtil(root->right, root->val, max);
    }
    
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return validate(root, prev);    
    }
    
    bool validate(TreeNode* root, TreeNode* &prev) {
        /*
        If we use in-order traversal to serialize a binary search tree, we can
        get a list of values in ascending order. It can be proved with the
        definition of BST. And here I use the reference of TreeNode
        pointer prev as a global variable to mark the address of previous node in the
        list.
        */
        if (root == NULL) return true;
        if (!validate(root->left, prev)) return false;
        if (prev != NULL && prev->val >= root->val) return false;
        prev = root;
        return validate(root->right, prev);
        
    }    
    
    
};
