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
class BSTIterator {
public:
    queue<int> s;
    BSTIterator(TreeNode* root) {
        traverse(root, s);
    }
    
    void traverse(TreeNode* root, queue<int>& s) {
        if(!root)
            return;
        traverse(root->left, s);
        s.push(root->val);
        traverse(root->right, s);
    }
    
    /** @return the next smallest number */
    int next() {
        if(!s.empty()) {
            int val = s.front();
            s.pop();
            return val;
        }
        else
            return -1;
        
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
