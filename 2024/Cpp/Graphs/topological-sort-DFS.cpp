#include <vector>
#include <stack>
using namespace std;

class Solution {
private: 
    void dfs(int node, int vis[], vector<int> &st, vector<int> adj[]) {
        vis[node] = 1;
        for(auto it : adj[node]) { // 1. Iterate over adjacent nodes of 'node'
            if(!vis[it]) {
                dfs(it, vis, st, adj); // 2. Pass 'it' instead of 'node'
            }
        }
        st.push(node); // 3. Push 'node' to stack 'st'
    }

public: 
    vector<int> topoSort(int V, vector<int> adj[]) {
        int* vis = new int[V]; // 5. Declare 'vis' using 'new'
        vector<int> st;
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, vis, st, adj); // 4. Add missing semicolon
            }
        }

        delete[] vis; // Free the memory allocated for 'vis'

        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
