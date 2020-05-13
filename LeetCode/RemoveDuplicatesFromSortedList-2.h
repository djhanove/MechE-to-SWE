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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        ListNode* current = head;
        ListNode* lastNode = head;
        bool flag = false;
        while(current) {
            
            while(current->next && current->val == current->next->val) {
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
                flag = true;
            }
            if(flag) {
                lastNode->next = current->next;
                if(lastNode == head && lastNode == current) {
                    head = lastNode->next;
                    lastNode = head;
                    delete current;
                    current = lastNode;
                }
                else {
                    delete current;
                    current = lastNode->next;
                }
                flag = false;
            }
            else {
                lastNode = current;
                current = current->next;
            }
        }
        return head;
    }
};
