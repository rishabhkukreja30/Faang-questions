

node* find(node* p) {
	if(p == NULL) {
		return NULL;
	}

	node* left = find(p->left);
	if(left != NULL) {
		return left;
	}
	return p;
}


node* inorderSuccerssor2(node* p) {
	node* right = find(p->right);
	
	if(right != NULL) {
		return right;
	}
	else {
		while(p->parent != NULL and p->parent->right == p) {
			p = p->parent;
		}
		return p->parent;
	}
}