# Code Explanation (HPC Perspective)

This program performs **Addition of Two Large Vectors using CUDA**.

The main goal in **High Performance Computing (HPC)** is to improve computational speed using massive parallel processing on GPU architecture.

Instead of performing vector addition sequentially on CPU:
- CUDA executes operations on GPU
- Thousands of threads run simultaneously
- Execution becomes significantly faster for large datasets

---

# Why CUDA is Used Instead of Normal C++?

Normal C++ programs usually execute on CPU.

CPU:
- Has fewer cores
- Optimized for sequential execution
- Good for control operations

However, vector addition involves:
- Repeating same operation many times
- Independent computations

This type of problem is ideal for GPU parallelism.

---

# CPU vs GPU

| CPU | GPU |
|-----|-----|
| Few powerful cores | Thousands of lightweight cores |
| Sequential processing | Massive parallel processing |
| Better for logic/control | Better for mathematical operations |
| Slower for large vector operations | Faster for large vector operations |

---

# Why CUDA is Important in HPC?

CUDA allows:
- Massive parallelism
- Faster computations
- Better hardware utilization
- Scientific computing acceleration

CUDA is widely used in:
- Artificial Intelligence
- Machine Learning
- Deep Learning
- Image Processing
- Scientific Simulations
- High Performance Computing

---

# What is CUDA?

CUDA (Compute Unified Device Architecture) is a parallel computing platform developed by NVIDIA.

It allows programmers to:
- Write programs for GPU execution
- Use GPU cores for general computations
- Accelerate large mathematical operations

CUDA programs are written using:
- C
- C++
- CUDA extensions

---

# CUDA Programming Model

CUDA uses:
- Threads
- Blocks
- Grids

---

# Thread

A thread is the smallest execution unit.

Each thread performs one operation.

In vector addition:
- One thread adds one vector element

---

# Block

A block is a group of threads.

Threads inside same block:
- Execute together
- Share resources

---

# Grid

A grid is collection of blocks.

Entire CUDA program runs as grid of blocks.

---

# Header File

```cpp
#include <stdio.h>
```

Used for input and output operations.

---

# CUDA Kernel Function

```cpp
__global__ void vectorAdd(int *A,
                          int *B,
                          int *C,
                          int n)
```

This is CUDA kernel function.

---

# What is `__global__`?

`__global__` tells CUDA that:
- Function executes on GPU
- Function is called from CPU

Kernel functions run in parallel on GPU threads.

---

# Kernel Parameters

| Parameter | Purpose |
|-----------|----------|
| `A` | First vector |
| `B` | Second vector |
| `C` | Result vector |
| `n` | Vector size |

---

# Thread Index Calculation

```cpp
int i = blockIdx.x * blockDim.x + threadIdx.x;
```

This calculates unique index for each thread.

---

# Explanation of CUDA Variables

| Variable | Purpose |
|----------|----------|
| `threadIdx.x` | Thread number inside block |
| `blockIdx.x` | Block number |
| `blockDim.x` | Number of threads per block |

---

# Why Thread Index Needed?

Each thread must process different vector element.

Example:

| Thread | Operation |
|--------|------------|
| Thread 0 | C[0] = A[0] + B[0] |
| Thread 1 | C[1] = A[1] + B[1] |
| Thread 2 | C[2] = A[2] + B[2] |

---

# Boundary Check

```cpp
if (i < n)
```

Ensures thread does not access invalid memory.

---

# Vector Addition Formula

:contentReference[oaicite:0]{index=0}

---

# Addition Operation

```cpp
C[i] = A[i] + B[i];
```

Each GPU thread performs one addition.

---

# Main Function

```cpp
int main()
```

Program execution starts here.

---

# Vector Size

```cpp
int n = 1024;
```

Defines total vector elements.

---

# Host Arrays

```cpp
int h_A[n], h_B[n], h_C[n];
```

These arrays exist in CPU memory.

---

# Why `h_` Prefix?

`h_` means:
```text
Host Memory
```

Stored on CPU side.

---

# Initialize Vectors

```cpp
for (int i = 0; i < n; i++)
```

Fills vectors with values.

---

# Initialize First Vector

```cpp
h_A[i] = i;
```

Example:
```text
0 1 2 3 ...
```

---

# Initialize Second Vector

```cpp
h_B[i] = i * 2;
```

Example:
```text
0 2 4 6 ...
```

---

# Device Pointers

```cpp
int *d_A, *d_B, *d_C;
```

Pointers for GPU memory.

---

# Why `d_` Prefix?

`d_` means:
```text
Device Memory
```

Stored on GPU side.

---

# GPU Memory Allocation

