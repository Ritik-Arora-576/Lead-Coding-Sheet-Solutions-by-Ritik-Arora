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
// TC: O(nlogk)
// SC: O(k)

class Solution {
    struct CompareHeight {
        bool operator()(ListNode* const& l1, ListNode* const& l2)
        {
            return l1->val > l2->val;
        }
};
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareHeight> q;
        ListNode* head=NULL;
        ListNode* tail=NULL;
        
        for(ListNode* list:lists) if(list) q.push(list);
        
        while(!q.empty())
        {
            ListNode* node=q.top();
            q.pop();
            
            if(head==NULL) head=node,tail=node;
            
            else
            {
                tail->next=node;
                tail=tail->next;
            }
        
            node=node->next;
            
            if(node) q.push(node);
        }
        
        return head;
    }
};