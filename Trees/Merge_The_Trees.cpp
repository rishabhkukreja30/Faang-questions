

void inorder(vector <int> &v, node* root) {
	if(root == NULL) {
		return;
	}
	inorder(v, root->left);
	v.push_back(root->data);
	inorder(v, root->right);
	return;
}

vector <int> merge_helper(vector <int> v1, vector <int> v2) {
	int n1 = v1.size();
	int n2 = v2.size();

	if(n1 ==0) {
		return v2;
	}
	if(n2 == 0) {
		return v1;
	}

	vector <int> ans;
	int i=0, j=0;

	while(i< n1 and j <n2) {

		if(v1[i] <= v2[j]) {
			ans.push_back(v1[i]);
			i++;
		}
		else {
			ans.push_back(v2[j]);
			j++;
		}
	}

	while(i<n1) {
		ans.push_back(v1[i]);
		i++;
	}

	while(j<n2) {
		ans.push_back(v2[j]);
		j++;
	}
	return ans;
}

vector <int> merge(node* root1, node* root2) {
	vector <int> v1;
	vector <int> v2;

	inorder(v1, root1);
	inorder(v2, root2);

	return merge_helper(v1,v2);
}





