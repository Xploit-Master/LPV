# Parallel Depth First Search (DFS) using OpenMP

---

# 📌 Aim

To design and implement **Parallel Depth First Search (DFS)** using **OpenMP** on an undirected graph and understand how parallelism improves graph traversal performance.

---

# 📖 Theory

# What is DFS?

Depth First Search (DFS) is a graph traversal algorithm that explores as far as possible along each branch before backtracking.

DFS starts from a source node and visits one branch completely before moving to another branch.

DFS can be implemented using:
- Recursion
- Stack data structure

DFS is widely used in graph traversal and searching applications.

---

# Applications of DFS

- Path finding
- Cycle detection in graphs
- Topological sorting
- Maze solving
- Network analysis
- Artificial Intelligence search problems

---

# Example of DFS

Consider the following graph:

```text
       0
      / \
     1   2
    / \   \
   3   4   5
```

---

# DFS Traversal from node 0

```text
0 → 1 → 3 → 4 → 2 → 5
```

---

# Working Steps of DFS

## Step 1
Start from source node.

## Step 2
Mark node as visited.

## Step 3
Visit any unvisited adjacent node.

## Step 4
Move deeper into graph recursively.

## Step 5
If no unvisited neighbor exists, backtrack.

## Step 6
Repeat until all nodes are visited.

---

# Concept of OpenMP

# What is OpenMP?

OpenMP (Open Multi-Processing) is an API used for parallel programming in C, C++ and Fortran.

It allows execution of multiple threads simultaneously on multicore processors.

---

# Features of OpenMP

- Shared memory programming
- Easy parallelization using directives
- Supports multicore processors
- Reduces execution time
- Efficient thread management

---

# Important OpenMP Directives Used

# `#pragma omp parallel`

Creates multiple threads for parallel execution.

```cpp
#pragma omp parallel
```

---

# `#pragma omp single`

Ensures only one thread executes a particular block.

```cpp
#pragma omp single
```

---

# `#pragma omp task`

Creates parallel tasks for recursive DFS calls.

```cpp
#pragma omp task
```

---

# `#pragma omp critical`

Protects shared resources from race conditions.

```cpp
#pragma omp critical
```

---

# How Parallel DFS Works

In Parallel DFS:

- Graph is divided among multiple threads.
- Different branches are explored simultaneously.
- Threads recursively process neighboring nodes.
- Shared visited array is synchronized using critical sections.

---

# Steps of Parallel DFS

## Step 1
Start DFS from source node.

## Step 2
Mark current node as visited.

## Step 3
Create parallel tasks for adjacent nodes.

## Step 4
Threads recursively explore graph branches.

## Step 5
Backtracking occurs after visiting all neighbors.

## Step 6
Traversal ends when all nodes are visited.

---

# Advantages of Parallel DFS

- Faster graph traversal
- Efficient CPU utilization
- Better performance on large graphs
- Supports multicore execution

---

# Concepts Used in Program

| Concept | Description |
|----------|-------------|
| Graph | Collection of vertices and edges |
| Adjacency List | Stores graph connections |
| Recursion | Used for DFS traversal |
| OpenMP | Enables parallel execution |
| Task Parallelism | Multiple recursive tasks run simultaneously |
| Critical Section | Prevents race conditions |
| Visited Array | Tracks visited nodes |

---

# Algorithm for Parallel DFS

## Step 1
Create graph using adjacency list.

---

## Step 2
Mark all vertices as unvisited.

---

## Step 3
Start DFS from source node.

---

## Step 4
Visit node and mark it visited.

---

## Step 5
Create parallel tasks for neighboring nodes.

---

## Step 6
Repeat recursively until all nodes are visited.

---

# Program Code (Parallel DFS using OpenMP)

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    // Parallel DFS Utility Function
    void parallelDFSUtil(int node, vector<bool> &visited) {

        bool alreadyVisited;

        #pragma omp critical
        {
            alreadyVisited = visited[node];

            if (!visited[node]) {
                visited[node] = true;
                cout << node << " ";
            }
        }

        if (alreadyVisited)
            return;

        #pragma omp parallel for
        for (int i = 0; i < adj[node].size(); i++) {

            int neighbor = adj[node][i];

            if (!visited[neighbor]) {

                #pragma omp task
                parallelDFSUtil(neighbor, visited);
            }
        }
    }

    // Parallel DFS Function
    void parallelDFS(int start) {

        vector<bool> visited(V, false);

        cout << "\nParallel DFS Traversal: ";

        #pragma omp parallel
        {
            #pragma omp single
            {
                parallelDFSUtil(start, visited);
            }
        }

        cout << endl;
    }
};

int main() {

    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v):\n";

    for (int i = 0; i < E; i++) {

        int u, v;
        cin >> u >> v;

        g.addEdge(u, v);
    }

    int start;

    cout << "Enter starting vertex: ";
    cin >> start;

    g.parallelDFS(start);

    return 0;
}
```

---

# Compilation Command

## For Linux / Ubuntu

```bash
g++ dfs.cpp -fopenmp -o dfs
./dfs
```

---

# Sample Input

```text
Enter number of vertices: 6
Enter number of edges: 5

Enter edges (u v):
0 1
0 2
1 3
1 4
2 5

Enter starting vertex: 0
```

---

# Sample Output

```text
Parallel DFS Traversal:
0 1 3 4 2 5
```

---

# HPC Concepts Used in This Code

| HPC Concept | Used In |
|-------------|----------|
| Parallel Computing | OpenMP task execution |
| Shared Memory | Shared visited array |
| Synchronization | Critical sections |
| Multithreading | OpenMP threads |
| Task Parallelism | Recursive DFS tasks |
| Race Condition Handling | Critical sections |

---

# Sequential DFS vs Parallel DFS

| Sequential DFS | Parallel DFS |
|----------------|--------------|
| Single thread execution | Multiple thread execution |
| Slower | Faster |
| One branch at a time | Multiple branches together |
| Lower CPU utilization | Better CPU utilization |

---

# Important Viva Questions

## 1. What is DFS?

DFS is a graph traversal algorithm that explores depth-wise before backtracking.

---

## 2. Which data structure is used in DFS?

Stack or recursion.

---

## 3. What is backtracking in DFS?

Returning to previous node when no unvisited neighbor exists.

---

## 4. What is OpenMP?

An API used for parallel programming.

---

## 5. Why is `#pragma omp task` used?

To create parallel recursive tasks.

---

## 6. Why is critical section necessary?

To avoid race conditions while accessing shared data.

---

## 7. What is race condition?

Simultaneous access of shared data causing incorrect output.

---

## 8. What is task parallelism?

Execution of multiple independent tasks simultaneously.

---

## 9. What type of parallelism is used?

Shared memory parallelism.

---

## 10. What is the advantage of Parallel DFS?

Improved speed and efficient utilization of CPU cores.

---

# Conclusion

Parallel Depth First Search (DFS) using OpenMP improves graph traversal efficiency by utilizing multiple CPU cores simultaneously.

OpenMP directives such as `parallel`, `single`, `task`, and `critical` help achieve synchronized and efficient parallel execution in High Performance Computing (HPC) environments.