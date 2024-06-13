int v, vector<int> adj[];

int vis[n] = {0};
vis[0] = 1;

queue<int> q;
q.push(0);

vector<int> bfs;

while (!q.empty()) {
    int node = q.front();
    q.pop();
    bfs.push_back(node);

    for (auto it : adj[node]) {
        if (!vis[it]) {
            vis[it] = 1;
            q.push(it);  
        }
    }
}

return bfs;

// TC: O(n) + O(2E) runs on all degrees
//SC : O(3N) close to O(N), Queue, + bfs liset, and + the visited node one


// revisited 

class Solution {
  public:
     vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] ={0};
        vis[0]=1;
        
        queue<int>q;
        q.push(0);
        
        vector<int> bfs;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        
        return bfs;
    }
};

 
