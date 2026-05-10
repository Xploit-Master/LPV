# Code Explanation (HPC Perspective)

This program implements **Parallel Depth First Search (DFS)** using **OpenMP** on an undirected graph.

The main goal in **High Performance Computing (HPC)** is to improve execution speed using parallel processing and multithreading.

---

# Header Files

```cpp
#include <iostream>
#include <vector>
#include <omp.h>
```

## Explanation

| Header File | Purpose |
|-------------|----------|
| `iostream` | Used for input and output |
| `vector` | Used for adjacency list representation |
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
| `adj` | Adjacency list of graph |

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
- Creates adjacency list for every vertex.

## HPC Concept

Dynamic memory allocation improves efficiency for graph storage.

---

# addEdge Function

```cpp
void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
```

## Explanation

Adds edge between vertices.

Since graph is undirected:
- `u → v`
- `v → u`

Both vertices store each other in adjacency list.

---

# Parallel DFS Utility Function

```cpp
void parallelDFSUtil(int node, vector<bool> &visited)
```

This recursive function performs DFS traversal in parallel.

---

# alreadyVisited Variable

```cpp
bool alreadyVisited;
```

Stores whether node was already visited.

---

# Critical Section

```cpp
#pragma omp critical
{
    alreadyVisited = visited[node];

    if (!visited[node]) {
        visited[node] = true;
        cout << node << " ";
    }
}
```

## Explanation

The `visited` array is shared among threads.

Critical section ensures:
- Only one thread accesses shared data at a time.
- Prevents race conditions.

## HPC Concept: Synchronization

Synchronization maintains correctness in parallel execution.

---

# Visit Check

```cpp
if (alreadyVisited)
    return;
```

If node already visited:
- Stop recursive traversal.
- Prevent duplicate processing.

---

# Parallel Loop

```cpp
#pragma omp parallel for
```

## Explanation

Distributes loop iterations among multiple threads.

Different neighbors are processed simultaneously.

## HPC Concept

Parallel workload distribution among CPU cores.

---

# Neighbor Traversal

```cpp
for (int i = 0; i < adj[node].size(); i++)
```

Traverses adjacent vertices of current node.

---

# Neighbor Variable

```cpp
int neighbor = adj[node][i];
```

Stores adjacent node.

---

# Visit Condition

```cpp
if (!visited[neighbor])
```

Checks whether neighbor is already visited.

---

# OpenMP Task

```cpp
#pragma omp task
parallelDFSUtil(neighbor, visited);
```

## Most Important HPC Part

Creates independent parallel tasks for recursive DFS calls.

Each task may execute on different CPU thread.

## Why Task Parallelism?

DFS naturally explores different branches.

OpenMP tasks allow simultaneous branch exploration.

---

# Parallel DFS Function

```cpp
void parallelDFS(int start)
```

Starts DFS traversal.

---

# Visited Array

```cpp
vector<bool> visited(V, false);
```

Tracks visited vertices.

Initially all vertices are unvisited.

---

# Traversal Output

```cpp
cout << "\nParallel DFS Traversal: ";
```

Displays DFS traversal.

---

# OpenMP Parallel Region

```cpp
#pragma omp parallel
```

Creates multiple worker threads.

---

# Single Directive

```cpp
#pragma omp single
{
    parallelDFSUtil(start, visited);
}
```

## Explanation

Ensures only one thread starts DFS traversal initially.

Other threads help execute generated tasks.

## HPC Concept

Fork-Join Parallelism:
- Master thread creates tasks.
- Worker threads execute tasks concurrently.

---

# End Line

```cpp
cout << endl;
```

Moves output to next line.

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

Creates graph object.

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

Accepts graph edges from user.

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

Reads DFS starting node.

---

# Function Call

```cpp
g.parallelDFS(start);
```

Starts parallel DFS traversal.

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
| Parallel Computing | OpenMP parallel region |
| Task Parallelism | `#pragma omp task` |
| Multithreading | OpenMP threads |
| Shared Memory | Shared visited array |
| Synchronization | Critical section |
| Load Distribution | Parallel neighbor traversal |
| Fork-Join Model | Parallel region execution |

---

# Why This Program is Parallel DFS?

Because:

- Multiple DFS branches are explored simultaneously.
- OpenMP tasks create parallel recursive execution.
- Multiple CPU cores work together.

---

# Sequential DFS vs Parallel DFS

| Sequential DFS | Parallel DFS |
|----------------|--------------|
| Single thread | Multiple threads |
| Slower | Faster |
| One branch at a time | Multiple branches together |
| Lower CPU utilization | Better CPU utilization |

---

# Important Viva Questions from Code

## 1. What is DFS?

DFS is a graph traversal algorithm that explores depth-wise before backtracking.

---

## 2. Which data structure is used in DFS?

Stack or recursion.

---

## 3. Why OpenMP is used?

To achieve parallel execution using multiple threads.

---

## 4. Why is critical section necessary?

To avoid race conditions on shared visited array.

---

## 5. What is task parallelism?

Execution of multiple independent tasks simultaneously.

---

## 6. Why `#pragma omp task` is used?

To create parallel recursive DFS tasks.

---

## 7. What is race condition?

Incorrect behavior caused by simultaneous shared data access.

---

## 8. What type of parallelism is used?

Shared memory parallelism.

---

## 9. What is advantage of Parallel DFS?

Improved performance and better CPU utilization.

---

## 10. Why adjacency list is preferred?

It is memory efficient for sparse graphs.

---

# Final Conclusion

This program demonstrates how **Depth First Search (DFS)** can be parallelized using **OpenMP** in HPC environments.

OpenMP directives such as `parallel`, `single`, `task`, and `critical` help achieve efficient and synchronized multithreaded graph traversal on multicore processors.