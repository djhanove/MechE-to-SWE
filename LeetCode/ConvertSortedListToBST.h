/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> temp;
        while(head) {
            temp.push_back(head->val);
            head = head->next;
        }
        
        return recursiveConstruction(temp, 0, temp.size()-1);
        
    }
    
    TreeNode* recursiveConstruction(const vector<int> &nums, const int &low, const int &high) {
        if(low > high)
            return nullptr;
        int mid = low + (high - low) / 2;
        TreeNode* head = new TreeNode(nums[mid]);
        
        head->right = recursiveConstruction(nums, mid+1, high);
        head->left = recursiveConstruction(nums, low, mid-1);
        return head;
    }
    
    TreeNode *sortedListToBST(ListNode *head) {
        if(!head) return NULL;
        if(!head->next) return new TreeNode(head->val);

        // fast/slow pointer to find the midpoint
        auto slow = head;
        auto fast = head;
        auto pre = head;
        while(fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = 0; // break two halves 

        // slow is the midpoint, use as root
        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};
