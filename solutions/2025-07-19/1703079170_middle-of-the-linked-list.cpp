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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        int l=0;
         while(temp!=nullptr)
        {
            l++;
            temp=temp->next;
        }
          int mid=(l/2);
          l=0;
          temp=head;
          while(l<mid)
          {
            temp=temp->next;
            l++;
          }
          return temp;



    }
};