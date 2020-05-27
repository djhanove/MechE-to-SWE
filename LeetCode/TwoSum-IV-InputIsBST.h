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
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;
        
        vector<int> result;
        traverse(result, root);
        
        for(int i = 0; i < result.size(); i++) {
            int target = k - result[i];
            cout << "result[i] =" << result[i] << endl;
            if(binarySearch(target, result, i+1, result.size()-1))
                return true;
        }
        return false;
    }
    
    void traverse(vector<int> &numbers, const TreeNode* root) {
        if(!root)
            return;
        traverse(numbers, root->left);
        numbers.push_back(root->val);
        traverse(numbers,root->right);
    }
    
    bool binarySearch(const int &target, const vector<int> &numbers, const int &low, const int &high) {
        if(low > high)
            return false;
        int mid = low + (high - low) / 2;
        if(numbers[mid] < target)
            return binarySearch(target, numbers, mid + 1 , high);
        else if (numbers[mid] > target)
            return binarySearch(target,numbers, low, mid-1);
        else
            return true;
    }
    
    
    
    
    


};
