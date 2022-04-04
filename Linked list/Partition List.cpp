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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallPtr = new ListNode(-1);
        ListNode* greatPtr = new ListNode(-1);
        ListNode* sItr = smallPtr;
        ListNode* gItr = greatPtr;
        ListNode* curr = head;
        while(curr!=NULL)
        {
            if(curr->val < x)
            {
                sItr->next = curr;
                curr = curr->next;
                sItr = sItr->next;
            }
           else 
           {
               gItr->next = curr;
               curr = curr->next;
               gItr = gItr->next;
           }
         }
        sItr->next = greatPtr->next;
        gItr->next = NULL;    //this is greater list pointing at the end of the final list
        return smallPtr->next;
    }
};