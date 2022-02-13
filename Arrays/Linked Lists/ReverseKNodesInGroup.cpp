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
    ListNode* reverseKGroup(ListNode* a, int k) {
        
        stack < ListNode* > s;
        
        int c = 0;
        ListNode* head = a;
        
        ListNode* ans_head = NULL;
        ListNode* ans_tail = NULL;
        
        while (head != NULL)
        {
            c = 0;
            ListNode* temp = head;
            
            while(c != k and head != NULL)
            {
                c++;
                s.push(head);
                head = head -> next;            
            }

            if (c != k)
            {
                cout << "c != NULL";
                
                if(ans_head == NULL)
                {
                    ans_head = temp;
                    return ans_head;
                }
                
                ans_tail -> next = temp;
                return ans_head;
            }
    
            while(!s.empty())
            {
                ListNode* top = s.top();
                s.pop();

                if (ans_head == NULL)
                {
                    ans_head = top;
                    ans_tail = top;
                }
                else
                {
                    ans_tail -> next = top;
                    ans_tail = top;
                }
            }   
        }
        
        ans_tail -> next = NULL;
        return ans_head;
    }
};