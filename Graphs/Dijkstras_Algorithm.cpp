/*

  Made with ❤ By Kishan ❤👌😍

                                 Dijkstra's Algorithm

 ### Key Points about Dijkstra's Algorithm

1. **Purpose and Applicability**:
   - Finds the shortest path from a single source to all other nodes in a weighted graph.
   - Works on graphs with non-negative edge weights.

2. **Data Structures and Initialization**:
   - Uses a priority queue (min-heap) and a distance array.
   - Source node distance set to 0; all other nodes set to infinity.

3. **Process and Efficiency**:
   - Updates distances to adjacent nodes, selects the smallest tentative distance node, and marks it as processed.
   - Time complexity: \(O(V \log V + E \log V)\) with a binary heap; \(O(V \log V + E)\) with a Fibonacci heap.

4. **Applications and Limitations**:
   - Used in routing, navigation systems, and network routing.
   - Not suitable for graphs with negative weight edges.

5. **Variants**:
   - Bidirectional Dijkstra: Searches from both source and destination.
   - Dial's algorithm: For graphs with small integer weights.
*/


/*
### Steps of the Dijkstra's Algorithm Implementation

1. Initialize Distance Vector:
   - Create a vector to store the shortest distances from the source to all vertices, initialized to infinity.

2. Initialize Priority Queue:
   - Use a min-heap priority queue to store nodes along with their current shortest distances.

3. Set Source Distance and Push to Queue:
   - Set the distance of the source vertex to 0 and push it into the priority queue.

4. Process the Queue:
   - Continuously extract the node with the smallest distance from the priority queue until the queue is empty.

5. Iterate Through Neighbors:
   - For each extracted node, iterate through all its adjacent nodes.

6. Relaxation Step:
   - If a shorter path to an adjacent node is found, update the distance and push the adjacent node into the priority queue.

7. Return the Result:
   - After processing all nodes, return the vector containing the shortest distances from the source to all other vertices.

*/

// By Using Priority Queue :->>>>
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int Source)
    {
      vector<int>ans(V,INT_MAX);
      
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
      
      ans[Source]=0;
      pq.push({0,Source});//push the source to priority queue({distance, Node})
      
      while(!pq.empty()){
          
          int d    =pq.top().first;
          int node =pq.top().second;
          pq.pop();
          
          for(auto &neighbours :adj[node]){ // iterate with all the neighbours of the Node.
              
              int adjNode= neighbours[0];
              int  weight = neighbours[1];
              
              if(d+weight < ans[adjNode]){
                  ans[adjNode]=d+weight;
                  pq.push({d+weight ,adjNode}); // push to priority_queue if we get a smaller edge
              }
          }
          
      }
      return ans;
    }
};

// By Using set / map :->>>>

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int Source)
    {
      vector<int>ans(V,INT_MAX);
      
      set<pair<int,int>>st;
      
      ans[Source]=0;
      st.insert({0,Source});//push the source to priority queue.
      
      while(!st.empty()){
          
          auto &it =*st.begin();
          
          int d    =it.first;
          int node =it.second;
          st.erase(it);
          
          for(auto &neighbours :adj[node]){
              
              int adjNode= neighbours[0];
              int  weight = neighbours[1];
              
              if(d+weight < ans[adjNode]){
                  
                  if(ans[adjNode]!=INT_MAX){
                      st.erase({ans[adjNode],adjNode}); // erase if already present elemnt node distance is greater thean current node
                  }
                  
                  ans[adjNode]=d+weight;
                  st.insert({d+weight,adjNode});
                  
              }
          }
          
      }
      return ans;
    }
};

