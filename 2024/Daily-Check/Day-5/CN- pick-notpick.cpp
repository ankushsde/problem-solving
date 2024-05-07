#include <bits/stdc++.h> 
vector<int> theOrder(int n)
{
	vector<int> res;
	unordered_map<int,int> visited;

	if(n == 1) {
		res.push_back(n);
	} 
	int current = 1;

	while(res.size()<=n){
		res.push_back(current);
		visited[current] = 1;

		int next = (current +1) > n ? 1 : (current+1);
		while(visited[next] == 1){
			next = (next+1) > n ? ! 1 : (next+1);

		} 
		current = next;
	}
	return res;
	
}

// fix this code