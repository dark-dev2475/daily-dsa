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
 //mergse sort approach;
class Solution {
public:
    ListNode* merge(ListNode* left,ListNode* right)
    {
       ListNode* dummy=new ListNode(-1);
       ListNode* temp=dummy;
       while(left!=nullptr&&right!=nullptr)
       {
        if(left->val<=right->val)
        {
            temp->next=left;
            left=left->next;
        }
        else{
            temp->next=right;
            right=right->next;
        }
        temp=temp->next;

       }
      if(left!=nullptr)
      {
        temp->next=left;
      }
       else{
        temp->next=right;
       }

       
     return dummy->next;

    }
       
    
    ListNode* findMiddle(ListNode* head)
    {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=nullptr&&fast->next!=nullptr)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* sortl(ListNode* head) 
    {
    
        if(head==nullptr||head->next==nullptr)
        {
            return head;
        }
        ListNode* middle=findMiddle(head);
        ListNode* right=middle->next;
        middle->next=nullptr;
        ListNode* left =head;
        left=sortl(left);
        right=sortl(right);
        return merge(left,right);
        
    }   
public:
    ListNode* sortList(ListNode* head) {
        return sortl(head);
    }
};