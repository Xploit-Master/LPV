# Code Explanation (HPC Perspective)

This program implements both:

- Sequential Merge Sort
- Parallel Merge Sort using OpenMP

The main goal in **High Performance Computing (HPC)** is to compare sequential and parallel execution and understand how multithreading improves sorting performance.

---

# Header Files

## Sequential Version Headers

```cpp
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
```

## Parallel Version Headers

```cpp
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <omp.h>
```

---

# Explanation of Header Files

| Header File | Purpose |
|-------------|----------|
| `iostream` | Input and output operations |
| `vector` | Dynamic array storage |
| `cstdlib` | Random number generation |
| `ctime` | Time-based random seed |
| `chrono` | Used for execution time measurement |
| `omp.h` | OpenMP library for parallel programming |

---

# Namespace

```cpp
using namespace std;
```

Used to avoid writing `std::`.

---

# Chrono Namespace

```cpp
using namespace std::chrono;
```

Used for time measurement in sequential version.

---

# Array Size

```cpp
#define SIZE 10000
```

Defines total number of array elements.

---

# Merge Function

```cpp
void merge(vector<int>& arr,
           int left,
           int mid,
           int right)
```

This function merges two sorted subarrays into one sorted array.

---

# Left and Right Subarrays

```cpp
vector<int> leftArray(arr.begin() + left,
                      arr.begin() + mid + 1);

vector<int> rightArray(arr.begin() + mid + 1,
                       arr.begin() + right + 1);
```

## Explanation

The original array is divided into:
- Left half
- Right half

Temporary vectors store divided subarrays.

---

# Merge Index Variables

```cpp
int i = 0;
int j = 0;
int k = left;
```

## Purpose

| Variable | Purpose |
|----------|----------|
| `i` | Traverses left array |
| `j` | Traverses right array |
| `k` | Traverses original array |

---

# Merge Comparison

```cpp
while (i < leftArray.size() &&
       j < rightArray.size())
```

Compares elements from both arrays.

---

# Comparison Condition

```cpp
if (leftArray[i] <= rightArray[j])
```

Checks which element is smaller.

---

# Copy Smaller Element

```cpp
arr[k++] = leftArray[i++];
```

or

```cpp
arr[k++] = rightArray[j++];
```

Smaller element is inserted into sorted array.

---

# Remaining Elements

```cpp
while (i < leftArray.size())
```

and

```cpp
while (j < rightArray.size())
```

Copies leftover elements into final array.

---

# Sequential Merge Sort

```cpp
void mergeSortSequential(vector<int>& arr,
                         int left,
                         int right)
```

Implements normal recursive Merge Sort.

---

# Base Condition

```cpp
if (left < right)
```

Stops recursion when array size becomes 1.

---

# Middle Index

```cpp
int mid = (left + right) / 2;
```

Divides array into two halves.

---

# Recursive Calls

```cpp
mergeSortSequential(arr, left, mid);

mergeSortSequential(arr, mid + 1, right);
```

Recursively sorts:
- Left half
- Right half

---

# Merge Call

```cpp
merge(arr, left, mid, right);
```

Combines sorted halves.

---

# Time Complexity of Merge Sort

:contentReference[oaicite:0]{index=0}

Efficient for large datasets.

---

# Parallel Merge Sort

```cpp
void mergeSortParallel(vector<int>& arr,
                       int left,
                       int right,
                       int depth)
```

Implements Merge Sort using OpenMP parallelism.

---

# Depth Parameter

```cpp
int depth
```

Controls recursion depth for thread creation.

---

# Why Depth Control Needed?

Without limit:
- Too many threads may be created
- System overhead increases
- Performance decreases

---

# Sequential Fallback

```cpp
if (depth <= 0)
```

When depth becomes zero:
- Sequential sorting is used
- Prevents excessive thread creation

---

# OpenMP Parallel Sections

```cpp
#pragma omp parallel sections
```

Creates parallel execution regions.

---

# OpenMP Section

```cpp
#pragma omp section
```

Defines independent tasks.

---

# Parallel Recursive Calls

```cpp
mergeSortParallel(arr,
                  left,
                  mid,
                  depth - 1);
```

and

```cpp
mergeSortParallel(arr,
                  mid + 1,
                  right,
                  depth - 1);
```

Left and right subarrays are sorted simultaneously.

---

