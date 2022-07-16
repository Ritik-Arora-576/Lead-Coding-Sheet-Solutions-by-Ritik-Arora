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

// TC: O(N)
// SC: O(1)

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        
        ListNode* ptr1=head;
        ListNode* ptr2=head->next;
        
        while(ptr2)
        {
            if(ptr1->val!=ptr2->val) 
            {
                ptr1=ptr1->next;
                ptr1->val=ptr2->val;
            }
            ptr2=ptr2->next;
        }
        
        ptr1->next=NULL;
        
        return head;
    }
};