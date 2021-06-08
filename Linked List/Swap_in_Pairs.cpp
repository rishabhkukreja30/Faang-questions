

node* swapInPairs(node* head) {

	if(head == NULL or head->next == NULL) {
		return head;
	}

	node* new_head = swapInPairs(head->next->next);
	node* temp = head->next;
	temp->next = head;
	head->next = new_head;

	return temp;
}