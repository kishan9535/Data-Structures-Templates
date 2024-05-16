#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function for DFS traversal
    void dfs(int node, vector<int> adj[], vector<bool>& visited, vector<int>& result) {
        visited[node] = true;
        result.push_back(node);
        for (auto v : adj[node]) {
            if (!visited[v]) {
                dfs(v, adj, visited, result);
            }
        }
    }

    // Function to return a list containing the DFS traversal of the graph
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<int> result;
        
        // Assuming the graph is connected and starting DFS from node 0
        dfs(0, adj, visited, result);
        
        return result;
    }
};

// Driver code
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