# HPC Concept: Divide and Conquer

Merge Sort naturally supports parallelism because:
- Left and right halves are independent
- Both can execute simultaneously

---

# Generate Random Array

```cpp
void generateRandomArray(vector<int>& arr)
```

Creates random input dataset.

---

# Random Number Generation

```cpp
arr[i] = rand() % 100000;
```

Generates random integers.

---

# Print Array Function

```cpp
void printArray(vector<int>& arr,
                int limit = 20)
```

Prints first few elements of array.

Used for output visualization.

---

# Main Function

```cpp
int main()
```

Program execution starts here.

---

# Array Declaration

```cpp
vector<int> arr(SIZE);
vector<int> temp;
```

## Explanation

| Variable | Purpose |
|----------|----------|
| `arr` | Original random array |
| `temp` | Temporary copy for sorting |

---

# Random Seed

```cpp
srand(time(0));
```

Ensures different random values every run.

---

# Generate Random Data

```cpp
generateRandomArray(arr);
```

Fills array with random numbers.

---

# Sequential Time Measurement (Chrono Version)

```cpp
auto start1 = high_resolution_clock::now();
```

Stores starting time.

---

# End Time

```cpp
auto end1 = high_resolution_clock::now();
```

Stores ending time.

---

# Execution Time Calculation

```cpp
duration<double>(end1 - start1).count();
```

Calculates total execution time.

---

# OpenMP Time Measurement

```cpp
start = omp_get_wtime();
```

and

```cpp
end = omp_get_wtime();
```

Used in OpenMP version for performance measurement.

---

# Sequential Merge Sort Execution

```cpp
mergeSortSequential(temp,
                    0,
                    SIZE - 1);
```

Starts sequential sorting.

---

# Parallel Merge Sort Execution

```cpp
mergeSortParallel(temp,
                  0,
                  SIZE - 1,
                  4);
```

Starts parallel sorting.

---

# Depth Value

```cpp
4
```

Defines recursion depth for parallel threads.

---

# Performance Analysis

```cpp
cout << "Speedup: "
     << sequentialTime / parallelTime;
```

Measures parallel performance improvement.

---

# Speedup Formula

:contentReference[oaicite:1]{index=1}

---

# Efficiency Formula

:contentReference[oaicite:2]{index=2}

---

# HPC Concepts Used in This Program

| HPC Concept | Used In |
|-------------|----------|
| Parallel Computing | OpenMP parallel sections |
| Divide and Conquer | Merge Sort recursion |
| Multithreading | Parallel recursive calls |
| Shared Memory | Shared array access |
| Synchronization | Merge operation |
| Load Distribution | Subarray division |
| Scalability | More threads improve performance |

---

# Sequential vs Parallel Merge Sort

| Sequential Merge Sort | Parallel Merge Sort |
|-----------------------|---------------------|
| Single thread | Multiple threads |
| Slower | Faster |
| One subarray at a time | Multiple subarrays together |
| Lower CPU utilization | Better CPU utilization |

---

# Important Viva Questions

## 1. What is Merge Sort?

Merge Sort is a divide-and-conquer sorting algorithm.

---

## 2. What is Divide and Conquer?

Breaking problem into smaller subproblems.

---

## 3. What is time complexity of Merge Sort?

:contentReference[oaicite:3]{index=3}

---

## 4. Why Merge Sort is suitable for parallelism?

Because left and right subarrays can be processed independently.

---

## 5. What is OpenMP?

An API for parallel programming using multithreading.

---

## 6. Why `parallel sections` is used?

To execute independent sections simultaneously.

---

## 7. What is scalability?

Ability to maintain performance with increasing processors.

---

## 8. What is speedup?

Performance improvement achieved using parallel execution.

---

## 9. What is synchronization?

Coordination among threads to maintain correctness.

---

## 10. What is shared memory architecture?

Memory shared among multiple processors or threads.

---

# Final Conclusion

This program demonstrates how **Merge Sort** can be parallelized using **OpenMP** in HPC environments.

The divide-and-conquer nature of Merge Sort makes it highly suitable for parallel processing.

Parallel Merge Sort improves:
- Sorting performance
- CPU utilization
- Scalability on multicore systems

This experiment helps understand:
- Parallel programming
- OpenMP directives
- Merge Sort algorithm
- Performance analysis
- HPC optimization techniques