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
// SC: O(N)

class Solution {
    void equal(ListNode* &l,int &diff)
    {
        diff=abs(diff);
        
        while(diff--)
        {
            ListNode* temp=new ListNode(0);
            temp->next=l;
            l=temp;
        }
    }
    
    int size(ListNode* l)
    {
        int ans=0;
        while(l)
        {
            ans++;
            l=l->next;
        }
        
        return ans;
    }
    
    void add(ListNode* &l1, ListNode* &l2,int &rem)
    {
        if(l1==NULL) return;
        
        add(l1->next,l2->next,rem);
        
        int data=l1->val+l2->val+rem;
        rem=data/10;
        data%=10;
        l1->val=data;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int size1=size(l1);
        int size2=size(l2);
        int diff=size1-size2;
        
        if(diff>0) equal(l2,diff);
        else equal(l1,diff);
        
        int rem=0;
        add(l1,l2,rem);
        
        if(rem)
        {
            ListNode* temp=new ListNode(1);
            temp->next=l1;
            l1=temp;
        }
        
        return l1;
    }
};