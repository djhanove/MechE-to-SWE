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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p && q)
            if(p->val == q->val) // check vals
                return isSameTree(p->left,q->left) && isSameTree(p->right, q->right); // return equality between sides
            else 
                return false;
        else if(!p && !q) // both are null
            return true;
        return false; // only one is null
        
    }
};
