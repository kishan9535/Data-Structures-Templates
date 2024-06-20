# Data Structures and Algorithms Templates

This repository contains templates for various data structures and algorithms.

## Contents

1. [Disjoint-Set Union](#disjoint-set-union)
2. [Graphs](#graphs)
   - [Kosaraju's Algorithm](#kosarajus-algorithm)
   - [Kruskal's Algorithm](#kruskals-algorithm)
   - [Prim's Algorithm](#prims-algorithm)
   - [Dijkstra's Algorithm](#dijkstras-algorithm)
   - [Bellman-Ford Algorithm](#bellman-ford-algorithm)
   - [Floyd-Warshall Algorithm](#floyd-warshall-algorithm)
   - [Topological Sorting](#topological-sorting)

## Disjoint-Set Union

### Description
The Disjoint-Set Union (DSU) is a data structure that keeps track of a partition of a set into disjoint (non-overlapping) subsets. It supports two operations:
- **Find**: Determine which subset a particular element is in.
- **Union**: Join two subsets into a single subset.

### Key Points
- **Path Compression**: Optimization technique to flatten the structure of the tree, ensuring all nodes point directly to the root.
- **Union by Rank**: Optimization technique to ensure the smaller tree is always added under the root of the larger tree.

## Graphs

### Kosaraju's Algorithm

### Description
Kosaraju's Algorithm is used to find all strongly connected components (SCCs) in a directed graph.

### Key Points
1. **Two-Pass DFS**: Involves two main passes of Depth-First Search (DFS).
2. **First Pass**: Perform DFS on the original graph and push vertices onto a stack in the order of their finish times.
3. **Graph Reversal**: Reverse all edges in the graph to form the transposed graph.
4. **Second Pass**: Perform DFS on the transposed graph, processing vertices in stack order to identify SCCs.
5. **Time Complexity**: O(V + E), where V is the number of vertices and E is the number of edges.
6. **Space Complexity**: O(V + E) due to storing the graph and its transpose.

### Kruskal's Algorithm

### Description
Kruskal's Algorithm is used to find the Minimum Spanning Tree (MST) of a graph.

### Key Points
1. **Sort Edges**: Sort all edges in the graph by their weight.
2. **Union-Find**: Use the Disjoint-Set Union data structure to manage and merge sets.
3. **Edge Selection**: Select the smallest edge and check if it forms a cycle. If not, include it in the MST.
4. **Time Complexity**: O(E log E), where E is the number of edges.
5. **Space Complexity**: O(V + E).

### Prim's Algorithm

### Description
Prim's Algorithm is used to find the Minimum Spanning Tree (MST) of a graph.

### Key Points
1. **Priority Queue**: Use a priority queue to select the edge with the smallest weight.
2. **Edge Selection**: Start from an arbitrary node and grow the MST one edge at a time.
3. **Time Complexity**: O(E log V), where E is the number of edges and V is the number of vertices.
4. **Space Complexity**: O(V + E).

### Dijkstra's Algorithm

### Description
Dijkstra's Algorithm is used to find the shortest path from a single source to all other vertices in a weighted graph.

### Key Points
1. **Priority Queue**: Use a priority queue to select the node with the smallest distance.
2. **Relaxation**: Update the distance to each neighbor if a shorter path is found.
3. **Time Complexity**: O(V log V + E log V), where V is the number of vertices and E is the number of edges.
4. **Space Complexity**: O(V).

### Bellman-Ford Algorithm

### Description
Bellman-Ford Algorithm is used to find the shortest path from a single source to all other vertices in a weighted graph, which can handle negative weights.

### Key Points
1. **Relaxation**: Repeatedly relax all edges up to V-1 times, where V is the number of vertices.
2. **Negative Cycle Detection**: Check for negative-weight cycles in the Vth pass.
3. **Time Complexity**: O(VE), where V is the number of vertices and E is the number of edges.
4. **Space Complexity**: O(V).

### Floyd-Warshall Algorithm

### Description
Floyd-Warshall Algorithm is used to find the shortest paths between all pairs of vertices in a weighted graph.

### Key Points
1. **Dynamic Programming**: Use a 2D matrix to store the shortest paths between all pairs.
2. **Triple Nested Loop**: Iterate over all pairs of vertices for each vertex.
3. **Time Complexity**: O(V^3), where V is the number of vertices.
4. **Space Complexity**: O(V^2).

### Topological Sorting

### Description
Topological Sorting is used to order the vertices of a directed acyclic graph (DAG) such that for every directed edge uv from vertex u to vertex v, u comes before v in the ordering.

### Key Points
1. **Kahn's Algorithm (BFS)**: Use a queue to implement Kahn's algorithm for topological sorting.
2. **DFS Based Approach**: Use a stack to implement topological sorting using DFS.
3. **Time Complexity**: O(V + E), where V is the number of vertices and E is the number of edges.
4. **Space Complexity**: O(V).

## How to Use
- Include the header files and use the provided template functions for the respective algorithms.
- Ensure to handle input and output as required by your specific use case or competitive programming environment.

## Contributing
Feel free to fork the repository, make improvements, and create pull requests.

## License
This project is licensed under the MIT License.
