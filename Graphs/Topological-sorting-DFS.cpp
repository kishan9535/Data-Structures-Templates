/*
  Coded with love By Kishan❤❤❤❤❤

1. **Applicability:**
   - Topological sorting is only applicable to directed graphs.
   - It is specifically used for Directed Acyclic Graphs (DAGs).

2. **Execution Order:**
   - Topological sorting determines the order in which nodes (tasks) should be executed.
   - It specifies which node comes first in the execution sequence.

3. **Cycle Detection:**
   - Topological sorting can be used to detect cycles in a directed graph.
   - If topological sorting is not applicable for a graph, it indicates the presence of cycles.

4. **Multiple Sortings:**
   - There can be multiple valid topological sortings for a given DAG.
   - Different valid execution orders may exist depending on the dependencies.

5. **DAG Requirement:**
   - Topological sorting is only applicable to Directed Acyclic Graphs (DAGs).
   - A graph must be acyclic to be topologically sorted.

6. **Algorithm Name:**
   - This algorithm is also known as Kahn's algorithm.
*/


class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void dfs(vector<int> adj[],int u,vector<bool>& visited,stack<int> &st){
	     visited[u]=true;
	     // if the edge is from u-->v fist put the children v and after put u into the stack
	     for(auto &v :adj[u]){
	         if(!visited[v]){
	             dfs(adj,v, visited,st);
	         }
	     }
	     st.push(u);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool>visited(V,false);
	    stack<int>st;
	    vector<int> ans;
	    
	   for(int i=0;i<V;i++){
	       if(!visited[i]){
	           dfs(adj,i,visited,st);
	       }
	   }
	   while(!st.empty()){
	       ans.push_back(st.top());
	       st.pop();
	   }
	   return ans;
	}
};