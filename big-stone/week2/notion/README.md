# Presentation of graph

## 1. adjacent matrix
[source](graph_adj_matrix.cpp)

## 2. adjacent list
[source](graph_adj_list.cpp)

## usage case (choice guide)

if graph is sparse, use adjacent list.
if graph is dense, use adjacent matrix.

because matrix has faster access time than list.
and list has better memory usage than matrix.

## 3. when graph is given as map. and method of traversing it.

as following ability to traverse map freely with direction array is needed 

### 3-1. traverse with four direction
[source](graph_map_traverse_four_direction.cpp)

### 3-2. traverse with eight direction
[source](graph_map_traverse_eight_direction.cpp)

key point is to check whether ny, nx is valid(overflow, underflow) or not as following.

```c++
if (ny < 0 || ny > n || nx < 0 || nx > n) continue;
```

### 3-3. dfs
[source](graph_dfs.cpp)

traversing graph using dfs can handle `connected-component` problem.
```c++
// dfs example
int vst[n];
vector<int> adj[n];

// check first
void dfs(int from){
    cout << from << " ";
    vst[from] = 1;
    for(int i : adj[from]){
        if (!vst[i]) dfs(i);
    }
}

// call first check inside dfs
void dfs(int from){
    if (vst[from]) return;
    vst[from] = 1;
    cout << from << " ";
    for (int i: adj[from]){
        dfs(i);
    }
```

### 3-4. bfs
[source](graph_bfs.cpp)

using bfs can handle `shortest-path` problem.

### 3-5 traversing tree : preorder, inorder ,postorder
[source](graph_tree_traverse.cpp)

