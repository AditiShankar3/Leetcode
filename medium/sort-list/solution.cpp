/*
[Description]
Sort List
https://leetcode.com/problems/sort-list/submissions/2047151073/

Given the head of a linked list, return the list after sorting it in ascending order.

 
Example 1:

Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:

Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Example 3:

Input: head = []
Output: []

 
Constraints:

  The number of nodes in the list is in the range [0, 5 * 104].
  -105 <= Node.val <= 105

 
Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

[Metadata]
- Difficulty: Medium
- Topics: Linked List, Two Pointers, Divide and Conquer, Sorting, Merge Sort
- Slug: sort-list
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