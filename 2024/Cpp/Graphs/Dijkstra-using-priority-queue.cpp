#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V);
    for (int i = 0; i < V; i++) dist[i] = 1e9;
    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node]) {
            int edgeWeight = it[1];
            int adjNode = it[0];

            if (d + edgeWeight < dist[adjNode]) {
                dist[adjNode] = d + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main() {
    // Example usage:
    int V = 5;
    vector<vector<int>> adj[V];
    adj[0] = {{1, 4}, {2, 1}};
    adj[1] = {{2, 2}, {3, 5}, {4, 12}};
    adj[2] = {{3, 2}};
    adj[3] = {{4, 3}};
    int S = 0;
    vector<int> distances = dijkstra(V, adj, S);
    for (int i = 0; i < V; i++) {
        cout << "Distance to node " << i << " from source " << S << ": " << distances[i] << endl;
    }
    return 0;
}
