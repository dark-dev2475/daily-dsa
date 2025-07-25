/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode pos;
        unordered_map<ListNode*,int> m;
        ListNode* temp=head;
        // bool check=false;
        while(temp!=nullptr)
        {
           if(m.find(temp)!=m.end())
           {
            return true;
           }
         
              m[temp]=1;
           temp=temp->next;
        }
        return false;;
    }
};