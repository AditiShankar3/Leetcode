/*
[Description]
Palindrome Linked List
https://leetcode.com/problems/palindrome-linked-list/submissions/2047050684/

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 
Example 1:

Input: head = [1,2,2,1]
Output: true

Example 2:

Input: head = [1,2]
Output: false

 
Constraints:

  The number of nodes in the list is in the range [1, 105].
  0 <= Node.val <= 9

 
Follow up: Could you do it in O(n) time and O(1) space?

[Metadata]
- Difficulty: Easy
- Topics: Linked List, Two Pointers, Stack, Recursion
- Slug: palindrome-linked-list
*/

// [Solution]
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
            return NULL;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* ans=NULL;
        if(fast==NULL)
            ans=slow;
        else if(fast->next==NULL)
            ans=slow->next;
        return ans;
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
    bool isPalindrome(ListNode* head) {
        ListNode* middle=findMiddle(head);
        ListNode* head2=reverse(middle);
        while(head!=NULL && head2!=NULL)
        {
            if(head->val!=head2->val)
                return false;
            head=head->next;
            head2=head2->next;
        }
        return true;
    }
};