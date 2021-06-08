#include<bits/stdc++.h>
using namespace std;

    string compare(string s1, string s2) {
        string result;
        int n1 = s1.length() , n2 = s2.length();
        
        for(int i = 0, j =0; i<=n1-1 and j<=n2-1; i++, j++) {
            if(s1[i] != s2[j]) {
                break;
            }
            result += s1[i];
        }
        return result;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        
        for(int i=1;i<strs.size();i++) {
            prefix = compare(prefix, strs[i]);
        }
        return prefix;
    }


int main() {

	
	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	string a[n];

	for(int i=0;i<n;i++) {
		cin>>a[i];
	}

	cout<<longestCommonPrefix(a,n)<<endl;



	return 0;
}