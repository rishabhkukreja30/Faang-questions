

vector <int> MaxValaues(node* root) {
	vector <int> ans;
	
	if(root == NULL) {
		return ans;
	}
	queue <node*> q;
	q.push(root);
	q.push(NULL);

	int max_val = INT_MIN;

	while(!q.empty()) {
		node* n = q.front();
		q.pop();

		if(n == NULL) {
			ans.push_back(max_val);
			if(!q.empty()) {
				q.push(NULL);
				max_val  =INT_MIN;
			}
		}
		else {
			max_val = max(max_val, n->data);
			if(n->left) {
				q.push(n->left);
			}
			if(n->right) {
				q.push(n->right);
			}
		}
	}
	return ans;
}