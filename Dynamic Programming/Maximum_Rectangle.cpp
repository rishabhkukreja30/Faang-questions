#include<bits/stdc++.h>
using namespace std;

int histogram(int a[], int m)
{
    stack <int> s;
    int maxArea = 0;
  
    for (int i = 0; i < m; i++)
    {
        if (s.empty()) {
            s.push(i);
        }
        else {
             
             while (!s.empty() && a[i] < a[s.top()]) {
                int x = s.top();
                s.pop();
                 int area = 0;
                if (s.empty())
                    area = a[x] * i;
                else
                    area = a[x] * (i - s.top() - 1);
                maxArea = max(area, maxArea);
            }
            s.push(i);
        }
    }
    while (!s.empty())
    {
         int area = 0;
         int x = s.top();
        s.pop();
        if (s.empty())
        {
            area = a[x] * m;
        }
        else
        {
            area = a[x] * (m - x);
        }

        maxArea = max(area, maxArea);
    }

    return maxArea;
}


int maxArea(int a[][100], int n, int m) {

	if(n ==0 or m== 0) {
		return 0;
	}

	int max_area = 0;
	int dp[m] = {0};

	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {

			if(a[i][j] == 1) {
				dp[j] = dp[j] + 1;
			}
			else {
				dp[j] = 0;
			}
		}
		max_area = max(max_area, histogram(dp, m));
	}
	return max_area;
}

int main() {

	
	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n, m;
	cin>>n>>m;

	int a[100][100];

	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>a[i][j];
		}
	}

	cout<<maxArea(a, n, m)<<endl;

	return 0;
}