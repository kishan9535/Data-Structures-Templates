 
/*
  Made with Love ❤ By Kishan ❤❤❤😘👌
 Topological Sorting Using BFS (Khans Algorithim) 

1. **Initialization**:
   - Create an `indegree` vector to track the in-degree of each node, initialized to zero.
   - Create an empty `queue<int>` to hold nodes with zero in-degree.
   - Create an empty `vector<int>` to store the topologically sorted order of nodes.

2. **Fill In-Degree Array**:
   - Iterate over all nodes (`0` to `V-1`).
   - For each node `u`, iterate over its adjacent nodes (`v`), and increment the in-degree of each node `v`.

3. **Enqueue Zero In-Degree Nodes**:
   - Iterate over all nodes (`0` to `V-1`).
   - If a node `i` has an in-degree of zero, enqueue it.

4. **Perform BFS for Topological Sorting**:
   - While the queue is not empty:
     - Dequeue a node `u` from the front.
     - Add node `u` to the result vector `ans`.
     - For each adjacent node `v` of `u`, decrement the in-degree of `v`.
     - If the in-degree of `v` becomes zero, enqueue it.

5. **Return the Result**:
   - After processing all nodes, the vector `ans` contains the nodes in topological order.
   - Return the result vector `ans`.

   */
   
   class Solution
{
   public:
   //Function to return list containing vertices in Topological order. 
   vector<int> topoSort(int V, vector<int> adj[]) 
   {
     
     vector<int>indegree(V,0);
     vector<int>ans;
     queue<int>que;
     //1-> Fill the Indegree array to keep Track of Indgree of te Nodes.
     for(int u=0;u<V;u++){
         for(auto v:adj[u]){
             indegree[v]++;
         }
     }
     //2-> put the indegree 0 elements into the queue to start BFS;
      for(int i=0;i<V;i++){
          if(indegree[i]==0){
              que.push(i);
          }
      }
      
      //3-> Do a BFS to get the Topo -sort in correct order:
      while(!que.empty()){
          int u=que.front();
          que.pop();
          ans.push_back(u);
          
          for(int &v :adj[u]){//u->v 
              indegree[v]--;
              
              if(indegree[v]==0){// if indegree of any node becomes 0 put it into the queue.
                  que.push(v);
              }
          }
      }
     return ans;
     
   }
};
