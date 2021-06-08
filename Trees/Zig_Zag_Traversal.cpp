

vector <vector <int >> zigzagLevelOrder(node* root) {
	queue <node*> q;
	vector <vector <int> > ans;
	vector <int> temp;
	int current_level = 1;

	if(root == NULL) {
		return ans;
	}
	
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		node* n = q.front();
		q.pop();

		if(n == NULL) {
			if(current_level % 2 != 0 ) {
				ans.push_back(temp);
			}
			else {
				reverse(temp.begin(), temp.end());
				ans.push_back(temp);
			}
			current_level++;
			if(!q.empty()) {
				q.push(NULL);
			}
			while(!temp.empty()) {
				temp.pop_back();
			}
		}
		else {
			temp.push_back(n->data);
			if(n->left) {
				q.push(n->left);
			}
			if(n->right) {
				q.push(n->right);
			}
		}

	}
}