```cpp
cudaMalloc((void**)&d_A,
           n * sizeof(int));
```

Allocates memory on GPU.

---

# Why `cudaMalloc()`?

GPU memory is separate from CPU memory.

CUDA provides:
```cpp
cudaMalloc()
```

for GPU allocation.

---

# Copy Host to Device

```cpp
cudaMemcpy(d_A,
           h_A,
           n * sizeof(int),
           cudaMemcpyHostToDevice);
```

Transfers data from CPU → GPU.

---

# Why Data Transfer Needed?

CPU and GPU have separate memory spaces.

Data must be copied before GPU processing.

---

# Block Size

```cpp
int blockSize = 256;
```

Defines:
```text
256 threads per block
```

---

# Grid Size

```cpp
int gridSize =
(n + blockSize - 1) / blockSize;
```

Calculates required blocks.

---

# Why Grid Size Calculation Needed?

Ensures enough threads for all vector elements.

---

# Kernel Launch

```cpp
vectorAdd<<<gridSize,
            blockSize>>>
            (d_A, d_B, d_C, n);
```

Launches GPU kernel.

---

# CUDA Execution Syntax

```cpp
<<<blocks, threads>>>
```

Defines:
- Number of blocks
- Threads per block

---

# GPU Parallel Execution

After kernel launch:
- Thousands of GPU threads execute simultaneously
- Each thread computes one addition

---

# Copy Result Back

```cpp
cudaMemcpy(h_C,
           d_C,
           n * sizeof(int),
           cudaMemcpyDeviceToHost);
```

Transfers result from GPU → CPU.

---

# Display Output

```cpp
printf("%d + %d = %d\n",
       h_A[i],
       h_B[i],
       h_C[i]);
```

Prints vector addition results.

---

# Free GPU Memory

```cpp
cudaFree(d_A);
```

Releases GPU memory.

---

# Why Memory Freeing Important?

Prevents:
- Memory leaks
- Resource wastage

---

# CUDA Execution Flow

```text
CPU → Allocate Memory
CPU → Initialize Data
CPU → Copy Data to GPU
GPU → Execute Kernel
GPU → Perform Parallel Addition
GPU → Copy Result to CPU
CPU → Display Output
```

---

# HPC Concepts Used in This Program

| HPC Concept | Used In |
|-------------|----------|
| Parallel Computing | GPU thread execution |
| Massive Parallelism | Thousands of threads |
| GPU Computing | CUDA kernel execution |
| Multithreading | Multiple GPU threads |
| Shared Processing | GPU cores working together |
| Scalability | Better performance for large vectors |

---

# Why Vector Addition is Parallel?

Each vector element is independent.

Example:

```text
C[0] depends only on A[0] and B[0]
```

No dependency between elements.

Hence:
- All additions can occur simultaneously.

---

# Advantages of CUDA Vector Addition

- Very fast for large vectors
- Massive parallelism
- Efficient GPU utilization
- Reduced execution time
- Suitable for HPC workloads

---

# Limitations

- Requires NVIDIA GPU
- CUDA Toolkit required
- Memory transfer overhead
- More complex programming model

---

# CUDA Compilation Command

```bash
nvcc vector_add.cu -o vector_add
```

---

# Run Command

```bash
./vector_add
```

---

# Important Viva Questions

## 1. What is CUDA?

CUDA is a parallel computing platform developed by NVIDIA.

---

## 2. Why CUDA is used?

To utilize GPU for parallel computation.

---

## 3. What is GPU computing?

Using GPU for general-purpose computations.

---

## 4. What is CUDA kernel?

A function executed on GPU.

---

## 5. What is thread in CUDA?

Smallest execution unit.

---

## 6. What is block in CUDA?

Group of threads.

---

## 7. What is grid in CUDA?

Collection of blocks.

---

## 8. What is cudaMalloc()?

Used to allocate memory on GPU.

---

## 9. What is cudaMemcpy()?

Transfers data between CPU and GPU.

---

## 10. Why vector addition is suitable for CUDA?

Because each addition operation is independent.

---

## 11. What is massive parallelism?

Execution of thousands of operations simultaneously.

---

## 12. What is advantage of GPU over CPU?

GPU provides much higher parallel processing capability.

---

# Final Conclusion

This CUDA program demonstrates vector addition using GPU-based parallel computing.

CUDA allows:
- Massive parallel execution
- Faster mathematical operations
- Better hardware utilization

The experiment helps understand:
- CUDA architecture
- GPU programming
- Kernel execution
- Thread organization
- HPC acceleration techniques

Vector addition is an ideal example of parallel computing because all operations can execute independently and simultaneously on GPU cores.