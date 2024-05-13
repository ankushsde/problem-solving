/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
Node* dfs(Node* cur,unordered_map<Node*,Node*>& mp)
    {
        vector<Node*> neighbour;
        Node* clone=new Node(cur->val);
        mp[cur]=clone;
            for(auto it:cur->neighbors)
            {
                if(mp.find(it)!=mp.end())   //already clone and stored in map
                {
                    neighbour.push_back(mp[it]);    //directly push back the clone node from map to neigh
                }
                else
                    neighbour.push_back(dfs(it,mp));
            }
            clone->neighbors=neighbour;
            return clone;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        if(node==NULL)
            return NULL;
        // if(node->neighbors.size()==0)   //if only one node present no neighbors
        // {
        //     Node* clone= new Node(node->val);
        //     return clone; 
        // }
        return dfs(node,mp);
    }};


// Approach :
// We'll require a map to track the mapping between original and cloned nodes.
// Within the dfs function, it recursively traverses the graph, cloning each node and its neighbors.
//  If a neighbor has not been visited, it recursively clones it, otherwise, it retrieves its clone from the map.
class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*,Node*> &mp){
        Node* newNode = new Node(node->val);
        mp[node]= newNode;
        for( auto neighbor : node->neighbors){
            if(mp.find(neighbor) == mp.end()){
                //create neighbor's clone    
                (newNode-> neighbors).push_back(dfs(neighbor,mp));
            }else{
                (newNode-> neighbors).push_back(mp[neighbor]);
            }
        }
        return newNode;
    }

    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*,Node*> mp; // old and new nodes
        return dfs(node,mp);
    }};