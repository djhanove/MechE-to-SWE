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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(), *current = head;
        while (l1 && l2) {
            if(l1->val < l2->val) {
                current->next =  new ListNode(l1->val);
                current = current->next;
                l1 = l1->next;
            }
            else {
                current->next =  new ListNode(l2->val);
                current = current->next;
                l2 = l2->next;
            }
        }
        
        while(l1)
        {
            current->next =  new ListNode(l1->val);
            current = current->next;
            l1 = l1->next;
        }
        while (l2) {
            current->next =  new ListNode(l2->val);
            current = current->next;
            l2 = l2->next;
        }
        current = head->next;
        delete head;
        return current;
    }
};
