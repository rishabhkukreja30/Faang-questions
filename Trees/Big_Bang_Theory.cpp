#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int val;
	node* left, *right;
	node(int d) {
		val = d;
		left = right = NULL;
	}
};

node* createTree() {
	int data;
	cin>>data;
	if(data == -1) {
		return NULL;
	}
	node* root = new node(data);
	root->left = createTree();
	root->right = createTree();
	return root;
}

node* find_node(node* root, int x) {
	if(root == NULL) {
		return NULL;
	}

	if(root->val == x) {
		return root;
	}
	node* left = find_node(root->left, x);
	node* right = find_node(root->right, x);

	return left == NULL ? right : left;
}

int countNodes(node* root) {
	if(root == NULL) {
		return 0;
	}
	return 1 + countNodes(root->left) + countNodes(root->right);
}

int bigBang(node* root, int x, int n) {
	// find the node of Rajesh
	node* t = find_node(root, x);

	int left = countNodes(t->left);
	int right = countNodes(t->right);
	int remaining = n -(left + right) - 1;

	if(left > right + remaining) {
		return true;
	}
	if(right > left + remaining) {
		return  true;
	}
	if(remaining > left + right) {
		return true;
	}
	
	return false;
}


int main() {


	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int N,n,x;    // n-> actual number of nodes in the tree
	cin>>N>>n>>x;

	node* root = createTree();

	cout<<bigBang(root, x, n)<<endl;
	return 0;
}