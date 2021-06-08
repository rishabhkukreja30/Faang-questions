
bool mirror(node* left_subtree, node* right_subtree) {

	if(left_subtree == NULL || right_subtree == NULL) {
		return left_subtree == right_subtree;
	}
	if(left_subtree->data != right_subtree->data) {
		return false;
	}
	if(mirror(left_subtree->left , right_subtree->right) and mirror(left_subtree->right , right_subtree->left)) {
		return true;
	}
	else {
		return false;
	}
}


bool isSymmetric(node* root) {
	if(root == NULL) {
		return true;
	}
	return mirror(root, root);

}