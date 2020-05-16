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
    int sumNumbers(TreeNode* root) {
        if (!root)
            return 0;
        return search(root, 0);
    }
    
    int search(TreeNode* root, int curSum) {
        if(!root)
            return 0;
        
        curSum = curSum*10 + root->val;
        if(!root->left && !root->right)
            return curSum;
        return search(root->left, curSum) + search(root->right, curSum);
        
    }
        
    
    
};
