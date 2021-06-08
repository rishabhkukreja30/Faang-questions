

node* last = NULL;
node* first = NULL;

void BST_to_DLL_helper(node* current) {
	if(root != NULL) {
		BST_to_DLL_helper(current->left);

		if(last != NULL) {
			last->right = current;
			current->left = last;
		}
		else {
			first = current;
		}
		last = current;
		BST_to_DLL_helper(current->right)
	}
}

node* BST_to_DLL(node* root) {
	if(root ==NULL) {
		return NULL;
	}
	BST_to_DLL_helper(root);
	last->right = first;
	first->left = last;
	return first;
}