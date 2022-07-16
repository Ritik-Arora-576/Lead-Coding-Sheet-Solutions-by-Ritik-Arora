/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// TC: O(N)
// SC: O(1)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        ListNode* slow=head;
        ListNode* fast=head->next;
        
        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast) return true;
        }
        
        return false;
    }
};