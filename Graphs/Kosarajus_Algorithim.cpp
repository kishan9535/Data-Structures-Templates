/*
  Codeded With ❤ Love By Kishan❤👌

      <--Kosarajus Algorithm For Strongly Connected Components-->
      

     -> Kosarajus Algorithim is used to print strongly Connected components in the order
     ->It uses Topological sorting to get the first to visit edges

     Steps in Kosaraju Algorithim->

      1)->Do a Topological Sort order of the Graph
      2)->Use stack to store the Topological Order
      3)->Reverse The edges to make sure strongly connected compenents be in order
      4)->Do a DFS Traversal based on stack(Topological order) Elements
      5)->We get a Strongly Connected Componets of the graph

      Time Complixity :->O(V+E);
      Space Complixity:->O(V+E);
*/

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
	void dfs(int node,vector<vector<int>>&adjReversed,vector<bool>&visited){
	   
	   visited[node]=true;
	   
	   for(int &v:adjReversed[node]){
	       
	       if(!visited[v]){
	           dfs(v,adjReversed,visited);
	           
	       }
	   }
	}
	
	void dfsFill(int node,vector<vector<int>>& adj,stack<int>&st ,vector<bool>&visited){
	    
	    visited[node]=true;
	    
	    for(int &v:adj[node]){
	       if(!visited[v]){
	           dfsFill(v,adj,st,visited);
	       } 
	    }
	    st.push(node);
	}
       
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        
        //1 Store order of dfs in stack using Topo-sort
        stack<int>st;
        vector<bool>visited(V,false);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfsFill(i,adj,st,visited);// do a dfs fill based on topological order
            }
        }
        
        //2->Make a Reverse graph;
        vector<vector<int>>adjReversed(V);
        for(int u=0;u<V;u++){
            
            for(int &v :adj[u]){
                adjReversed[v].push_back(u);
            }
        }
        
        //3->call Dfs Based on stack order
        int connected_count=0;
        vector<vector<int>>conn;
        visited=vector<bool>(V,false);
        
        while(!st.empty()){
            
            int node=st.top();
            st.pop();
            
            if(!visited[node]){
                dfs(node,adjReversed,visited);
                connected_count++;
            }
        }
        
        return connected_count;
        
    }
};
/*

Here are the key points about Kosaraju's Algorithm:

1. **Two-Pass DFS**:
    - Involves two main passes of Depth-First Search (DFS).

2. **First Pass**:
    - Perform DFS on the original graph.
    - Push vertices onto a stack in the order of their finish times.

3. **Graph Reversal**:
    - Reverse all the edges in the graph to form the transposed graph.

4. **Second Pass**:
    - Perform DFS on the transposed graph.
    - Process vertices in the order determined by the stack from the first pass.
    - Each DFS traversal in this step identifies a strongly connected component (SCC).

5. **Stack Usage**:
    - A stack is used to store vertices in the order of their finish times during the first pass of DFS.

6. **Time Complexity**:
    - Runs in O(V + E) time, where V is the number of vertices and E is the number of edges.

7. **Space Complexity**:
    - The space complexity is O(V + E) due to storing the graph and its transpose.

8. **Output**:
    - Identifies all strongly connected components (SCCs) in the graph.

9. **Efficiency**:
    - Efficient for large graphs due to its linear time complexity.
*/