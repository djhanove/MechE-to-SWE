/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)
            return vector<vector<int>>();
        vector<vector<int>> result;
        traverse(root, result, 0);
        return result;
        }
    
    void traverse(const Node* root, vector<vector<int>> &nums, const int &curLevel) {
        if(!root)
            return;
        if(nums.empty() || curLevel > nums.size()-1)
            nums.push_back(vector<int>());
        nums[curLevel].push_back(root->val);
        for(const auto &child : root->children)
            traverse(child, nums, curLevel + 1);
    }
};
