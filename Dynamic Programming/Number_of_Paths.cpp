#include<bits/stdc++.h>
using namespace std;

int numbrOfPaths(int n, int m) {
    int **dp  = new int*[n];
        for(int i=0;i<n;i++){
            dp[i] = new int[m];
            for(int j=0;j<m;j++){
                dp[i][j] = -1;
            }  
    }

    for(int i=0;i<n;i++){
        dp[i][0] = 1;
    }
    for(int j=0;j<m;j++){
        dp[0][j] = 1;
    }
    dp[0][0] = 0;

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }

    return dp[n-1][m-1];

}

int top_down(int i,int j,int **dp){
    if(dp[i][j] == -1){
        if(i == 0 && j == 0) {
            dp[i][j] = 0;
            return 0;
        }
        else if(i == 0 || j == 0) {
            dp[i][j] = 1;
            return 1;
        }
        dp[i][j] = top_down(i,j-1,dp) + top_down(i-1,j,dp);
        return dp[i][j];
    }
    else return dp[i][j];
}

int main() {

	
	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n, m;
	cin>>n>>m;


	cout<<numbrOfPaths(n, m)<<endl;


    int **dp  =new int*[n];
    for(int i=0;i<n;i++){
        dp[i] = new int[m];
        for(int j=0;j<m;j++){
            dp[i][j] = -1;
        }  
    }

    cout<<top_down(n-1, m-1, dp)<<endl;



	return 0;
}