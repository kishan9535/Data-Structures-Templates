/*
     Codeded With ❤ Love By Kishan ❤👌

 ->It is used For Shortest Path form Source to all other nodes of  Negative Weight Edges.
 ->works for negative weight edges
 -> Will detect Negative Weight Cycles
 -> works Only for Directed graphs
 ->Relax all Edges (V-1)Times.
 -> Releaxing order of the Nodes Should Be same as before Done Relaxation
 ->order of the nodes can be in any Order.
 ->To detect Negative weigth Cycles:-
    * If we try to relax after (V-1) time and it relaxes then it has Negative edge Cycles
*/

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int Source) {
        
        vector<int>distance(V,INT_MAX);
        distance[Source]=0;
        
        for(int relax=1;relax<=V-1;relax++){// Do the Relaxation V-1 Times
            
            for(auto &edge :edges){
                
                int u=edge[0]; //u->v is the edge
                int v=edge[1];
                int w=edge[2];
                
                if(distance[u]!=INT_MAX && distance[u]+w < distance[v]){
                    distance[v]=distance[u]+w;
                }
            }
        }
        //To Check For negative Edges Do once More Relaxation :-> 
        //if any of distance we get changes or becomes less then there is a negative edge Cycle
        for(auto &edge :edges){
                
                int u=edge[0]; //u->v is the edge
                int v=edge[1];
                int w=edge[2];
                
                if(distance[u]!=INT_MAX && distance[u]+w < distance[v]){
                   return {-1};// if there is a negative Egge Cycle.
                }
            }
        return distance;
    }
};

/*
  Important points about the Bellman-Ford algorithm:

### Bellman-Ford Algorithm:
1. **Purpose**:
   - The Bellman-Ford algorithm is used to find the shortest paths from a single source vertex to all other vertices in a weighted graph.
   - Unlike Dijkstra's algorithm, Bellman-Ford can handle graphs with negative edge weights.

2. **Algorithm Steps**:
   - **Initialization**: Set the distance to the source vertex to 0 and all other vertices to infinity.
   - **Relaxation**: For each edge, if the distance to the destination vertex can be shortened by taking the edge, update the distance.
   - **Repeat**: Perform the relaxation step \(V-1\) times, where \(V\) is the number of vertices.
   - **Negative Cycle Detection**: After \(V-1\) relaxations, perform one more relaxation step to check for negative-weight cycles. 
                                   If a shorter path is found, a negative cycle exists.

3. **Time Complexity**:
   - The time complexity of the Bellman-Ford algorithm is \(O(V \cdot E)\), where \(V\) is the number of vertices and \(E\) is the number of edges.

4. **Space Complexity**:
   - The space complexity is \(O(V)\) for storing the distances.

5. **Advantages**:
   - It can handle negative weights, unlike Dijkstra's algorithm.
   - It can detect negative-weight cycles in the graph.

6. **Disadvantages**:
   - It is slower than Dijkstra's algorithm for graphs without negative weights.

7. **Applications**:
   - Finding shortest paths in graphs with negative weights.
   - Detecting negative weight cycles in financial networks or graphs with debt relations.

### Important Points to Remember:
- **Relaxation Process**: The key operation in the Bellman-Ford algorithm is the relaxation step. 
                          This step updates the shortest path estimates by considering each edge 
                          and trying to improve the shortest path estimate by using that edge.
- **Negative Weight Cycles**: The Bellman-Ford algorithm can detect negative weight cycles. 
                              If, after \(V-1\) iterations, a further relaxation step can still reduce 
                              the distance to any vertex, then a negative weight cycle exists.
- **Initialization**: Start by setting the distance to the source vertex as 0 and all other vertices
                        as infinity (\(INT\_MAX\)). This ensures that the source vertex is the starting 
                        point for finding the shortest paths.

*/