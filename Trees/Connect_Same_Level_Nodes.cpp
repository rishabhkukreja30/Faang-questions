

void connectNextRight(node* root) {
	queue <node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		node*n = q.front();
		q.pop();

		if(n != NULL) {
			if(n->left != NULL) {
				q.push(n->left);
			}
			if(n->right != NULL) {
				q.push(n->right);
			}
			n->nextRight = q.front();
		}
		else {
			if(!q.empty()) {
				q.push(NULL);
			}
		}
	}
}