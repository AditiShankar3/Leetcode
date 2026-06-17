/*
[Description]
Remove Nth Node From End of List
https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/2036378845/

Given the head of a linked list, remove the nth node from the end of the list and return its head.

 
Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]

 
Constraints:

  The number of nodes in the list is sz.
  1 <= sz <= 30
  0 <= Node.val <= 100
  1 <= n <= sz

 
Follow up: Could you do this in one pass?

[Metadata]
- Difficulty: Medium
- Topics: Linked List, Two Pointers
- Slug: remove-nth-node-from-end-of-list
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)
            return NULL;
        if(head->next==NULL){
            if(n>2)
                return NULL;
            else if(n==1)
                return NULL;
            else if(n==0)
                return head;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        while(n>0){
            fast=fast->next;
            n=n-1;
        }
        if(!fast)
            return head->next;
        while(fast->next)
        {
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};