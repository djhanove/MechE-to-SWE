/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> s;
        if(!headA || !headB)
            return nullptr;
        
        while(headA && headB) {
            if(s.count(headA) == 0)
                s.insert(headA);
            else
                return headA;
            if(s.count(headB) == 0)
                s.insert(headB);
            else
                return headB;
            
            headA = headA->next;
            headB = headB->next;
        }
        
        while(headA){
            if(s.count(headA) == 0)
                s.insert(headA);
            else
                return headA;
            headA = headA->next;
        }
        
        while(headB){
            if(s.count(headB) == 0)
                s.insert(headB);
            else
                return headB;
            headB = headB->next;
        }
        
        return nullptr;
        
    }
};
