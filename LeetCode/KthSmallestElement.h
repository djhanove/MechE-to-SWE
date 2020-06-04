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
        if(!root)
            return 0;
        vector<int> vec;
        traverse(vec, root);
        
        return vec[k-1];
        
    }
    
    void traverse(vector<int> &s, TreeNode* root) {
        if(!root)
            return;
        traverse(s, root->left);
        s.push_back(root->val);
        traverse(s,root->right);
    }
};
