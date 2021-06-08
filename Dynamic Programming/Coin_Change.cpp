#include<bits/stdc++.h>
using namespace std;

// recursive soln
int coinChange(int n, int m, int *d) {
	
	if(n== 0) {
		return 1;
	}
	else if(m ==0 ) {
		return 0;
	}

	int ans = 0;
	ans = coinChange(n, m-1, d);

	if(n >= d[m]) {
		ans += coinChange(n-d[m], m, d);
	}
	return ans;
}

// bottom up dp solution
    int change(int amount, vector<int>& coins) {
        int m = coins.size();
        int dp[amount+1][m];
        
        for(int j=0;j<m;j++) {
            dp[0][j] = 1;
        }
        
        for(int i=1;i<=amount;i++) {
            for(int j=0;j<m;j++) {
                
                int ans = 0;
                if(j >= 1) {
                    ans = dp[i][j-1];
                }
                
                if(i >= coins[j]) {
                    ans += dp[i-coins[j]][j];
                }
                dp[i][j] = ans;
            }
        }
        return dp[amount][m-1];
    }




int main() {



	return 0;
}









