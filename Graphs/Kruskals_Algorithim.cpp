/*
   codeded with Love❤ By Kishan❤👌

  ->It is a Minimum Spanning Tree (MST) Algorithim.
  ->MST should have (V) vertices and (V-1) edges.
   
   ->IMPortant Points in Kruskals algo:->>
     1)->
     ->sort the weights according to their weights
     ->accendeing oder sort the weight edges.
     
     2)->
        ->Take any to edges if not connect else dont connect.
        ->Use Disjoint set to know if connected or not
        ->Union find is Used Here.

        adj->{ u1 ,v1 , w1};

     3)->
       -> start Processing from Smallest Edges
       ->  and use union find   
*/
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	
	 vector<int> parent;
     vector<int> rank;

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]); // Path compression
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) {
            return;
        }

        // Union by rank
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }

    int Kruskal(vector<vector<int>>& edges) {
        int sum = 0;

        for (auto& temp : edges) {
            int u = temp[0];
            int v = temp[1];
            int wt = temp[2];

            int parent_u = find(u);
            int parent_v = find(v);

            if (parent_u != parent_v) {
                Union(u, v);
                sum += wt;
            }
        }
        return sum;
    }
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<vector<int>> edges;

        parent.resize(V);
        rank.resize(V, 0);

        for (int i = 0; i < V; i++) { // Initializing parent of disjoint set
            parent[i] = i;
        }

        for (int u = 0; u < V; u++) {
            for (auto& tmp : adj[u]) {
                int v = tmp[0];
                int wt = tmp[1];

                // Adding both (u,v) and (v,u) leads to duplicate edges
                edges.push_back({u, v, wt});
            }
        }

        // Comparator function to sort edges by weight
        auto comparator = [](vector<int>& vec1, vector<int> vec2) {
            return vec1[2] < vec2[2]; // Comparing the third element (weight)
        };
        sort(edges.begin(), edges.end(), comparator); // Sort edges in ascending order of weights.

        return Kruskal(edges);
    }
};
/*
  Here are the key points explaining how the Kruskal's algorithm works in your code:

1. **Initialization:**
   - Initialize `parent` and `rank` vectors to manage the disjoint sets.
   - Set each node as its own parent to start with.

2. **Read and Store Edges:**
   - Convert the adjacency list into an edge list while avoiding duplicate edges by only considering edges in one direction.

3. **Sort Edges:**
   - Sort the edge list in ascending order based on edge weights using a comparator.

4. **Find Function:**
   - Implement path compression in the `find` function to keep the tree flat and optimize future queries.

5. **Union Function:**
   - Implement union by rank to ensure the smaller tree is always attached under the root of the deeper tree.

6. **Process Each Edge:**
   - Iterate over the sorted edge list and for each edge, use `find` to check if the vertices are in different sets.

7. **Union and Add Edge Weight:**
   - If the vertices are in different sets, union them and add the edge weight to the total sum.

8. **Kruskal's Function:**
   - `Kruskal` function processes all edges and returns the total weight of the MST.

9. **Return Result:**
   - The `spanningTree` function returns the total sum of the weights of the MST.

These points summarize the flow of Kruskal's algorithm as implemented in your code.
*/

