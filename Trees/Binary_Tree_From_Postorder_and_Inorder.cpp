
int index;


node* buildTreeHelper(vector <int> inorder, vector<int> postorder, int s, int e) {
	if(s> e) {
		return NULL;
	}

	int data = postorder[index];
	index--;

	node* root = new node(data);

	int k = -1;
	for(int i=s;i<=e;i++) {
		if(data == inorder[i]) {
			k = i;
			break;
		}
	}

	root->right = buildTreeHelper(inorder, postorder, k+1, e);   // it is imp. that right call is made before left (bcoz it is postorder)
	root->left = buildTreeHelper(inorder, postorder,s,k-1);

	return root;
}

node* buildTree(vector <int> &inorder, vector <int> &postorder) {
	index = inorder.size()-1;

	return buildTreeHelper(inorder, postorder, 0, index);
}