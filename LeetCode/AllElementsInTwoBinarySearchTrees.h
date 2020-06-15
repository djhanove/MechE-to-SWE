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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2)
            return vector<int>();
        
        vector<int> tree1;
        vector<int> tree2;
        vector<int> result;
        if(!root1 && root2) {
            traverse(root2, tree2);
            return tree2;
        }
        
        if(root1 && !root2) {
            traverse(root1, tree1);
            return tree1;
        }
        
        traverse(root1, tree1);
        traverse(root2, tree2);
        
        int i = 0;
        int j = 0;
        while(i < tree1.size() && j < tree2.size()) {
            if(tree1[i] > tree2[j]) {
                result.push_back(tree2[j++]);
            }
            else
                result.push_back(tree1[i++]);
        }
        
        while(i < tree1.size())
            result.push_back(tree1[i++]);
        
        while(j < tree2.size())
            result.push_back(tree2[j++]);
        
        return result;
                
            
        
        
    }
    
    void traverse(TreeNode* root, vector<int>& nums) {
        if(!root)
            return;
        traverse(root->left, nums);
        nums.push_back(root->val);
        traverse(root->right, nums);
    }
};
