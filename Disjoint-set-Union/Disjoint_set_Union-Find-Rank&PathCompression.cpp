/*
By-> Kishan Kumar N...❤❤❤😍👌

Union Find By path Compression..
Find: Efficiently finds the root of a set and applies path compression to flatten the tree.
Union: Unites two sets by linking the roots and applying union by rank to maintain a balanced tree.
Path Compression and Union by Rank: These optimizations ensure that the
 operations are nearly constant time, making the DSU structure highly efficient.


  <<->>   Summary of Code Logic  <<->>
  
Common Components
Data Structures:
vector<int> parent;: Stores the parent of each element. If parent[i] == i, then i is the root of its set.
vector<int> rank;: Stores the rank (or approximate height) of the tree rooted at each element.

Find Function
Purpose: To find the representative (root) of the set containing an element.

Logic:
If the element is its own parent, return it.
Otherwise, recursively find the root and apply path compression to flatten the tree for future operations.

Union Function
Purpose: To unite two sets.

Logic:
Find the roots of the two elements.
If the roots are the same, they are already in the same set, so do nothing.
Link the root with the lower rank to the root with the higher rank to keep the tree balanced.
If the ranks are equal, arbitrarily link one root to the other and increment the rank of the new root.

*/

 vector<int> parent;
 vector<int> rank;

 int find(int x){

    if(parent[x]==x){
        return x;
    }

    return parent[x]=find(parent[x]);
 }

 void Union(int x,int y){

    int x_parent=find(x);
    int y_parent=find(y);

    if(x_parent==y_parent){
        return;
    }

    if(rank[x_parent]>rank[y_parent]){
        parent[y_parent]=x_parent;
    }
    else if(rank[x_parent]<rank[y_parent]){
        parent[x_parent]=y_parent;
    }
    else{
        parent[y_parent]=x_parent;
        rank[x_parent]++;
        }

}
