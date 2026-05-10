# Parallel Bubble Sort using OpenMP

---

# 📌 Aim

To design and implement **Parallel Bubble Sort** using **OpenMP** and compare the performance of sequential and parallel sorting algorithms.

---

# 🎯 Objective

Students should be able to:

- Understand Bubble Sort algorithm
- Implement Sequential Bubble Sort
- Implement Parallel Bubble Sort using OpenMP
- Understand concepts of parallelism
- Measure execution time of sequential and parallel algorithms
- Analyze performance improvement using multicore processors

---

# 📖 Theory

# What is Bubble Sort?

Bubble Sort is one of the simplest sorting algorithms.

It repeatedly compares adjacent elements and swaps them if they are in the wrong order.

The larger elements gradually move toward the end of the array like bubbles rising in water.

Hence the name **Bubble Sort**.

---

# Working Principle of Bubble Sort

Bubble Sort works by repeatedly traversing the array.

For every pass:
- Compare adjacent elements
- Swap them if they are in wrong order
- Largest element moves to correct position

The process repeats until the array becomes sorted.

---

# Basic Algorithm of Bubble Sort

## Step 1
Start from first element.

## Step 2
Compare adjacent elements.

## Step 3
Swap elements if left element is greater.

## Step 4
Move to next pair.

## Step 5
Repeat until end of array.

## Step 6
Repeat passes until array becomes sorted.

---

# Time Complexity of Bubble Sort

## Best Case

```text
O(n)
```

Occurs when array is already sorted.

---

## Average Case

```text
O(n²)
```

---

## Worst Case

```text
O(n²)
```

Occurs when array is reverse sorted.

---

# Space Complexity

```text
O(1)
```

Bubble Sort uses constant extra memory.

---

# Advantages of Bubble Sort

- Simple to understand
- Easy to implement
- Good for educational purposes
- Works efficiently for small datasets
- Detects already sorted arrays quickly

---

# Disadvantages of Bubble Sort

- Very slow for large datasets
- High time complexity
- Large number of swaps
- Not suitable for high-performance systems

---

# Applications of Bubble Sort

- Educational learning
- Small dataset sorting
- Nearly sorted arrays
- Understanding sorting concepts
- Performance comparison studies

---

# Example of Bubble Sort

Consider the array:

```text
5 3 4 1 2
```

---

# First Iteration

## Compare 5 and 3

```text
3 5 4 1 2
```

Swap occurs.

---

## Compare 5 and 4

```text
3 4 5 1 2
```

Swap occurs.

---

## Compare 5 and 1

```text
3 4 1 5 2
```

Swap occurs.

---

## Compare 5 and 2

```text
3 4 1 2 5
```

Swap occurs.

Largest element `5` reaches correct position.

---

# Second Iteration

Compare remaining elements again.

```text
3 1 2 4 5
```

---

# Final Sorted Array

```text
1 2 3 4 5
```

---

# Concept of OpenMP

# What is OpenMP?

OpenMP (Open Multi-Processing) is an API used for parallel programming in:

- C
- C++
- Fortran

It enables programs to run simultaneously on multiple CPU cores.

---

# Features of OpenMP

- Shared memory programming
- Easy parallelization
- Multithreading support
- Better CPU utilization
- Reduced execution time
- Portable across platforms

---

# OpenMP Fork-Join Model

OpenMP follows Fork-Join execution model.

## Fork Phase
Master thread creates worker threads.

## Parallel Execution
Threads execute tasks simultaneously.

## Join Phase
Threads synchronize and merge back.

---

# Important OpenMP Directives

# `#pragma omp parallel`

Creates multiple threads.

```cpp
#pragma omp parallel
```

---

# `#pragma omp parallel for`

Distributes loop iterations among threads.

```cpp
#pragma omp parallel for
```

---

# `#pragma omp critical`

Protects shared data from race conditions.

```cpp
#pragma omp critical
```

---

# What is Parallel Bubble Sort?

Parallel Bubble Sort is a modified Bubble Sort algorithm that uses multiple threads to improve sorting performance.

Instead of processing entire array sequentially:
- Work is divided among multiple threads
- Threads sort different parts simultaneously
- Execution becomes faster on multicore processors

---

# How Parallel Bubble Sort Works

## Step 1
Array is divided among threads.

