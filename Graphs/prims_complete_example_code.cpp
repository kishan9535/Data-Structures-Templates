// codeded with ❤ Love By kishan
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[], vector<int>& parent) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        //priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
       
      // { 20     ,   3  ,     0  }
     //{ Weight   , node , parent }the data Type of priority Queue.
     vector<bool> inMST(V, false);
     //vector<int>  parent(V,-1);
        int sum = 0;
        parent[0]=-1;

        pq.push({0, 0, -1});

        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            int weight = p[0];
            int node = p[1];

            if (inMST[node] == true) {
                continue;
            }

            inMST[node] = true; // added to MST
            sum += weight;

            for (auto &temp : adj[node]) {
                int neighbour = temp[0];
                int neighbour_weight = temp[1];

                if (!inMST[neighbour]) {
                    pq.push({neighbour_weight, neighbour, node});
                    parent[neighbour]=node;
                }
            }
        }
        return sum;
    }
};

int main() {
    int V=4;
    vector<vector<int>> adj[4];
adj[0].push_back({1, 4});
adj[0].push_back({2, 6});
adj[1].push_back({0, 4});
adj[1].push_back({2, 2});
adj[1].push_back({3, 5});
adj[2].push_back({0, 6});
adj[2].push_back({1, 2});
adj[2].push_back({3, 1});
adj[3].push_back({1, 5});
adj[3].push_back({2, 1});




    Solution obj;
    vector<int> parent(V, -1);
    int sum = obj.spanningTree(V, adj, parent);

    cout << "Sum of weights of MST: " << sum << endl;
    cout << "Parents of each node in MST:" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " has parent " << parent[i] << endl;
    }

    return 0;
}
