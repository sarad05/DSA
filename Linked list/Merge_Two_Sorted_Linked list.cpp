//Brute force

 ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode();
        ListNode* newnode=new ListNode();
        if(l1==NULL && l2==NULL)
        {
            return dummy->next;
        }
        if(l1==NULL)
        {
            return l2;
        }
        else if(l2==NULL)
        {
            return l1;
        }
        if(l1!=NULL && l2!=NULL)
        {
            if(l1->val<=l2->val)
            {  dummy->next=newnode;
            newnode->val=l1->val;
            l1=l1->next;
            }
            else
            {
                dummy->next=newnode;
                newnode->val=l2->val;
                l2=l2->next;
            }
        }
        ListNode* duplicate_dummy=dummy->next;
        while(l1!=NULL && l2!=NULL)               //1,1,1,2,3,4,4
        {
             if(l1->val<=l2->val)
            {
                ListNode* newnode=new ListNode();
                 newnode->val=l1->val;
                 duplicate_dummy->next=newnode;
                 duplicate_dummy=newnode;
                 l1=l1->next;
            }
            else if(l1->val>=l2->val)
            {
                ListNode* newnode=new ListNode();
                 newnode->val=l2->val;
                 duplicate_dummy->next=newnode;
                 duplicate_dummy=newnode;
                l2=l2->next;
            }
        }
        while(l1!=NULL)
        {
             ListNode* newnode=new ListNode();
                 newnode->val=l1->val;
                 duplicate_dummy->next=newnode;
                 duplicate_dummy=newnode;
                 l1=l1->next;
        }
        while(l2!=NULL)
        {
            ListNode* newnode=new ListNode();
                 newnode->val=l2->val;
                 duplicate_dummy->next=newnode;
                 duplicate_dummy=newnode;
                l2=l2->next;
        }
        return dummy->next;
        
        
    }

//optimal solution
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)  return l2;
        if(l2==NULL)   return l1;
        if(l1->val>l2->val)    
        {
          std::swap(l1,l2);   //as we wants l1 to contain smaller value always
        }
        ListNode* res=l1;     //this will return the head of our answer
        while(l1!=NULL && l2!=NULL)
        {
           ListNode* temp=NULL;
            while(l1!=NULL && l1->val<=l2->val)
            {
               temp=l1;
                l1=l1->next;
            }
            temp->next=l2;
            std::swap(l1,l2);
        }
        return res;
    }
};