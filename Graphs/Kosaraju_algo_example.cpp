#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    // Function to find number of strongly connected components in the graph.

    // DFS function for the reversed graph
    void dfs(int node, vector<vector<int>>& adjReversed, vector<bool>& visited, vector<int>& currentSCC) {
        visited[node] = true;
        currentSCC.push_back(node);
        for (int &v : adjReversed[node]) {
            if (!visited[v]) {
                dfs(v, adjReversed, visited, currentSCC);
            }
        }
    }

    // DFS function to fill the stack with vertices based on their finish times
    void dfsFill(int node, vector<vector<int>>& adj, stack<int>& st, vector<bool>& visited) {
        visited[node] = true;
        for (int &v : adj[node]) {
            if (!visited[v]) {
                dfsFill(v, adj, st, visited);
            }
        }
        st.push(node);
    }

    int kosaraju(int V, vector<vector<int>>& adj, vector<vector<int>>& SCCs) {
        // 1. Store order of dfs in stack using Topo-sort
        stack<int> st;
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfsFill(i, adj, st, visited); // do a dfs fill based on topological order
            }
        }

        // 2. Make a Reverse graph
        vector<vector<int>> adjReversed(V);
        for (int u = 0; u < V; u++) {
            for (int &v : adj[u]) {
                adjReversed[v].push_back(u);
            }
        }

        // 3. Call DFS based on stack order
        int connected_count = 0;
        visited = vector<bool>(V, false);

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (!visited[node]) {
                vector<int> currentSCC;
                dfs(node, adjReversed, visited, currentSCC);
                SCCs.push_back(currentSCC);
                connected_count++;
            }
        }

        return connected_count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V); // Changed to a single vector of vectors
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v); // Simplified edge insertion
        }

        Solution obj;
        vector<vector<int>> SCCs;
        int count = obj.kosaraju(V, adj, SCCs);
        cout << "Number of Strongly Connected Components: " << count << "\n";
        cout << "Strongly Connected Components:\n";
        for (const auto& scc : SCCs) {
            for (int node : scc) {
                cout << node << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
// } Driver Code Ends
