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
        
        ListNode* ans = new ListNode();
        ListNode* cur = ans;
        
        int c = 0;
        while(l1 || l2)
        {
            int a = l1 != NULL ? l1 -> val : 0;
            int b = l2 != NULL ? l2 -> val : 0;
            
            int s = a + b + c;
            c = s / 10;
            int r = s % 10;
            
            cur -> next = new ListNode(r);   
            cur = cur -> next;
            
            if(l1) l1 = l1 -> next;
            if(l2) l2 = l2 -> next;
        }
        
        if(c)
        {
            ListNode* t = new ListNode(c);
            cur -> next = t;
        }
        
        return ans -> next;
    }
};