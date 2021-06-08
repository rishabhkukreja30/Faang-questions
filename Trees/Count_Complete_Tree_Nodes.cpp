
int depth(node* root) {
	int count = 0;
	while(root->left != NULL) {
		root = root->left;
		count++;
	}
	return count;
}

bool check(node* new_node, int index, int d) {
	int l = 1;
	int r = pow(2,d);
	int mid = 0;
	for(int i=0;i<d;i++) {
		mid = (l+r)/2;
		if(index <= mid) {
			new_node = new_node->left;
			r = mid; 
		}
		else {
			new_node = new_node->right;
			l = mid + 1;
		}
	}
	if(new_node == NULL) {
		return false;
	}
	else {
		return true;
	}
}

int countNodes(node* root) {
	if(root == NULL) {
		return 0;
	}

	int d = depth(root);
	if(d ==0) {
		return 1;
	}

	// find total number of nodes in level d
	int left = 1;
	int right = pow(2,d);

	int total_nodes = 0;       // total nodes in level d

	while(left <= right) {
		int mid = (left + right) / 2;
		if(check(root, mid, d)) {
			left = mid + 1;
			total_nodes = mid;
		}
		else {
			right = mid  -1;
		}
	}
	return pow(2, d)-1 + total_nodes;

}





