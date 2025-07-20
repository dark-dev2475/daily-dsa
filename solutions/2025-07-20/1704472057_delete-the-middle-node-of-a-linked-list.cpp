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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr) return nullptr;
        int l=0;
        ListNode* temp=head;
        while(temp!=nullptr)
        {
            l++;
            temp=temp->next;
        }
        if(l==1) return nullptr;
        int  mid= floor(l/2);
        temp=head;
        l=0;
        while(l<mid-1){
            temp=temp->next;
            l++;
        }
        ListNode* todelete=temp->next;
        temp->next=todelete->next;
        delete todelete;
         return head;
        
    }
};