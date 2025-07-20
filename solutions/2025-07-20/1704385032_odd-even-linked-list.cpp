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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr) return nullptr;
        ListNode* temp=head;
      int cnt=1;
        ListNode* odd=new ListNode();
        ListNode* even=new ListNode();
        ListNode* oddtail=odd;
        ListNode* eventail=even;
        while(temp!=nullptr)
        {
            if(cnt%2==1)
            {
               oddtail->next= new ListNode(temp->val);
               oddtail=oddtail->next;
                
            }
            if(cnt%2==0)
            {
               eventail->next=new ListNode(temp->val);
               eventail=eventail->next;
            }
            
            temp=temp->next;
            cnt++;
        }
        oddtail->next=even->next;
        ListNode* Result=odd->next;
        delete odd;
        delete even;
        return Result;
    }
};