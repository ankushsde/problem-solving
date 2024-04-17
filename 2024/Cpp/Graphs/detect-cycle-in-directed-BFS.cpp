{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int indegree[V] = {0};
	    
	    for(int i = 0; i< V; i++){
	        for(auto it: adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    queue <int> q;
	    for(int i = 0; i< V; i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
 	    int cnt;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        cnt++;
 	        
	        for(auto it : adj[node] ){
	            indegree[it] --;
	            if(indegree[it] == 0) q.push(it);
	        }
	    }
	    
	    if(cnt == V) return false;
	    return ture;
	    
	}
};