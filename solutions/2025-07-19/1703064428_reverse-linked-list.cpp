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

     ListNode* f(ListNode* temp,ListNode* prev,ListNode* nex)
       {
         if(temp==nullptr)  return prev ;
         nex=temp->next;
         temp->next=prev;
         prev=temp;
         temp=nex;
         return f(temp,prev,nex);
        }
    ListNode* reverseList(ListNode* head) {
    ListNode* temp=head;
    ListNode* prev=nullptr;
    ListNode* nex=nullptr;

  return  f(temp,prev,nex);
    // while(temp!=nullptr)
    // {
    //    nex=temp->next;
    //    temp->next=prev;
    //    prev=temp;
    //    temp=nex;

    // }
    //    return prev;
       
    } 
        
        
    
};