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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root)
            return vector<int>();
        vector<int> result;
        traverse(root, result);
        return result;
        
    }
    
    void traverse(TreeNode* root, vector<int>& vec) {
        if(!root)
            return;
        if(root->left) {
            traverse(root->left, vec);
        }
        vec.push_back(root->val);
        if(root->right){
            traverse(root->right, vec);
        }
        
        
    }
        
        
};
