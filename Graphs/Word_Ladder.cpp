

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue < string> q;
        q.push(beginWord);
        int depth = 0;
        
        set <string> dict(wordList.begin(), wordList.end());
        // for(auto x: dict) {
        //     cout<<x<<" ";
        // }
        int wordLength = beginWord.length();
        
        if(dict.find(endWord) == dict.end()) {
            return 0;
        }
        
        while(!q.empty()) {
            depth++;
            
            int sizeofQ = q.size();
            
            for(int i=0;i<sizeofQ;i++) {
                string word = q.front();
                q.pop();
                
                for(int pos=0;pos<wordLength;pos++) {
                    char orig_char = word[pos];
                    
                    for(char c = 'a'; c<='z'; c++) {
                        word[pos] = c;
                        
                        if(word == endWord) {
                            return depth+1;
                        }
                        if(dict.find(word) == dict.end()) {
                            continue;
                        }
                        dict.erase(word);
                        q.push(word);
                    }
                    word[pos] = orig_char;
                }
                
            }
        }
        return 0;
    }