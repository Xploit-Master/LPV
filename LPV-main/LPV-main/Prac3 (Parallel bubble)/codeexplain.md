# Code Explanation (HPC Perspective)

This program implements both **Sequential Bubble Sort** and **Parallel Bubble Sort** using **OpenMP**.

The purpose of this program in **High Performance Computing (HPC)** is to compare the execution time of sequential and parallel sorting algorithms and understand how parallelism improves performance.

---

# Header Files

```cpp
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <omp.h>
```

## Explanation

| Header File | Purpose |
|-------------|----------|
| `iostream` | Used for input and output |
| `vector` | Dynamic array container |
| `cstdlib` | Used for random number generation |
| `ctime` | Used for time-based random seed |
| `omp.h` | OpenMP library for parallel programming |

---

# Namespace

```cpp
using namespace std;
```

Used to avoid writing `std::` repeatedly.

---

# Define Array Size

```cpp
#define SIZE 10000
```

Defines total number of elements in array.

The array size is 10000 integers.

---

# Sequential Bubble Sort

```cpp
void bubbleSortSeq(vector<int>& arr)
```

This function implements normal sequential Bubble Sort.

---

# Outer Loop

```cpp
for (int i = 0; i < n - 1; i++)
```

Controls number of passes.

Bubble Sort requires multiple passes through array.

---

# Inner Loop

```cpp
for (int j = 0; j < n - i - 1; j++)
```

Traverses array elements.

After every iteration:
- Largest element moves to correct position.

---

# Comparison Condition

```cpp
if (arr[j] > arr[j + 1])
```

Checks whether adjacent elements are in wrong order.

---

# Swap Operation

```cpp
swap(arr[j], arr[j + 1]);
```

Swaps elements if left element is greater.

---

# Time Complexity of Sequential Bubble Sort

:contentReference[oaicite:0]{index=0}

Because nested loops are used.

---

# Parallel Bubble Sort

```cpp
void bubbleSortParallel(vector<int>& arr)
```

This function implements Bubble Sort using OpenMP parallelism.

---

# Odd-Even Transposition Method

Parallel Bubble Sort uses:
- Even phase
- Odd phase

This allows multiple comparisons simultaneously.

---

# Outer Loop

```cpp
for (int i = 0; i < n; i++)
```

Controls sorting iterations.

---

# Even Phase

```cpp
#pragma omp parallel for
for (int j = 0; j < n - 1; j += 2)
```

## Explanation

OpenMP distributes loop iterations among multiple threads.

Threads compare:
- `(0,1)`
- `(2,3)`
- `(4,5)`

simultaneously.

---

# Even Phase Comparison

```cpp
if (arr[j] > arr[j + 1])
```

Checks whether adjacent elements need swapping.

---

# Even Phase Swap

```cpp
swap(arr[j], arr[j + 1]);
```

Performs parallel swapping.

---

# Odd Phase

```cpp
#pragma omp parallel for
for (int j = 1; j < n - 1; j += 2)
```

## Explanation

Threads compare:
- `(1,2)`
- `(3,4)`
- `(5,6)`

simultaneously.

---

# Why Even and Odd Phases?

Without separation:
- Threads may access same elements simultaneously.
- Race conditions may occur.

Even-Odd strategy prevents conflicts.

---

# HPC Concept: Parallelism

Multiple comparisons execute together on different CPU cores.

This improves performance.

---

# Random Array Generation

```cpp
void generateRandom(vector<int>& arr)
```

Generates random array values.

---

# Random Value Assignment

```cpp
x = rand() % 100000;
```

Generates random integers between:
```text
0 to 99999
```

---

# Main Function

```cpp
int main()
```

Program execution starts here.

---

# Array Declaration

```cpp
vector<int> arr(SIZE), temp;
```

## Explanation

| Variable | Purpose |
|----------|----------|
| `arr` | Original random array |
| `temp` | Copy used for sorting |

---

# Random Seed Initialization

```cpp
srand(time(0));
```

Ensures different random values every execution.

---

# Generate Random Data

```cpp
generateRandom(arr);
```

Fills array with random numbers.

---

# Timing Variables

```cpp
double start, end;
```

Stores execution start and end times.

---

# Sequential Bubble Sort Timing

```cpp
start = omp_get_wtime();
bubbleSortSeq(temp);
end = omp_get_wtime();
```

## Explanation

Measures sequential execution time.

---

# Display Sequential Time

```cpp
cout << "Sequential Bubble Sort Time: " << (end - start) << " sec\n";
```

Prints sequential sorting time.

---

# Parallel Bubble Sort Timing

```cpp
start = omp_get_wtime();
bubbleSortParallel(temp);
end = omp_get_wtime();
```

Measures parallel execution time.

---

# Display Parallel Time

```cpp
cout << "Parallel Bubble Sort Time: " << (end - start) << " sec\n";
```

Prints parallel sorting time.

---

# Return Statement

```cpp
return 0;
```

Indicates successful execution.

---

# OpenMP Compilation Command

```bash
g++ bubble.cpp -fopenmp -o bubble
./bubble
```

---

# HPC Concepts Used in This Program

| HPC Concept | Used In |
|-------------|----------|
| Parallel Computing | OpenMP parallel loops |
| Multithreading | Multiple threads sorting simultaneously |
| Shared Memory | Threads access same array |
| Synchronization | Even-Odd phase coordination |
| Speedup | Faster execution using threads |
| Load Distribution | Loop iterations divided among threads |

---

# Sequential vs Parallel Bubble Sort

| Sequential Bubble Sort | Parallel Bubble Sort |
|------------------------|----------------------|
| Single thread | Multiple threads |
| Slower | Faster |
| One comparison at a time | Multiple comparisons together |
| Lower CPU utilization | Better CPU utilization |

---

# Performance Measurement

Execution time is measured using:

```cpp
omp_get_wtime()
```

This function returns wall-clock execution time.

---

# Speedup Formula

:contentReference[oaicite:1]{index=1}

---

# Efficiency Formula

:contentReference[oaicite:2]{index=2}

---

# Important Viva Questions

## 1. What is Bubble Sort?

Bubble Sort is a sorting algorithm that repeatedly swaps adjacent elements.

---

## 2. Why is Bubble Sort called Bubble Sort?

Because larger elements move upward like bubbles.

---

## 3. What is time complexity of Bubble Sort?

:contentReference[oaicite:3]{index=3}

---

## 4. What is OpenMP?

An API for parallel programming using multithreading.

---

## 5. Why parallel Bubble Sort is faster?

Because multiple comparisons occur simultaneously.

---

## 6. What is multithreading?

Execution of multiple threads simultaneously.

---

## 7. What is shared memory architecture?

Memory shared among multiple threads.

---

## 8. Why Even-Odd phases are used?

To avoid race conditions during parallel execution.

---

## 9. What is race condition?

Incorrect behavior caused by simultaneous access to shared data.

---

## 10. Which OpenMP directive is used?

```cpp
#pragma omp parallel for
```

---

# Final Conclusion

This program demonstrates how **Bubble Sort** can be parallelized using **OpenMP** in HPC environments.

Parallel Bubble Sort improves CPU utilization and reduces execution time by distributing comparisons among multiple threads.

The experiment helps understand:
- Parallel programming
- OpenMP directives
- Performance measurement
- Multithreading
- HPC optimization concepts