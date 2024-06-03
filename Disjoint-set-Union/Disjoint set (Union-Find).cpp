//Basic Union Find By DSU->dsjoint set Union By Kishan Kumar N.
/*
-> It is also called union find. 
->It has 2 functions *Union ,*Find functions.
->Basic Union find .
*/
 int find(int x,vector<int>&parent){

 	if(parent[x]==x){
 		return x;
 	}

 	return parent[x]=find(parent[x],parent);
 }

 void Union(int x,int y,vector<int>&parent){

 	int x_parent=find(x,parent);

 	int y_parent=find(y,parent);

 	if(x_parent==y_parent){
 		return;
 	}
 	 parent[x_parent]=y_parent;
 }
/*
//-> code implemented in GFG->

int find(int A[],int X)
{
       if(A[X]==X){
           return X;
       }
      return  A[X]=find(A,A[X]);
}
void unionSet(int A[],int X,int Z)
{
    int x_parent=find(A,X);
    int z_parent=find(A,Z);
    
    if(x_parent==z_parent){
        return;
    }
    A[x_parent]=z_parent;
    return;
	//add code here.
}

*/

