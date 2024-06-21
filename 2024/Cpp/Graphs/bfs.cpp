// TC: O(n) + O(2E) runs on all degrees
//SC : O(3N) close to O(N), Queue, + bfs liset, and + the visited node one


// revisited ++

// To implement BFS, we'll be using, 
// a queue data structure
// a visited array and will mark starting node 1 and rest to be traverses and marked as 0;

class Solution {
  public:
     vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] ={0};
        vis[0]=1;
        // initialize a queue which contains a starting node and a visited array 
        queue<int>q;
        q.push(0);

        
        vector<int> bfs;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            // keep taking out element from queue until the queue is not empty
            bfs.push_back(node);
            // take element out, print and ask who are your neighbors
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

 
