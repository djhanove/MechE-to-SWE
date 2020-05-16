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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>> levels;
        vector<double> result;
        traverse(root, levels, 0);
        for(auto c : levels)
            result.push_back(accumulate( c.begin(), c.end(), 0.0)/c.size());
        
        return result;
        
    }
    
    void traverse(TreeNode* root, vector<vector<int>>& vec, int curLevel)
    {
        if(!root)
            return;
        if(vec.empty() || curLevel > vec.size()-1) {
            vec.push_back(vector<int>());
        }
        vec[curLevel].push_back(root->val);
        
        traverse(root->left, vec, curLevel+1);
        traverse(root->right, vec, curLevel+1);
    }
};
