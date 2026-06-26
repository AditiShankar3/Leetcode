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
    ListNode* findMiddle(ListNode* head){
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* ans=slow->next;
        slow->next=NULL;
        return ans;
    }
    ListNode* merge(ListNode* head,ListNode* middle){
        ListNode* curr=new ListNode(-1);
        ListNode* ans=curr;
        while(head!=NULL && middle!=NULL){
            if(head->val<=middle->val)
            {
                ans->next=head;
                head=head->next;
            }
            else
            {
                ans->next=middle;
                middle=middle->next;
            }
            ans=ans->next;
        }
        while(head!=NULL){
            ans->next=head;
            head=head->next;
            ans=ans->next;
        }
        while(middle!=NULL){
            ans->next=middle;
            middle=middle->next;
            ans=ans->next;
        }
        return curr->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* middle=findMiddle(head);
        ListNode* left=sortList(head);
        ListNode* right=sortList(middle);
        return merge(left,right);
    }
};