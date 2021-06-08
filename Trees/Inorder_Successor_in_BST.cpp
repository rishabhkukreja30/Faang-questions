
bool check = false;

node* inorderSuccessorInBST(node* root, node* p) {
	if(root == NULL) {
		return NULL;
	}

	node* left = inorderSuccessorInBST(root->left, p);
	if(left) {
		return left;
	}

	if(check == true) {
		check = false;
		return root;	
	}
	if(root->data == p->data) {
		check = true;
	}

	node* right = inorderSuccessorInBST(root->right, p);
	if(right) {
		return right;
	}

	return NULL;
}
