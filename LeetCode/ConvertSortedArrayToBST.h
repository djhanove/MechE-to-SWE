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
    
    
    
    // If we have a sorted array, we can assume inorder traversal. 
    // Therefore, the mid value of the array has to be the root node.
    // elements to the left of the mid point of the array must be less than the root,
    // elements to the right of the mid point of the array must be greater than the root. 
    // recursively construct the tree using binary search with the appropriate limit,
    // i.e. low, mid-1 for the left side, and mid+1, high for the right side
    // terminate the recursion if low becomes > high
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty())
            return nullptr;
        return recursiveConstruction(nums, 0, nums.size() - 1);
    }
    
    TreeNode* recursiveConstruction(const vector<int> &nums, const int &low, const int &high) {
        if(low > high)
            return nullptr;
        
        int mid = low + (high - low) / 2;
        TreeNode* head = new TreeNode(nums[mid]);
        
        head->right= recursiveConstruction(nums, mid + 1, high);
        
        head->left = recursiveConstruction(nums,low, mid - 1);
        
        return head;
    }
};
