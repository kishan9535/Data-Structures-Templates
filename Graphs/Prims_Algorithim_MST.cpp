/*

   Codeded With ❤ Love By Kishan 👌❤
   
  Minimum Spanning tree Algorithims:->
   1->Prims Algorithim.
   2->Krushkals Algorithim.

    Important Points To Remenber About MST:->

     1->The MST should have exactly v verteces ans (v-1)Edges To become a Spanning Tree.
     2-> The Shortest edges of Spanning Tree is a Minimum Spanning Tree

     { 20     ,   3  ,     0 }
     { Weight , node , parent}// the data Type of priority Queue.

     ->we use a Visited array and paren array to store visited nodes and their parents.
     -> we use priority_queue(min_heap) for smaleest edges to process.
  
  Sure, here are the key points in small, concise steps:

### Initialization
1. **Min-Heap Priority Queue** to store edges `{weight, node, parent}`.
2. **Tracking Inclusion** in MST using a boolean vector `inMST`.
3. **Parent Array** to track the parent of each node in the MST.
4. **Total Weight** sum initialized to 0.

### Starting Point
5. **Push Initial Node** with weight `0` and node `0` into the priority queue.

### Main Loop
6. **Extract Minimum Weight Edge** from the priority queue.
7. **Skip Nodes** already included in the MST.
8. **Include Node** in MST and add edge weight to the total sum.

### Explore Adjacent Nodes
9. **Iterate Over Adjacent Nodes** of the current node.
10. **Push Valid Edges** to the priority queue if the adjacent node is not in MST.
11. **Update Parent** of each adjacent node.

### Return Result
12. **Return Total Weight** of the MST.


*/
class Solution
{
    
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
       
      // { 20     ,   3  ,     0  }
     //{ Weight   , node , parent }the data Type of priority Queue.
     vector<bool> inMST(V, false);
     vector<int>  parent(V,-1);
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