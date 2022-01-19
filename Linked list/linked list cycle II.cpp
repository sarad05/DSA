//Brute force
TC: O(N) Space O(N)

class Solution {
public:
 ListNode *detectCycle(ListNode *head) {
    unordered_set<ListNode*> mp;
    while(head!=NULL)
    {
        if(mp.find(head)!=mp.end())
        {
            return head;
        }
        mp.insert(head);
        head=head->next;
    }
        return NULL;
    }
};

//Optimised solution
TC: O(N) Space : O(1)

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)     //this is the base case
        {
            return NULL;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* entry=head;
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)              //this is the point of collision
            {
                while(slow!=entry)            //from point of collision
                {
                    slow=slow->next;
                    entry=entry->next;
                }
                 return entry;
            }
        }
        return NULL;
    }
};