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
    vector<int> postorder(Node* root) {
        if(!root)
            return vector<int>();
        vector<int> result;
        traverse(root, result);
        return result;
    }
    
    void traverse(const Node* root, vector<int> &nums) {
        if(!root)
            return;
        for(const auto child : root->children) {
            traverse(child, nums);
        }
        nums.push_back(root->val);
    }
};
