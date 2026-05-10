# Code Explanation (HPC Perspective)

This program implements **Parallel Breadth First Search (BFS)** using **OpenMP** on an undirected graph.

The main goal in **High Performance Computing (HPC)** is to improve execution speed using parallel processing.

---

# Header Files

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <omp.h>
```

## Explanation

| Header File | Purpose |
|------------|----------|
| `iostream` | Used for input and output |
| `vector` | Dynamic array for adjacency list |
| `queue` | Required for BFS traversal |
| `omp.h` | OpenMP library for parallel programming |

---

# Namespace

```cpp
using namespace std;
```

Used to avoid writing `std::` repeatedly.

---

# Graph Class

```cpp
class Graph {
```

A class is created to represent the graph structure.

---

# Variables

```cpp
int V;
vector<vector<int>> adj;
```

## Explanation

| Variable | Purpose |
|----------|----------|
| `V` | Stores number of vertices |
| `adj` | Adjacency list representation of graph |

---

# Constructor

```cpp
Graph(int V) {
    this->V = V;
    adj.resize(V);
}
```

## Explanation

- Initializes graph with `V` vertices.
- `adj.resize(V)` creates adjacency list for each vertex.

## HPC Concept

Efficient memory allocation using dynamic data structures.

---

# addEdge Function

```cpp
void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
```

## Explanation

Adds an edge between two vertices.

Since graph is undirected:

- `u → v`
- `v → u`

## Example

```text
0 ---- 1
```

Both nodes store each other.

---

# Parallel BFS Function

```cpp
void parallelBFS(int start)
```

This function performs BFS traversal using OpenMP parallelism.

---

# Visited Array

```cpp
vector<bool> visited(V, false);
```

## Purpose

Tracks visited nodes.

## Why Important?

Prevents infinite loops and repeated traversal.

---

# Queue Creation

```cpp
queue<int> q;
```

Queue is used because BFS follows FIFO order.

---

# Starting Node

```cpp
visited[start] = true;
q.push(start);
```

## Explanation

- Mark source node visited.
- Insert source node into queue.

---

# Traversal Output

```cpp
cout << "\nParallel BFS Traversal: ";
```

Displays traversal sequence.

---

# Main BFS Loop

```cpp
while (!q.empty())
```

Loop continues until all nodes are processed.

---

# Queue Size

```cpp
int size = q.size();
```

Stores number of nodes at current BFS level.

## HPC Concept

Level-wise parallel traversal.

All nodes at same level can be processed simultaneously.

---

# Parallel Region

```cpp
#pragma omp parallel for
```

## Most Important HPC Part

This OpenMP directive divides loop iterations among multiple CPU threads.

### Sequential Execution

One processor executes nodes one by one.

### Parallel Execution

Multiple processors execute nodes together.

---

# Node Extraction

```cpp
int node = -1;
```

Temporary variable for current node.

---

# Critical Section

```cpp
#pragma omp critical
{
    if (!q.empty()) {
        node = q.front();
        q.pop();
        cout << node << " ";
    }
}
```

## Explanation

Queue is shared among threads.

Only one thread can access queue at a time.

## Why Critical Needed?

Without critical section:

- Multiple threads may remove same node.
- Race condition may occur.
- Incorrect output possible.

## HPC Concept: Synchronization

Used to maintain data consistency.

---

# Neighbor Traversal

```cpp
for (int neighbor : adj[node])
```

Traverses all adjacent vertices of current node.

---

# Visit Check

```cpp
if (!visited[neighbor])
```

Checks whether node is already visited.

---

# Another Critical Section

```cpp
#pragma omp critical
{
    if (!visited[neighbor]) {
        visited[neighbor] = true;
        q.push(neighbor);
    }
}
```

## Why Again Critical?

Multiple threads may try to insert same node.

Critical section ensures:

- Node inserted only once.
- Correct BFS traversal.

---

# End of BFS

```cpp
cout << endl;
```

Moves cursor to next line.

---

# Main Function

```cpp
int main()
```

Program execution starts here.

---

# Input Vertices

```cpp
cin >> V;
```

Reads number of graph vertices.

---

# Graph Object

```cpp
Graph g(V);
```

Creates graph instance.

---

# Input Edges

```cpp
cin >> E;
```

Reads number of edges.

---

# Edge Input Loop

```cpp
for (int i = 0; i < E; i++)
```

Takes graph edges from user.

---

# Add Edge

```cpp
g.addEdge(u, v);
```

Adds connection between vertices.

---

# Starting Vertex

```cpp
cin >> start;
```

Reads BFS source node.

---

# Function Call

```cpp
g.parallelBFS(start);
```

Starts parallel BFS traversal.

---

# Return Statement

```cpp
return 0;
```

Indicates successful execution.

---

# HPC Concepts Used in This Code

| HPC Concept | Used In |
|-------------|----------|
| Parallel Computing | `#pragma omp parallel for` |
| Shared Memory | Queue and visited array |
| Synchronization | `#pragma omp critical` |
| Multithreading | OpenMP threads |
| Load Distribution | Parallel loop execution |
| Race Condition Handling | Critical sections |

---

# Why This Program is Parallel BFS?

Because:

- Multiple threads process nodes simultaneously.
- OpenMP distributes work among CPU cores.
- Traversal becomes faster for large graphs.

---

# Sequential vs Parallel BFS

| Sequential BFS | Parallel BFS |
|----------------|--------------|
| Single thread | Multiple threads |
| Slower | Faster |
| One node at a time | Multiple nodes together |
| Less CPU utilization | Better CPU utilization |

---

# Important Viva Questions from Code

## 1. Why queue is used in BFS?

Because BFS follows FIFO order traversal.

---

## 2. Why OpenMP is used?

To achieve parallel execution using multiple threads.

---

## 3. Why critical section is necessary?

To avoid race conditions on shared queue and visited array.

---

## 4. What is race condition?

When multiple threads access shared data simultaneously causing incorrect behavior.

---

## 5. What type of parallelism is used?

Shared memory parallelism.

---

## 6. What is the advantage of parallel BFS?

Improved performance and reduced execution time.

---

## 7. Which OpenMP directive is used?

```cpp
#pragma omp parallel for
```

---

## 8. Why adjacency list is preferred?

It is memory efficient for sparse graphs.

---

# Final Conclusion

This program demonstrates how **Breadth First Search (BFS)** can be parallelized using **OpenMP** in HPC environments.

The use of multithreading allows simultaneous processing of graph nodes, improving performance on multicore processors while synchronization mechanisms ensure correctness of execution.