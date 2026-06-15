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
        if(head==NULL || head->next==NULL)
            return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* curr=NULL;
        while(fast!=NULL && fast->next!=NULL){
            curr=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(curr==NULL)
        {
            head->next=NULL;
            return head;
        }
        curr->next=slow->next;
        slow->next=NULL;
        return head;
    }
};
