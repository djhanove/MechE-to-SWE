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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode* current = head;
        while(current) {
            s.push(current->val);
            current = current->next;
        }
        
        current = head;
        while(!s.empty()) {
            int stackVal = s.top();
            if(stackVal != current->val)
                return false;
            s.pop();
            current = current->next;
        }
        
        return true;
            
        
    }
};
