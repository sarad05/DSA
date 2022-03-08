/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // naive solution using  time complexity: O(n) space complexity:O(n)

 class Solution {
public:
    bool hasCycle(ListNode *head) {
      
        unordered_set<ListNode *> s;
        if(head!=NULL)
        {
          while(head!=NULL)
          {
            if(s.find(head)!=s.end())
            {
              return true;
            }
              s.insert(head);
              head=head->next;
          }
        }
        return false;
    }
};

// optimal solution using time complexity :O(N) and space complexity O(1)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode *slowptr=head;
        ListNode *fastptr=head;
        if(head!=NULL)
        {
          while(slowptr!=NULL && fastptr!=NULL && fastptr->next!=NULL)
          {
              slowptr=slowptr->next;
              fastptr=fastptr->next->next;
              if(slowptr==fastptr)
              {
                  return true;
              }
          }
        }
        return false;
    }
};