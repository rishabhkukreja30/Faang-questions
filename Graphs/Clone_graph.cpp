

    Node* cloneGraph(Node* node) {
        if(node == NULL) {
            return NULL;
        }
        map <Node*, Node*> m;
        queue <Node*> q;
        
        q.push(node);
        m[node] = new Node(node->val);
        
        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            Node* copy_node = m[curr];
            
                for(auto nbr : curr->neighbors) {
                    Node* cloned = m[nbr];
                    if(cloned == NULL) {
                        q.push(nbr);
                        cloned = new Node(nbr->val);
                        m[nbr] = cloned;
                    }
                    copy_node->neighbors.push_back(cloned);
                }
            }
        
        return m[node];
    }