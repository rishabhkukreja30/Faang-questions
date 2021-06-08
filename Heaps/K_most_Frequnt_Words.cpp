

    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        
        unordered_map <string , int> m;
        
        for(int i=0;i<words.size();i++) {
            m[words[i]]++;
        }
        
        priority_queue <string, vector <string> , greater <string> > q[n];
        
        for(auto val : m) {
            string word = val.first;
            int freq = val.second;
            
            q[freq].push(word);
        }
        
        vector <string> ans;
        
        for(int i=n-1;i>=1;i--) {
            
            while(!q[i].empty() and k>0) {
                ans.push_back(q[i].top());
                q[i].pop();
                k--;
            }
        }
        return ans;
        
    }