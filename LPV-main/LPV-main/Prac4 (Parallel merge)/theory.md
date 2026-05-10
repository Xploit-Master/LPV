# Parallel Merge Sort using OpenMP

---

# 📌 Aim

To design and implement **Parallel Merge Sort** using **OpenMP** and compare the performance of sequential and parallel merge sort algorithms.

---

# 🎯 Objective

Students should be able to:

- Understand Merge Sort algorithm
- Implement Sequential Merge Sort
- Implement Parallel Merge Sort using OpenMP
- Understand Divide and Conquer strategy
- Measure execution time of sequential and parallel algorithms
- Analyze performance improvement using multicore processors

---

# 📖 Theory

# What is Merge Sort?

Merge Sort is an efficient sorting algorithm based on the **Divide and Conquer** technique.

The algorithm:
1. Divides the array into smaller subarrays
2. Sorts each subarray recursively
3. Merges sorted subarrays into final sorted array

Merge Sort recursively divides the array until each subarray contains only one element.

Then all subarrays are merged back in sorted order.

---

# Working Principle of Merge Sort

Merge Sort works in two major phases:

## 1. Divide Phase

The array is recursively divided into smaller halves.

---

## 2. Merge Phase

The divided arrays are merged back together in sorted order.

---

# Basic Algorithm of Merge Sort

## Step 1
Divide array into two halves.

---

## Step 2
Recursively sort left half.

---

## Step 3
Recursively sort right half.

---

## Step 4
Merge both sorted halves.

---

## Step 5
Repeat until entire array becomes sorted.

---

# Time Complexity of Merge Sort

## Best Case

:contentReference[oaicite:0]{index=0}

---

## Average Case

:contentReference[oaicite:1]{index=1}

---

## Worst Case

:contentReference[oaicite:2]{index=2}

---

# Space Complexity

:contentReference[oaicite:3]{index=3}

Extra memory is required during merge operation.

---

# Advantages of Merge Sort

- Efficient for large datasets
- Stable sorting algorithm
- Consistent time complexity
- Suitable for parallelization
- Works well for linked lists

---

# Disadvantages of Merge Sort

- Requires extra memory
- Recursive overhead
- Slower for very small arrays
- More memory consumption compared to Quick Sort

---

# Applications of Merge Sort

- Sorting large datasets
- External sorting
- Database systems
- Multithreaded applications
- Parallel computing systems
- Scientific computing

---

# Example of Merge Sort

Consider the array:

```text
12 31 25 8 32 17 40 42
```

---

# Step 1: Divide Array

```text
12 31 25 8     32 17 40 42
```

---

# Step 2: Divide Again

```text
12 31     25 8     32 17     40 42
```

---

# Step 3: Divide into Single Elements

```text
12 31 25 8 32 17 40 42
```

Each element is now individually sorted.

---

# Step 4: Merge Sorted Elements

```text
12 31
8 25
17 32
40 42
```

---

# Step 5: Merge Again

```text
8 12 25 31
17 32 40 42
```

---

# Final Sorted Array

```text
8 12 17 25 31 32 40 42
```

---

# Concept of OpenMP

# What is OpenMP?

OpenMP (Open Multi-Processing) is an API used for parallel programming in:

- C
- C++
- Fortran

It enables programs to execute simultaneously on multiple CPU cores.

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

---

## Parallel Execution
Threads execute tasks simultaneously.

---

## Join Phase
Threads synchronize and merge back.

---

# Important OpenMP Directives

# `#pragma omp parallel`

Creates multiple worker threads.

```cpp
#pragma omp parallel
```

---

# `#pragma omp parallel sections`

Executes different sections simultaneously.

```cpp
#pragma omp parallel sections
```

---

# `#pragma omp section`

Defines independent parallel section.

```cpp
#pragma omp section
```

---

# What is Parallel Merge Sort?

Parallel Merge Sort is a parallelized version of Merge Sort.

Instead of sorting sequentially:
- Subarrays are processed simultaneously
- Multiple CPU cores work together
- Sorting becomes faster for large datasets

---

# How Parallel Merge Sort Works

## Step 1
Divide array into smaller subarrays.

