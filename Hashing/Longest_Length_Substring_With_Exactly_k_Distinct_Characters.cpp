

    int longestKSubstr(string s, int k) {
        // your code here
        int n = s.length();
    
        if(n == 0 or k == 0) {
            return -1;
        }
        
        unordered_map <char, int> m;
        int start = 0;
        int max_len = -1;
        
        for(int i=0;i<n;i++) {
            char ch = s[i];
            m[ch] = i;
            
            char min_idx_ch;
            int min_idx = INT_MAX;
            if(m.size() == k) {
                 max_len = max(max_len, i-start+1);
            }
            else if(m.size() > k) {
                for(auto x: m) {
                     if(x.second <min_idx) {
                         min_idx_ch = x.first;
                         min_idx = x.second;
                     }
                 }
                 start = min_idx+1;
                 m.erase(min_idx_ch);
                 max_len = max(max_len, i-start+1);
            }
            
        }
        return max_len;
    }