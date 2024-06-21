//

#include <vector>
#include <stack>
using namespace std;

class Solution
{
private:
    void dfs(int node, int vis[], vector<int> &st, vector<int> adj[])
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, vis, st, adj);
            }
        }
        st.push(node);
    }

public:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        int *vis = new int[V];
        vector<int> st;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, st, adj);
            }
        }

        delete[] vis;

        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

// revisted :
// Works on Directed Acyclic Graphs

class Solution
{

private:
    void dfs(int node, vector<int> adj[], vector<int> &st, int vis[])
    {
        vis[node] = 1;
        for (int it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, adj, st, vis);
            }
        }
        st.push(node);
    }

public:
    vector<int> topoSort(int V, Vector<int> adj[])
    {
        int vis[V] = {0};
        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, st, vis);
            }
        };

        vector<int> ans;

        while (!q.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }

}

// TC : O(V + E)
//          SC : O(N)
