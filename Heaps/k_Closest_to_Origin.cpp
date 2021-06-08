

vector <vector <int> > kClosest(vector <vector <int> > &points, int k) {
	int n = points.size();
	priority_queue <int> q;

	for(int i=0;i<n;i++) {
		int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];

		if(q.size() < k || dist < q.top()) {

			if(q.size() == k) {
				q.pop();
			}
			q.push(dist);
		}
	}

	int num = q.top();
	int i=0, j=n-1;

	while(i <= j) {
		int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];

		if(dist <= num) {
			i++;
		}
		else {
			swap(points[i],points[j]);
			j--;
		}
	}
	points.erase(points.begin() + k, points.end());
	return points;
}