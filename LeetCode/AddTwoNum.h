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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int total = 0;
        ListNode* head = new ListNode(0), *current=head;
        while (l1 || l2)
        {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            total += val1 + val2;
            current->next = new ListNode(total % 10);
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
            total /= 10;
            current = current->next;
        }
        if(total) {
            current->next = new ListNode(total);
        }
        current = head->next;
        delete head;
        return current;
    }
};

