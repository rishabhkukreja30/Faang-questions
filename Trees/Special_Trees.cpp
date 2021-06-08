#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* left, *right;
	node(int d) {
		data = d;
		left = right = NULL;
	}
};

void inorder(node* root) {
	if(root == NULL) {
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

node* specialTrees(int a[], int s, int e) {
	if(s> e) {
		return NULL;
	}

	int k=s;
	for(int i=s;i<=e;i++) {
		if(a[i] > a[k]) {
			k = i;
		}
	}

	node* root = new node(a[k]);
	root->left = specialTrees(a,s,k-1);
	root->right = specialTrees(a,k+1,e);
	return root;
}



int main() {


	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	int a[n];

	for(int i=0;i<n;i++) {
		cin>>a[i];
	}

	node* root = specialTrees(a,0,n-1);

	inorder(root);

	return 0;
}