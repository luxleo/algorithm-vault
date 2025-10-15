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

