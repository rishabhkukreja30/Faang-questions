

void inorder(node* root, vector <int> &v) {
	if(root == NULL) {
		return; 
	}
	inorder(root->left, v);
	v.push_back(root->data);
	inorder(root->right, v);
	return;
}

int kthSmallest(node* root, int k) {
	vector <int> v;
	inorder(root, v);
	return v[k-1];

}