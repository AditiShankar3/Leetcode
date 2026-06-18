/*
[Description]
Remove Linked List Elements
https://leetcode.com/problems/remove-linked-list-elements/submissions/2037799586/

Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

 
Example 1:

Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Example 2:

Input: head = [], val = 1
Output: []

Example 3:

Input: head = [7,7,7,7], val = 7
Output: []

 
Constraints:

  The number of nodes in the list is in the range [0, 104].
  1 <= Node.val <= 50
  0 <= val <= 50

[Metadata]
- Difficulty: Easy
- Topics: Linked List, Recursion
- Slug: remove-linked-list-elements
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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return NULL;
        while(head->val==val && head->next)
            head=head->next;
        if(head->val==val && head->next==NULL)
            return NULL;
        ListNode* curr=head;
        while(curr->next)
        {
            if(curr->next->val==val)
                curr->next=curr->next->next;
            else
                curr=curr->next;
        }
        return head;   
    }
};