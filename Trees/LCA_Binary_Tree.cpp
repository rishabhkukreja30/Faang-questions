
// O(n^2) soln


bool find(node* root, node* n) {
	if(root ==NULL) {
		return false;
	}

	return root->data == n->data || find(root->right, n) || find(root->left, n);
}



node* lca(node* root, node* a, node* b) {

	if(a->data == root->data || b->data == root->data) {
		return root;
	}

	if(find(root->left, a)) {
		if(find(root->left, b)) {
			return lca(root->left, a, b);
		}
		else {
			return root;
		}
	}
	else if(find(root->right, b)) {
		return lca(root->right, a, b);
	}
	else {
		return root;
	}
}