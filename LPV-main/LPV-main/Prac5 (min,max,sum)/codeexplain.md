# Code Explanation (HPC Perspective)

This program implements:

- Minimum Operation
- Maximum Operation
- Sum Operation
- Average Operation

using reduction concepts in C++.

The purpose of this program in **High Performance Computing (HPC)** is to understand how mathematical operations can be efficiently performed on datasets.

The original practical uses OpenMP reduction clauses for parallel execution.  
This modified version works on all compilers without OpenMP support.

---

# Header Files

```cpp
#include <iostream>
#include <vector>
#include <chrono>
```

---

# Explanation of Header Files

| Header File | Purpose |
|-------------|----------|
| `iostream` | Input and output operations |
| `vector` | Dynamic array storage |
| `chrono` | Measures execution time |

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

Used for time measurement.

---

# Min Function

```cpp
int minval(vector<int>& arr)
```

This function finds the minimum value from the array.

---

# Minimum Variable

```cpp
int minimum = arr[0];
```

Stores current minimum value.

Initially first element is considered minimum.

---

# Traversing Array

```cpp
for (int i = 0; i < arr.size(); i++)
```

Traverses entire array.

---

# Minimum Comparison

```cpp
if (arr[i] < minimum)
```

Checks whether current element is smaller.

---

# Update Minimum

```cpp
minimum = arr[i];
```

Updates minimum value.

---

# Return Minimum

```cpp
return minimum;
```

Returns final minimum value.

---

# Max Function

```cpp
int maxval(vector<int>& arr)
```

Finds maximum value in array.

---

# Maximum Variable

```cpp
int maximum = arr[0];
```

Initially first element is considered maximum.

---

# Maximum Comparison

```cpp
if (arr[i] > maximum)
```

Checks whether current element is larger.

---

# Update Maximum

```cpp
maximum = arr[i];
```

Updates maximum value.

---

# Return Maximum

```cpp
return maximum;
```

Returns final maximum value.

---

# Sum Function

```cpp
int sum(vector<int>& arr)
```

Calculates total sum of all elements.

---

# Total Variable

```cpp
int total = 0;
```

Stores cumulative sum.

---

# Sum Calculation

```cpp
total += arr[i];
```

Adds each array element into total.

---

# Return Sum

```cpp
return total;
```

Returns total sum.

---

# Average Function

```cpp
double average(vector<int>& arr)
```

Calculates average of array elements.

---

# Call Sum Function

```cpp
int total = sum(arr);
```

Uses sum function to calculate total.

---

# Average Formula

:contentReference[oaicite:0]{index=0}

---

# Average Calculation

```cpp
return (double)total / arr.size();
```

Divides total sum by number of elements.

Typecasting to `double` ensures decimal output.

---

# Main Function

```cpp
int main()
```

Program execution starts here.

---

# User Input Size

```cpp
int n;
```

Stores number of elements.

---

# Read Number of Elements

```cpp
cin >> n;
```

User enters array size.

---

# Dynamic Array Creation

```cpp
vector<int> arr(n);
```

Creates dynamic array using vector.

---

# Input Array Elements

```cpp
for (int i = 0; i < n; i++)
```

Reads user input elements.

---

# Store Elements

```cpp
cin >> arr[i];
```

Stores each element into array.

---

# Time Measurement

```cpp
auto start1 = high_resolution_clock::now();
```

Stores starting execution time.

---

# End Time

```cpp
auto end1 = high_resolution_clock::now();
```

Stores ending execution time.

---

# Execution Time Calculation

```cpp
duration<double>(end1 - start1).count();
```

Calculates total execution time.

---

# Minimum Operation Execution

```cpp
int minimum = minval(arr);
```

Calls minimum function.

---

# Maximum Operation Execution

```cpp
int maximum = maxval(arr);
```

Calls maximum function.

---

# Sum Operation Execution

```cpp
int totalsum = sum(arr);
```

Calls sum function.

---

# Average Operation Execution

```cpp
double avg = average(arr);
```

Calls average function.

---

# Output Statements

```cpp
cout << "Minimum Value = "
```

Displays final results.

---

# HPC Concepts Used in This Program

| HPC Concept | Used In |
|-------------|----------|
| Reduction Operation | Min, Max, Sum, Average |
| Data Traversal | Iterating through dataset |
| Shared Computation | Common dataset processing |
| Performance Measurement | Execution time calculation |
| Scalability | Large dataset processing |
| Mathematical Reduction | Combining values into single result |

---

# Original OpenMP Reduction Version

In actual HPC implementation:

```cpp
#pragma omp parallel for reduction(min:minval)
```

OpenMP divides array among multiple threads.

Each thread:
- Computes local result
- Combines results automatically

---

# OpenMP Reduction Examples

# Min Reduction

```cpp
#pragma omp parallel for reduction(min:minval)
```

---

# Max Reduction

```cpp
#pragma omp parallel for reduction(max:maxval)
```

---

# Sum Reduction

```cpp
#pragma omp parallel for reduction(+:total)
```

---

# Why Reduction is Important in HPC?

Reduction operations:
- Improve performance
- Reduce computation time
- Utilize multiple CPU cores
- Handle large datasets efficiently

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
- Better CPU utilization
- Efficient for large datasets
- Improved scalability
- Reduced computation time

---

# Limitations

- Thread synchronization overhead
- Additional memory overhead
- Less benefit for very small datasets

---

# Important Viva Questions

## 1. What is Reduction?

Combining multiple values into single result.

---

## 2. What is Parallel Reduction?

Reduction performed using multiple threads simultaneously.

---

## 3. What is OpenMP?

An API for parallel programming using multithreading.

---

## 4. What is Min Reduction?

Finding smallest value using reduction.

---

## 5. What is Max Reduction?

Finding largest value using reduction.

---

## 6. What is Sum Reduction?

Finding total sum of all elements.

---

## 7. What is Average Reduction?

Finding average using total sum and array size.

---

## 8. Why reduction is useful in HPC?

Because it speeds up large computations.

---

## 9. What is speedup?

Improvement achieved using parallel execution.

---

## 10. What is scalability?

Ability to maintain performance with increasing processors.

---

## 11. Which OpenMP clause combines thread results?

```cpp
reduction()
```

---

## 12. What is shared memory architecture?

Memory shared among multiple threads.

---

# Final Conclusion

This program demonstrates reduction operations such as:

- Minimum
- Maximum
- Sum
- Average

The experiment helps understand:
- Reduction concepts
- Mathematical operations on datasets
- Performance measurement
- OpenMP reduction clauses
- HPC optimization techniques

Parallel reduction is an important concept in High Performance Computing because it allows efficient processing of large datasets using multiple processors.