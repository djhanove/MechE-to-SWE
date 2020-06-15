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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return vector<int>();
        
        vector<int> result;
        traverse(root, 1, result);
        return result;
    }
    
    void traverse(TreeNode* root, const int level, vector<int> &vec) {
        if(!root)
            return;

        if(vec.size() < level)
            vec.push_back(root->val);
        
        traverse(root->right, level + 1, vec);
        traverse(root->left, level + 1, vec);
    }
    
};
