# Parallel Reduction using OpenMP

---

# 📌 Aim

To implement **Min, Max, Sum, and Average operations** using **Parallel Reduction** with OpenMP.

---

# 🎯 Objective

Students should be able to:

- Understand the concept of Parallel Reduction
- Implement Min, Max, Sum, and Average operations using OpenMP
- Understand reduction operations in parallel computing
- Analyze the advantages of parallel execution
- Measure performance improvement using multithreading

---

# 📖 Theory

# What is Parallel Reduction?

Parallel Reduction is a technique used in parallel computing to combine multiple values into a single result efficiently.

Reduction operations are commonly used for:
- Sum
- Minimum
- Maximum
- Average
- Product

In Parallel Reduction:
- Data is divided among multiple threads
- Each thread performs operation on its assigned data
- Partial results are combined into final result

---

# Why Parallel Reduction is Important?

For very large datasets:
- Sequential operations become slow
- CPU utilization remains low

Parallel Reduction improves:
- Performance
- Execution speed
- Resource utilization

It is widely used in:
- Scientific computing
- Machine learning
- Big data processing
- HPC applications

---

# Basic Working of Parallel Reduction

## Step 1
Divide dataset among threads.

---

## Step 2
Each thread computes partial result.

---

## Step 3
Partial results are combined.

---

## Step 4
Final reduced value is produced.

---

# Example of Parallel Reduction

Consider the array:

```text
2 4 6 8
```

For Sum Reduction:

## Thread 1

```text
2 + 4 = 6
```

## Thread 2

```text
6 + 8 = 14
```

## Final Reduction

```text
6 + 14 = 20
```

Final Sum:

```text
20
```

---

# Types of Reduction Operations

| Operation | Purpose |
|------------|----------|
| Min Reduction | Finds minimum value |
| Max Reduction | Finds maximum value |
| Sum Reduction | Finds total sum |
| Average Reduction | Finds average value |

---

# Concept of OpenMP

# What is OpenMP?

OpenMP (Open Multi-Processing) is an API used for parallel programming in:

- C
- C++
- Fortran

It supports:
- Multithreading
- Shared memory programming
- Parallel execution

---

# Features of OpenMP

- Easy parallelization
- Shared memory architecture
- Multicore processor support
- Portable across platforms
- Improved performance

---

# OpenMP Fork-Join Model

OpenMP uses Fork-Join execution model.

## Fork Phase

Master thread creates worker threads.

---

## Parallel Execution

Threads execute operations simultaneously.

---

## Join Phase

Threads combine results and terminate.

---

# OpenMP Reduction Clause

The reduction clause combines results from multiple threads safely.

General Syntax:

```cpp
#pragma omp parallel for reduction(operation:variable)
```

---

# Example: Sum Reduction

```cpp
#pragma omp parallel for reduction(+:sum)
```

Each thread calculates partial sum.

OpenMP automatically combines them.

---

# Example: Min Reduction

```cpp
#pragma omp parallel for reduction(min:minValue)
```

Finds minimum value across all threads.

---

# Example: Max Reduction

```cpp
#pragma omp parallel for reduction(max:maxValue)
```

Finds maximum value across all threads.

---

# Min Reduction

# What is Min Reduction?

Min Reduction finds the smallest value in dataset using parallel execution.

---

# Working of Min Reduction

## Step 1
Array divided among threads.

---

## Step 2
Each thread finds local minimum.

---

## Step 3
OpenMP combines local minimum values.

---

## Step 4
Final global minimum is produced.

---

# Advantages of Min Reduction

- Faster minimum search
- Efficient for large datasets
- Better CPU utilization

---

# Max Reduction

# What is Max Reduction?

Max Reduction finds largest value using multiple threads.

---

# Working of Max Reduction

## Step 1
Dataset divided among threads.

---

## Step 2
Each thread computes local maximum.

---

## Step 3
Partial maximum values are combined.

