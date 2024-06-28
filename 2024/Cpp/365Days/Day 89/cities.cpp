class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {

        // Idea: Assign the highest value to the node with the maximum degree
        // Using a topological sort approach to assign values
        
        unordered_map<int, int> val; // Map to store the importance value for each node
        unordered_map<int, int> graph; // Map to store the degree of each node
        priority_queue<pair<int, int>> q; // Priority queue to sort nodes by their degree in descending order
        long long res = 0; // Result variable to store the total importance value

        // Calculate the degree of each node
        for(int i = 0; i < roads.size(); i++) {
            graph[roads[i][0]]++;
            graph[roads[i][1]]++;
        }

        // Push the nodes and their degrees into the priority queue
        for(auto it = graph.begin(); it != graph.end(); it++) {
            q.push({it->second, it->first});
        }

        // Assign the highest values to the nodes with the highest degrees
        while(!q.empty()) {
            auto temp = q.top(); // Get the node with the highest degree
            q.pop();
            val[temp.second] = n; // Assign the current highest value to this node
            n--; // Decrease the value for the next node
        }

        // Calculate the total importance by summing the importance of each road
        for(int i = 0; i < roads.size(); i++) {
            res += (val[roads[i][0]] + val[roads[i][1]]);
        }

        return res; // Return the total importance
    }
};
