

node* copyRandomList(node* head) {
	node* temp = head;

	while(temp != NULL) {
		node* n = new node(temp->val);
		n->next = temp->next;
		temp->next = n;

		temp = temp->next->next;
	}

	temp = head;
	while(temp != NULL) {
		if(temp->random != NULL) {
			temp->next->random = temp->random->next;
		}
		temp = temp->next->next;
	}

	temp = head;
	node* new_head = NULL, *new_tail = NULL;

	while(temp != NULL) {
		node* copy = temp->next;
		if(new_head == NULL) {
			new_head = copy;
			new_tail = copy;

			temp->next = copy->next;
			copy->next = NULL;
		}
		else {
			temp->next = copy->next;
			copy->next = NULL;
			new_tail->next = copy;
			new_tail = copy;
		}
		temp = temp->next;
	}
	return new_head;
}




