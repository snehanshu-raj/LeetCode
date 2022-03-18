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
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
    
        int l1 = 0, l2 = 0;
        ListNode *t = a;
        while(t)
        {
            l1++;
            t = t -> next;
        }
        
        t = b;
        while(t)
        {
            l2++;
            t = t -> next;
        }
        
        if(l1 == l2)
        {
            while(a)
            {
                if(a == b)
                    return a;
                a = a -> next;
                b = b -> next;
            }
            
            return NULL;
        }
        else
        {
            if(l1 > l2)
            {
                while(l1 != l2)
                {
                    l1--;
                    a = a -> next;
                }
            }
            else
            {
                while(l1 != l2)
                {
                    l2--;
                    b = b -> next;
                }
            }
            
            while(a)
            {
                if(a == b)
                    return a;
                a = a -> next;
                b = b -> next;
            }
            
            return NULL;
        }
        
    }
};