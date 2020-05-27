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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)
            return vector<int>();
        vector<int> result;
        traverse(root, result);
        return result;
    }
    
    void traverse(TreeNode* root, vector<int> &nums) {
        if(!root)
            return;
        nums.push_back(root->val);
        traverse(root->left, nums);
        traverse(root->right, nums);
        
        
    }
};
