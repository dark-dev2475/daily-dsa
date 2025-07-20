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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
     //slow andd fast pointer appraoch
     if(head==nullptr)  return nullptr;
     ListNode* dummy=new ListNode(0,head);
     ListNode* slow=dummy;
     ListNode* fast=dummy;
     int l=0;
     while(l<n)
     {
        fast=fast->next;
        l++;
     }
    
     while(fast->next!=nullptr)
     {
        slow=slow->next;
        fast=fast->next;
     }

     ListNode* todelete=slow->next;
     slow->next=slow->next->next;
     delete todelete;
     head=dummy->next;
     delete dummy;

     return head;
    }
};