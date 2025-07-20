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
        if(head==nullptr) return nullptr;
        int len=0;
        ListNode* temp=head;
        while(temp!=nullptr)
        {
            len++;
            temp=temp->next;
        }
        int  k=len-n;
        if(k==0)
        {
            head=head->next;
            return head;
        }
        len=0;
        temp=head;
        while(len<k-1)
        {
            temp=temp->next;;
            len++;
        }
        ListNode* todelete=temp->next;
        temp->next=todelete->next;
        delete todelete;
        return head;


    }
};