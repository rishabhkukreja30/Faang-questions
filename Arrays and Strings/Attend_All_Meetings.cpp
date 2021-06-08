#include<bits/stdc++.h>
using namespace std;

bool canAttendMeetings(vector <vector <int> > &intervals) {

	sort(intervals.begin(), intervals.end());

	int i=1;
	while(i < intervals.size()) {
		if(intervals[i][0] < intervals[i-1][1]) {
			return false;
		}
		i++;
	}
	return true;
}


int main() {

	
	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	vector <vector <int> > intervals;
	for(int i=0;i<n;i++) {
		int s, e;
		cin>>s>>e;
		vector <int> temp;
		temp.push_back(s);
		temp.push_back(e);

		intervals.push_back(temp);
	}

	cout<<canAttendMeetings(intervals);
	


	return 0;
}