

int LCA_BST(node* root, node* a, node* b) {

	if(a->data < root->data and b->data < root->data) {
		return LCA_BST(root->left, a, b);
	}
	if(a->data > root->data and b->data > root->data) {
		return LCA_BST(root->right, a, b);
	}

	return root;
}