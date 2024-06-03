
---

# Disjoint Set (Union-Find) Data Structure

## Overview

The Disjoint Set (Union-Find) data structure is a powerful tool for managing and merging disjoint sets. It supports two primary operations efficiently:
- **Find**: Determine the representative (or root) of the set containing a particular element.
- **Union**: Merge two sets into one.

This data structure is widely used in various algorithms, such as Kruskal's algorithm for finding the Minimum Spanning Tree (MST) of a graph.

## Features

- **Path Compression**: Optimizes the `find` operation to flatten the structure, making future operations faster.
- **Union by Rank**: Optimizes the `union` operation to keep the tree balanced by linking the root of the smaller tree under the root of the larger tree.

## Functions

### Find Function
```cpp
int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}
```
- **Purpose**: To find the representative (root) of the set containing an element `x`.
- **Logic**:
  - If `x` is its own parent, return `x`.
  - Otherwise, recursively find the root and apply path compression by making `x` point directly to the root. This flattens the structure, making future queries faster.

### Union Function
```cpp
void Union(int x, int y) {
    int x_parent = find(x);
    int y_parent = find(y);

    if (x_parent == y_parent) {
        return;
    }

    if (rank[x_parent] > rank[y_parent]) {
        parent[y_parent] = x_parent;
    } else if (rank[x_parent] < rank[y_parent]) {
        parent[x_parent] = y_parent;
    } else {
        parent[x_parent] = y_parent;
        rank[y_parent]++;
    }
}
```
- **Purpose**: To unite the sets containing elements `x` and `y`.
- **Logic**:
  - Find the roots of `x` and `y` using the `find` function.
  - If `x` and `y` are already in the same set, do nothing.
  - Otherwise, link the root with the lower rank to the root with the higher rank. This keeps the tree shallow, ensuring efficient operations.
  - If the ranks are the same, arbitrarily link one root to the other and increment the rank of the new root.

## Usage Example

```cpp
#include <vector>
#include <iostream>
using namespace std;

vector<int> parent;
vector<int> rank;

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    int x_parent = find(x);
    int y_parent = find(y);

    if (x_parent == y_parent) {
        return;
    }

    if (rank[x_parent] > rank[y_parent]) {
        parent[y_parent] = x_parent;
    } else if (rank[x_parent] < rank[y_parent]) {
        parent[x_parent] = y_parent;
    } else {
        parent[x_parent] = y_parent;
        rank[y_parent]++;
    }
}

int main() {
    int n = 5; // Number of elements
    parent.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; ++i) {
        parent[i] = i; // Each element is its own parent initially
    }

    Union(0, 1);
    Union(1, 2);
    Union(3, 4);

    cout << "Find(0): " << find(0) << endl; // Output will be the root of the set containing 0
    cout << "Find(1): " << find(1) << endl; // Same root as for 0
    cout << "Find(3): " << find(3) << endl; // Output will be the root of the set containing 3

    return 0;
}
```

## Key Points

- **Path Compression**: Optimizes the `find` operation by making all nodes point directly to the root, flattening the structure and speeding up future operations.
- **Union by Rank**: Optimizes the `union` operation by attaching the tree with a smaller rank under the root of the tree with a larger rank, keeping the tree balanced.
- **Efficiency**: Both `find` and `union` operations are nearly constant time, making the Disjoint Set data structure highly efficient.

## Applications

- **Kruskal's Algorithm**: For finding the Minimum Spanning Tree (MST) of a graph.
- **Connected Components**: To determine connected components in a graph.
- **Network Connectivity**: To manage network connectivity and operations efficiently.

---

You can use this README as a template and modify it according to your specific requirements.
