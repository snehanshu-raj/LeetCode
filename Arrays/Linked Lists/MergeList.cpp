You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
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
        
        if(l1 == NULL and l2 == NULL)
            return NULL;
        
        if(l1 == NULL)
            return l2;
        
        if(l2 == NULL)
            return l1;
        
        ListNode* ans_head = NULL;
        ListNode* ans_tail = NULL;
        
        while(l1 and l2)
        {
            if(l1 -> val < l2 -> val)
            {
                if(ans_head == NULL)
                {
                    ans_head = l1;
                    ans_tail = l1;
                }
                else
                {
                    ans_tail -> next = l1;
                    ans_tail = l1;
                }
                
                l1 = l1 -> next;
            }
            else
            {
                if(ans_head == NULL)
                {
                    ans_head = l2;
                    ans_tail = l2;
                }
                else
                {
                    ans_tail -> next = l2;
                    ans_tail = l2;
                }
                
                l2 = l2 -> next;
            }            
        }
        
        if(l1)
        {
            ans_tail -> next = l1;
        }
        
        if(l2)
        {
            ans_tail -> next = l2;
        }
        
        return ans_head;
    }
};