---

## Step 4
Final maximum value is produced.

---

# Sum Reduction

# What is Sum Reduction?

Sum Reduction calculates total sum of array elements using parallelism.

---

# Working of Sum Reduction

## Step 1
Array divided among threads.

---

## Step 2
Each thread calculates partial sum.

---

## Step 3
Partial sums are combined.

---

## Step 4
Final total sum is obtained.

---

# Average Reduction

# What is Average Reduction?

Average Reduction computes average value of dataset.

---

# Formula for Average

:contentReference[oaicite:0]{index=0}

---

# Working of Average Reduction

## Step 1
Calculate parallel sum.

---

## Step 2
Divide total sum by array size.

---

## Step 3
Final average value obtained.

---

# HPC Concepts Used

| HPC Concept | Explanation |
|-------------|-------------|
| Parallel Computing | Multiple operations execute simultaneously |
| Multithreading | Multiple threads process dataset |
| Shared Memory | Threads share same array |
| Synchronization | Combining thread results safely |
| Reduction Operation | Combining partial results |
| Scalability | Better performance with more cores |
| Speedup | Reduced execution time |

---

# Sequential vs Parallel Reduction

| Sequential Reduction | Parallel Reduction |
|----------------------|-------------------|
| Single thread | Multiple threads |
| Slower | Faster |
| One element at a time | Multiple elements together |
| Lower CPU utilization | Better CPU utilization |

---

# Advantages of Parallel Reduction

- Faster execution
- Better resource utilization
- Efficient for large arrays
- Scalable on multicore processors
- Reduced computation time

---

# Limitations of Parallel Reduction

- Thread synchronization overhead
- Additional thread management cost
- Less benefit for small datasets
- Shared memory limitations

---

# Performance Measurement

Important metrics used in HPC:

- Execution Time
- Speedup
- Efficiency
- Scalability

---

# Execution Time

Measures total program execution time.

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

:contentReference[oaicite:1]{index=1}

---

# Efficiency Formula

:contentReference[oaicite:2]{index=2}

---

# Scalability

Scalability measures ability of program to maintain performance as:
- Input size increases
- Number of processors increases

---

# Real World Applications

Parallel Reduction is used in:

- Scientific simulations
- Big Data analytics
- Artificial Intelligence
- Machine Learning
- Image processing
- High Performance Computing (HPC)

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

# Compilation Command

```bash
g++ -fopenmp program.cpp -o program
```

---

# Run Command

```bash
./program
```

---

# Important Viva Questions

## 1. What is Parallel Reduction?

A technique used to combine multiple values into single result using parallel computing.

---

## 2. What is OpenMP?

An API for parallel programming using multithreading.

---

## 3. What is reduction clause?

An OpenMP clause used to combine results from multiple threads.

---

## 4. What is Min Reduction?

Finding smallest value using parallel reduction.

---

## 5. What is Max Reduction?

Finding largest value using parallel reduction.

---

## 6. What is Sum Reduction?

Finding total sum using parallel execution.

---

## 7. What is Average Reduction?

Finding average value using parallel sum computation.

---

## 8. Why parallel reduction is faster?

Because multiple threads process data simultaneously.

---

## 9. What is speedup?

Performance improvement achieved using parallel execution.

---

## 10. What is scalability?

Ability to maintain performance with increasing processors.

---

## 11. What is shared memory architecture?

Memory shared among multiple processors or threads.

---

## 12. Which OpenMP clause combines thread results?

```cpp
reduction()
```

---

# Conclusion

Parallel Reduction using OpenMP demonstrates how mathematical operations such as:

- Minimum
- Maximum
- Sum
- Average

can be efficiently computed using multithreading.

OpenMP reduction operations improve:
- Execution speed
- CPU utilization
- Scalability

This experiment helps understand:
- Parallel computing
- Reduction operations
- OpenMP directives
- Performance analysis
- HPC optimization techniques