---

## Step 2
Assign subarrays to multiple threads.

---

## Step 3
Threads sort subarrays simultaneously.

---

## Step 4
Sorted subarrays are merged.

---

## Step 5
Final sorted array is produced.

---

# Why Merge Sort is Suitable for Parallelism?

Merge Sort naturally divides work into independent tasks.

Different subarrays:
- Can be sorted simultaneously
- Do not interfere with each other

This makes Merge Sort ideal for parallel execution.

---

# HPC Concepts Used

| HPC Concept | Explanation |
|-------------|-------------|
| Parallel Computing | Multiple operations execute simultaneously |
| Divide and Conquer | Problem divided into smaller subproblems |
| Multithreading | Multiple threads process subarrays |
| Shared Memory | Threads access same memory |
| Synchronization | Threads coordinate merging |
| Scalability | Performance improves with more cores |
| Speedup | Reduced execution time |

---

# Sequential vs Parallel Merge Sort

| Sequential Merge Sort | Parallel Merge Sort |
|-----------------------|---------------------|
| Single thread | Multiple threads |
| Slower | Faster |
| One subarray at a time | Multiple subarrays together |
| Lower CPU utilization | Better CPU utilization |
| Limited scalability | Highly scalable |

---

# Measuring Performance

Performance analysis is important in HPC.

Important metrics:

- Execution Time
- Speedup
- Efficiency
- Scalability

---

# Execution Time

Execution time measures total sorting time.

Can be measured using:

```cpp
omp_get_wtime()
```

or

```cpp
chrono library
```

---

# Speedup Formula

:contentReference[oaicite:4]{index=4}

Higher speedup means better parallel performance.

---

# Efficiency Formula

:contentReference[oaicite:5]{index=5}

---

# Scalability

Scalability measures ability of algorithm to maintain performance as:
- Input size increases
- Number of processors increases

---

# CPU Utilization Monitoring in Ubuntu

# `top`

Displays real-time CPU and memory usage.

```bash
top
```

---

# `htop`

Interactive process monitoring tool.

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

Displays CPU and memory statistics.

```bash
vmstat
```

---

# Performance Factors

Parallel Merge Sort performance depends on:

- Number of CPU cores
- Thread synchronization overhead
- Dataset size
- Memory bandwidth
- Load balancing

---

# Limitations of Parallel Merge Sort

- Extra memory requirement
- Synchronization overhead
- Thread creation overhead
- Less benefit for small datasets

---

# Real World Applications

Parallel Merge Sort is used in:

- Big Data processing
- Database management systems
- Scientific computing
- Artificial Intelligence
- Parallel processing systems
- High Performance Computing (HPC)

---

# Important Viva Questions

## 1. What is Merge Sort?

Merge Sort is a divide-and-conquer sorting algorithm.

---

## 2. What is Divide and Conquer?

Breaking large problem into smaller subproblems.

---

## 3. What is time complexity of Merge Sort?

:contentReference[oaicite:6]{index=6}

---

## 4. Why Merge Sort is efficient?

Because it has consistent O(n log n) complexity.

---

## 5. What is OpenMP?

An API for parallel programming using multithreading.

---

## 6. Why Merge Sort is suitable for parallelism?

Because subarrays can be sorted independently.

---

## 7. What is speedup?

Performance improvement achieved using parallel execution.

---

## 8. What is scalability?

Ability to maintain performance with increasing processors.

---

## 9. What is synchronization?

Coordination among threads.

---

## 10. What is shared memory architecture?

Memory shared among multiple processors or threads.

---

## 11. Which OpenMP directive executes sections simultaneously?

```cpp
#pragma omp parallel sections
```

---

## 12. What is advantage of Parallel Merge Sort?

Faster sorting for large datasets.

---

# Conclusion

Parallel Merge Sort using OpenMP demonstrates how divide-and-conquer algorithms can efficiently utilize multicore processors.

OpenMP enables multithreaded execution, improving:
- Sorting speed
- CPU utilization
- Scalability

This experiment helps understand:
- Parallel programming
- Merge Sort algorithm
- OpenMP directives
- Performance analysis
- HPC optimization techniques