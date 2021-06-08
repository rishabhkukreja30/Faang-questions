#include<bits/stdc++.h>
using namespace std;

    int minDistance(string word1, string word2) {
        int m = word1.length() , n = word2.length();
        
        int dp[m+1][n+1];
        
        for(int i=0;i<=m;i++) {
            for(int j=0;j<=n;j++) {
                
                if(i==0) {
                    dp[i][j] = j;
                }
                else if(j == 0) {
                    dp[i][j] = i;
                }
                else if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j]  =1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
                }
            }
        }
        return dp[m][n];
    }

int main() {

	
	// #ifndef ONLINE_JUDGEs
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	string s1, s2;
	cin>>s1>>s2;

	int m = s1.length() , n = s2.length();

	int **dp = new int*[m];
	for(int i=0;i<=m;i++) {
		dp[i] = new int[n+1];
	}

	memset(dp, -1, sizeof dp);

	cout<<topDown(0,0,s1,s2,dp)<<endl;

	cout<<bottomUp(0,0,s1,s2)<<endl;

	return 0;
}








