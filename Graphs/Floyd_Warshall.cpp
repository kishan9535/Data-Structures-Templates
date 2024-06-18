/*
   Codeded With ❤ Love By Kishan ❤👌

                <---Floyd Warshall--->

    -> Multi-Source Shortest Path Algorithim.
    ->finds Shortest Distances B/W Every pair of vertices of 2 given edge -weigted -directed graph
    -> It can detect negative edge cycles.



    Certainly! Here is the explanation without example code:

1. **Initialization**:
   - Determine the number of vertices, `n`, from the size of the adjacency matrix.

2. **Replace `-1` with a Large Value**:
   - Iterate through the adjacency matrix.
   - Replace all `-1` entries with a large value (`100000`) to represent the absence of a direct path. 
     This ensures that these entries do not affect the distance calculations during the algorithm.

3. **Floyd-Warshall Algorithm**:
   - Apply the Floyd-Warshall algorithm to find the shortest paths between all pairs of vertices.
   - Use three nested loops:
     - The outer loop iterates through each vertex as an intermediate vertex (`via`).
     - The middle loop iterates through each vertex as the source vertex (`i`).
     - The inner loop iterates through each vertex as the destination vertex (`j`).
   - For each pair of source and destination vertices (`i`, `j`), update the shortest distance
      by considering the intermediate vertex (`via`). Specifically, the distance is updated 
      if a shorter path is found through the intermediate vertex.

4. **Replace Large Value Back to `-1`**:
   - After applying the Floyd-Warshall algorithm, iterate through the matrix again.
   - Replace the large value (`100000`) back with `-1` to indicate that there is 
     no path between the corresponding vertices in the final result.

    This process ensures that the adjacency matrix is updated to reflect the shortest distances
    between all pairs of vertices, considering any intermediate vertices that might provide 
    shorter paths. If a direct path does not exist between two vertices, it is indicated by `-1` in the final matrix.
*/


class Solution {
public:
    void shortest_distance(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Step 1: Replace all -1 with a large value (100000) to indicate no path
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = 100000;
                }
            }
        }
        
        // Step 2: Apply Floyd-Warshall algorithm to find shortest distances
        for (int via = 0; via < n; via++) { // Iterate through all possible intermediate vertices
            for (int i = 0; i < n; i++) { // Iterate through all source vertices
                for (int j = 0; j < n; j++) { // Iterate through all destination vertices
                    // Update the shortest distance from i to j through the intermediate vertex 'via'
                    matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }
        
        // Step 3: Replace the large value back to -1 to indicate no path in the final result
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 100000) {
                    matrix[i][j] = -1;
                }
            }
        }
        /*
        for negative edge cycle detection:-

        for(int i=0;i<n;i++){
	       if(matrix[i][i]!=0){ // there is a negative edge Cycle 
	         return -1
	       }
        }
        */
    }
};
