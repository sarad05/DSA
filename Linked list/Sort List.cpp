class Solution {
    private:
       ListNode* merge(ListNode* head1, ListNode* head2){
		if(head1 == NULL){
			return head2;
		}
		if(head2 == NULL){
			return head1;
		}

		ListNode* dummy = new ListNode(-1);
		ListNode* it= dummy;

		while(head1!=NULL && head2!=NULL){
			if(head1->val < head2->val){
				it->next = head1;
				head1 = head1->next;
				it = it->next;
			} else {
				it->next = head2;
				head2 = head2->next;
				it = it->next;
			}
		}
		while(head1!=NULL){
			it->next = head1;
			head1 = head1->next;
			it = it->next;

		}
		while(head2!=NULL){
			it->next = head2;
			head2 = head2->next;
			it = it->next;

		}
		return dummy->next;
       }
public:
    ListNode* sortList(ListNode* head) {
        // find the middle element of the list
		if(head == NULL || head->next == NULL){
			return head;
		}
		ListNode* fast = head;
		ListNode* slow = head;
		ListNode* prev= NULL;
		while(fast!=NULL && fast->next!=NULL){
			prev = slow;
			fast= fast->next;
			slow = slow->next;
			if(fast!=NULL){
				fast = fast->next;
			}
		}
		// slow will point to middle element
		prev->next = NULL;
		ListNode* first = sortList(head);
		ListNode*  second = sortList(slow);
		return merge(first, second);
    }
};