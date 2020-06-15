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
    TreeNode* increasingBST(TreeNode* root) {
        if(!root)
            return nullptr;
        vector<int> vec;
        traverse(root, vec);
        int i = 1;
        TreeNode* head = new TreeNode(vec[0]);
        TreeNode* cur = head;
        while(i < vec.size()) {
            head->left = nullptr;
            head->right = new TreeNode(vec[i++]);
            head = head->right;
        }
        return cur;
    }
    
    void traverse(TreeNode* root, vector<int>& vec) {
        if(!root)
            return;
        traverse(root->left, vec);
        vec.push_back(root->val);
        traverse(root->right,vec);
    }

};
