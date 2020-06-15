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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)
            return nullptr;
        return traverse(root, val);
    }
    
    TreeNode* traverse(TreeNode* root, const int &val) {
        if(!root)
            return nullptr;
        if(root->val == val)
            return root;
        if(root->val > val)
            return traverse(root->left, val);
        return traverse(root->right, val);
    }
};
