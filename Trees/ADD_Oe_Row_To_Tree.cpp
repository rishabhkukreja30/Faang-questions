
void add(node* root, int current_depth, int d, int v) {
	if(root == NULL) {
		return;
	}

	if(current_depth == d-1) {
		node* left = root->left;
		node* right  = root->right;

		node * new_left = new node(v);
		node * new_right = new node(v);

		root->left = new_left;
		root->new_right = new_right;

		new_left->left = left;
		new_right->right = right;
		return;
	}
	else {
		add(root->left, current_depth + 1,d,v);
		add(root->right, current_depth +1, d,v);
	}
}



node* addOneRowToTree(node* root, int d, int v) {
	if(d == 1) {
		node* new_root = new node(v);
		new_root->left = root;    // or new_root->right = root;   (wiil be given in ques)
		return new_root;
	}

	add(root, 1, d, v);
	return root;
}