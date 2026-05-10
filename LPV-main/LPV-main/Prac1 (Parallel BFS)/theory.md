# Parallel Breadth First Search (BFS) using OpenMP

---

# 📌 Aim

To design and implement **Parallel Breadth First Search (BFS)** using **OpenMP** on an undirected graph and understand how parallelism improves graph traversal performance.

---

# 📖 Theory

# What is BFS?

Breadth First Search (BFS) is a graph traversal algorithm used to visit all vertices of a graph level by level.

It starts from a source node and first visits all neighboring nodes before moving to the next level neighbors.

BFS uses a **Queue (FIFO)** data structure.

---

# Applications of BFS

- Shortest path in unweighted graph
- Network broadcasting
- Web crawling
- Social networking suggestions
- GPS navigation systems

---

# Example of BFS

Consider the following graph:

```text
       0
      / \
     1   2
    / \   \
   3   4   5
```

---

# BFS Traversal from node 0

```text
0 → 1 → 2 → 3 → 4 → 5
```

---

# Working Steps

## Step 1
Start from source node.

## Step 2
Mark node as visited.

## Step 3
Insert node into queue.

## Step 4
Remove node from queue.

## Step 5
Visit all unvisited neighbors.

## Step 6
Repeat until queue becomes empty.

---

# Concept of OpenMP

# What is OpenMP?

OpenMP (Open Multi-Processing) is an API used for parallel programming in C, C++ and Fortran.

It allows execution of multiple threads simultaneously on multicore processors.

---

# Features of OpenMP

- Shared memory programming
- Easy parallelization using directives
- Supports multicore CPUs
- Reduces execution time

---

# Important OpenMP Directives Used

# `#pragma omp parallel for`

Used to divide loop iterations among multiple threads.

```cpp
#pragma omp parallel for
```

---

# `#pragma omp critical`

Ensures only one thread accesses shared resources at a time.

```cpp
#pragma omp critical
```

---

# How Parallel BFS Works

In Parallel BFS:

- Multiple threads process graph nodes simultaneously.
- Each thread explores neighboring vertices in parallel.
- Shared queue is protected using critical section.
- Visited array prevents revisiting nodes.

---

# Steps of Parallel BFS

## Step 1
Source node inserted into queue.

## Step 2
Multiple threads process nodes concurrently.

## Step 3
Neighboring nodes added in parallel.

## Step 4
Traversal continues until queue becomes empty.

---

# Advantages of Parallel BFS

- Faster traversal
- Better CPU utilization
- Efficient for large graphs

---

# Concepts Used in Program

| Concept | Description |
|----------|-------------|
| Graph | Collection of vertices and edges |
| Adjacency List | Stores graph connections |
| Queue | Used in BFS traversal |
| OpenMP | Enables parallel execution |
| Parallelism | Multiple threads work simultaneously |
| Critical Section | Prevents race condition |
| Visited Array | Tracks visited nodes |

---

# Algorithm for Parallel BFS

## Step 1
Create graph using adjacency list.

---

## Step 2
Mark all vertices as unvisited.

---

## Step 3
Insert starting node into queue.

---

## Step 4
Use parallel threads to process nodes.

---

## Step 5
Visit all unvisited neighboring nodes.

---

## Step 6
Continue until queue becomes empty.

---

# HPC Concepts Involved

| HPC Concept | Explanation |
|-------------|-------------|
| Parallel Computing | Multiple threads execute simultaneously |
| Shared Memory | Threads share queue and visited array |
| Synchronization | Critical section prevents conflicts |
| Multithreading | OpenMP creates multiple worker threads |
| Load Balancing | Loop iterations distributed among threads |
| Race Condition Handling | Prevents simultaneous unsafe access |

---

# Sequential BFS vs Parallel BFS

| Sequential BFS | Parallel BFS |
|----------------|--------------|
| Single thread execution | Multiple thread execution |
| Slower for large graphs | Faster execution |
| Lower CPU utilization | Better CPU utilization |
| Processes one node at a time | Processes multiple nodes together |

---

# Advantages of OpenMP in HPC

- Simple parallel programming model
- Supports multicore processors
- Reduces execution time
- Efficient shared memory programming
- Easy integration with C++

---

# Real World Applications

- Social network analysis
- Web crawling systems
- Routing algorithms
- Recommendation systems
- AI and Machine Learning graph traversal
- Network packet analysis

---

# Important Viva Questions

## 1. What is BFS?

BFS is a graph traversal algorithm that visits nodes level by level using a queue.

---

## 2. Which data structure is used in BFS?

Queue data structure.

---

## 3. What is OpenMP?

OpenMP is an API used for parallel programming.

---

## 4. What is parallelism?

Executing multiple tasks simultaneously.

---

## 5. Why is critical section used?

To avoid race condition when multiple threads access shared resources.

---

## 6. What is race condition?

A condition where multiple threads access shared data simultaneously causing incorrect output.

---

## 7. Which OpenMP directive is used for parallel execution?

```cpp
#pragma omp parallel for
```

---

## 8. What is the advantage of Parallel BFS?

Improved speed and better CPU utilization.

---

## 9. Why adjacency list is preferred?

Because it is memory efficient for sparse graphs.

---

## 10. What type of parallelism is used here?

Shared memory parallelism.

---

# Conclusion

Parallel Breadth First Search (BFS) using OpenMP improves graph traversal performance by utilizing multiple CPU cores simultaneously.

OpenMP directives such as `parallel for` and `critical` help achieve efficient and synchronized parallel execution in High Performance Computing (HPC) environments.