#include<bits/stdc++.h>
using namespace std;



int main() {


	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int k;
	cin>>k;

	queue <int> q;
	int n;
	cin>>n;
	int sum = 0;

	while(n != -1) {
		sum += n;
		q.push(n);

		if(q.size() > k) {
			sum -= q.front();
			q.pop();
		}

		cout<<(double)(sum)/(q.size())<<" ";
		cin>>n;
	}
	cout<<endl;

	return 0;
}