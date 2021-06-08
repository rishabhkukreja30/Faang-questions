

string  removeKDigits(string n, int k) {

	stack <char> s;

	for(int i=0;i< n.length(); i++) {

		while(!s.empty() and k > 0 and a[i] < s.top()) {
			s.pop();
			k--;
		}
		s.push(a[i]);
	}

	 while(k>0){
            s.pop();
            k--;
     }

     if(s.empty()) {
     	return "0";
     }



	string ans;
	while(!s.empty()) {
		ans = s.top() + ans;
		s.pop();
	}

	int i=0;
	/* corner case 3: count the leading number of zeros*/
    while(ans[i] == '0'){
        i++;
    }


	return (ans.substr(i) == "") ? "0" : ans.substr(i);
}







