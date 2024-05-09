// using BFS,
// Bipartite graph problem is similar to M coloring game.
// approach : simply check if the same color detected, rest BFS approach is there.
// TC: O(n) + O(2E) runs on all degrees
//SC : O(3N) close to O(N), Queue, + bfs liset, and + the visited node one

class Solution {
public:
bool check(int start, int V, vector<vector<int>>&adj,vector<int>&color){
        color[start] = 0;
        queue<int>q;
        q.push(start);
        while(!q.empty()){
           int node = q.front();
           q.pop();
           for(auto j: adj[node]){
               if(color[j] == -1){
                   color[j] = !color[node];
                   q.push(j);
               }
               else if(color[j] == color[node]){
                   return false;
               }
           }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& adj) {
        int V=adj.size();
        vector<int>color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i] == -1){
                if(!check(i,V,adj,color)){
                    return false;
                }
            }
        }
        return true;
    }
};