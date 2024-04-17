#include <vector>
using namespace std;

class Solution {
private:
    bool detect(int node, int parent, vector<int> vis[], vector<int> adj[]) {
        vis[node] = 1;
        for (auto adjacentNode : adj[node]) {
            if (!vis[adjacentNode]) {
                if (detect(adjacentNode, node, adj, vis))
                    return true;
            } else if (adjacentNode != parent)
                return true;
        }
        return false;
    }

public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (detect(i, -1, adj, vis))
                    return true;
            }
        }
        return false;
    }
};

// SC: O(N)+O(N), recursion stack space and visied array
// TC : O(N+2E), as it takes for DFS as discussed
