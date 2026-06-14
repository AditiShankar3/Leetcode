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
    typedef long long ll;
    ListNode* splitHalf(ListNode* head){
        if(head==NULL || head->next==NULL)
            return NULL;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* secondHead=slow->next;
        slow->next=NULL;
        return secondHead;
    }
    ListNode* reverse(ListNode* head){
        ListNode* curr=head,*prev=NULL,*next;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* SecondHead=splitHalf(head);
        SecondHead=reverse(SecondHead);
        ListNode* curr=head;
        ll twinSum=0;
        while(curr!=NULL && SecondHead!=NULL)
        {
            ll sum=curr->val+SecondHead->val;
            twinSum=max(twinSum,sum);
            curr=curr->next;
            SecondHead=SecondHead->next;
        }
        return twinSum;
    }
};