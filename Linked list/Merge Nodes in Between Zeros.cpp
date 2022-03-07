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
    ListNode* mergeNodes(ListNode* head) {
         if(head->val == 0)
    {
        head = head->next;
    }
     
    // To store modified list
    ListNode* res = head;
     
    // Traverse linked list and keep
    // adding nodes between 0s.
    ListNode* temp = head;
    int sum = 0;
     
    while(temp)
    {
         
        // loop to sum the data of nodes till
        // it encounters 0
        if(temp->val != 0)
        {
            sum += temp->val;
            temp = temp->next;
        }
         
        // If we encounters 0, we need
        // to update next pointers
        else
        {
            res->val = sum;
            res->next = temp->next;
            temp = temp->next;
            res = temp;
            sum = 0;
        }
    }
        return head;
    }
};