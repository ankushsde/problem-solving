#include <bits/stdc++.h>


class Solution {


private : 

void dfs(int node, vector<int> &adj[], int vis[], vector<int> &ls){
 
 vis[node] = 1;
 ls.push_back(node);

for(auto : it , adj[node]){
  if(!vis[node]){
    dfs(it, adj,vis,ls)
   }
}

 }


public: 

vector<int> dfsGraph ( int V, vector <int> adj[] ){

int vis[V] = {0},
int start = 0; 
vector <int> ls;

dfs(start,adj,vis,ls);

return ls;


}
};


// TC: O(N)+ O(2*Edges) in cas eundirected graph and in case of directed graph it depends on the edges. 
//SC : O(N) for storing the nodes + O(N) for visited ones  + O(N) recursion stack space = O(N)

DFS 👍

In DFS, we'll go in depth, and to go in depth we always use recursion
//remember to perform DFS we'll always need a starting node

class Solution {

private: void dfs(int node, vector<int> adj[], vector<int> vis[], vector<int> &ls){
	vis[node] = 1;
	ls.push_back(node);
// traverse all nodes
	for(auto it : adj[node]){
// if the neigbour is not visited 
	if(!vis[it]){
	dfs(node, adj, vis, ls);
 }
 }
}

public: 

vector<int> dfsOfGraph(int V, vector<int> adj[]){
int vis[V] = {0};
int start = 0;
vector<int> ls;
dfs(start,adj, vis, ls);
return ls;

}

};