## Step 2
Multiple threads compare and swap elements simultaneously.

## Step 3
Threads synchronize after each iteration.

## Step 4
Sorting continues until array becomes sorted.

---

# HPC Concepts Used

| HPC Concept | Explanation |
|-------------|-------------|
| Parallel Computing | Multiple operations execute simultaneously |
| Multithreading | Multiple threads process array |
| Shared Memory | Threads access same array |
| Synchronization | Threads coordinate execution |
| Load Distribution | Work divided among threads |
| Speedup | Reduced execution time |
| Scalability | Better performance with more cores |

---

# Sequential vs Parallel Bubble Sort

| Sequential Bubble Sort | Parallel Bubble Sort |
|------------------------|----------------------|
| Single thread | Multiple threads |
| Slower | Faster |
| One comparison at a time | Multiple comparisons together |
| Low CPU utilization | High CPU utilization |
| Suitable for small tasks | Suitable for large tasks |

---

# Measuring Performance

Performance comparison is important in HPC.

We measure:
- Execution time
- CPU utilization
- Memory usage
- Speedup

---

# Steps to Measure Performance

## Step 1
Implement sequential Bubble Sort.

## Step 2
Implement parallel Bubble Sort.

## Step 3
Run both algorithms on same dataset.

## Step 4
Measure execution time.

## Step 5
Compare results.

---

# Execution Time Measurement

In C++, execution time can be measured using:

```cpp
omp_get_wtime()
```

Example:

```cpp
double start = omp_get_wtime();

/* Sorting Code */

double end = omp_get_wtime();

cout << "Execution Time: " << end - start;
```

---

# Speedup Formula

Speedup measures performance improvement.

:contentReference[oaicite:0]{index=0}

Higher speedup means better parallel performance.

---

# Efficiency Formula

Efficiency measures utilization of processors.

:contentReference[oaicite:1]{index=1}

---

# CPU Utilization in Ubuntu

# `top`

Displays real-time CPU and memory usage.

```bash
top
```

---

# `htop`

Interactive system monitoring tool.

```bash
htop
```

---

# `free -h`

Displays memory usage.

```bash
free -h
```

---

# `vmstat`

Shows CPU, memory and process statistics.

```bash
vmstat
```

---

# Performance Factors

Parallel Bubble Sort performance depends on:

- Number of CPU cores
- Thread synchronization overhead
- Dataset size
- Memory access speed
- Load balancing

---

# Limitations of Parallel Bubble Sort

- Synchronization overhead
- Thread creation overhead
- Less efficient for small arrays
- Bubble Sort still has O(n²) complexity

---

# Real World Importance

Parallel sorting algorithms are important in:

- Database systems
- Big Data processing
- Scientific computing
- Artificial Intelligence
- Parallel computing systems
- High Performance Computing (HPC)

---

# Important Viva Questions

## 1. What is Bubble Sort?

Bubble Sort is a sorting algorithm that repeatedly swaps adjacent elements if they are in wrong order.

---

## 2. Why is it called Bubble Sort?

Because larger elements move upward like bubbles in water.

---

## 3. What is time complexity of Bubble Sort?

Worst case:
```text
O(n²)
```

---

## 4. What is OpenMP?

An API for parallel programming using multithreading.

---

## 5. What is parallelism?

Executing multiple operations simultaneously.

---

## 6. What is speedup?

Improvement achieved using parallel execution.

---

## 7. Why parallel Bubble Sort is faster?

Because multiple comparisons occur simultaneously.

---

## 8. What is synchronization?

Coordination among threads to maintain correctness.

---

## 9. What is race condition?

Incorrect behavior caused by simultaneous access to shared data.

---

## 10. Which OpenMP directive distributes loops?

```cpp
#pragma omp parallel for
```

---

## 11. Why Bubble Sort is inefficient for large data?

Because of high time complexity O(n²).

---

## 12. What is shared memory architecture?

Memory shared among multiple threads/processors.

---

# Conclusion

Parallel Bubble Sort using OpenMP demonstrates how traditional sequential algorithms can be accelerated using parallel computing techniques.

OpenMP enables multithreaded execution on multicore processors, improving performance and CPU utilization.

This experiment helps understand:
- Parallel programming
- OpenMP directives
- HPC concepts
- Performance analysis
- Multithreading and synchronization