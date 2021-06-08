class node {
public:
	int val;
	node* prev; 
	node* next;
	node* child;
}

node* flatten(node* head) {
	if(head == NULL) {
		return head;
	}

	node* pseudoHead = new node(0, NULL, head, NULL);
	node* curr, *prev = pseudoHead;

	stack <node*> st;
	st.push(head);

	while(!st.empty()) {
		curr = st.top();
		st.pop();

		prev->next = curr;
		curr->prev = prev;

		if(curr->next != NULL) {
			st.push(curr->next);
		}

		if(curr->child != NULL) {
			st.push(curr->child);
			curr->child = NULL;
		}
		prev = curr;
	}
	pseudoHead->next->prev = NULL;
	return pseudoHead->next;
}






