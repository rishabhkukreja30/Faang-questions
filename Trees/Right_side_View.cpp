
vector <int> rightView (node* root) {

    vector <int> ans;
    queue <node*> q;

    if(root == NULL) {
        return ans;
    }

    q.push(root);
    q.push(NULL);

    while(!q.empty()) {

        node* n = q.front();
        q.pop();

        if(n->left) {
            q.push(n->left);
        }

        if(n->right) {
            q.push(n->right);
        }


        if(q.front() == NULL) {
            ans.push_back(n->val);
            q.pop();

            if(!q.empty()) {
                q.push(NULL);
            }
        }
    }

    return  ans;
}