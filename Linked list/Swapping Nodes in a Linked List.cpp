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

//Method 1
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
       ListNode* curr = head;
        ListNode* end = head;
        int size = 0;
        while(curr!=NULL)
        {
            size++;
            curr = curr->next;
        }
       // cout<<size;
        int first_pos = k;
        int last_pos = size - k + 1;
     //   cout<<last_pos;
        ListNode* firstNode = head;
        ListNode* lastNode = head;
        int i = 0,j = 0;
        while(i!=first_pos-1)
        {
            i++;
            firstNode = firstNode->next;
        }
       // cout<<" "<<firstNode->val;
        while(j!=last_pos-1)
        {
            j++;
            lastNode = lastNode->next;
        }
       // cout<<lastNode->val;
        swap(firstNode->val,lastNode->val);
        return head;
    }
};

//Method 2
//removing nodes from the end concept is used

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int size = 0;
        ListNode* temp = head;
        ListNode* end = head;
        while(temp!=NULL)
        {
            size++;
            end = temp;
            temp=temp->next;
        }
        if(size&1)
        {
            if(((size/2)+1) == k)
            {
                return head;
            }
        }
        int i = 0;
        ListNode* itr = head;
        k = k-1;
        while(k>0)
        {
            itr=itr->next;
            k--;
        }
        ListNode* second = head;
        ListNode* fastptr = itr;
        while(fastptr->next!=NULL)
        {
            fastptr = fastptr->next;
            second = second->next;
        }
        swap(itr->val,second->val);
        return head;
    }
};