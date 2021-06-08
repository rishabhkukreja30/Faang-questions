

// sum is passed by reference so that its value gets updated 
void modifyBST(node* root, int &sum) {
	if(root == NULL) {
		return;
	}

	modifyBST(root->right, sum);
	sum += root->data;
	root->data = sum;
	modifyBST(root->left, sum);

}