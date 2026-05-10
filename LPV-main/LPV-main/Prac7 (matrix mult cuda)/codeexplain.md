# Code Explanation (HPC Perspective)

This program performs **Matrix Multiplication using CUDA C**.

The main purpose in **High Performance Computing (HPC)** is to accelerate matrix computations using GPU parallelism.

Instead of performing computations sequentially on CPU:
- CUDA executes matrix operations on GPU
- Multiple threads run simultaneously
- Large computations become much faster

---

# Why CUDA is Used Instead of Normal C++?

Normal C++ programs execute on CPU.

CPU:
- Has limited cores
- Better for sequential tasks
- Slower for repetitive matrix computations

Matrix multiplication involves:
- Large repetitive calculations
- Independent computations

CUDA uses GPU architecture to:
- Execute thousands of operations simultaneously
- Improve performance significantly

---

# CPU vs GPU

| CPU | GPU |
|-----|-----|
| Few powerful cores | Thousands of lightweight cores |
| Sequential processing | Massive parallel processing |
| Better for logic operations | Better for mathematical operations |
| Slower for matrix operations | Faster for matrix operations |

---

# Why Matrix Multiplication is Important in HPC?

Matrix multiplication is heavily used in:
- Artificial Intelligence
- Deep Learning
- Scientific Simulations
- Computer Graphics
- Machine Learning
- Data Analysis

CUDA accelerates these computations using GPU parallelism.

---

# What is CUDA?

CUDA (Compute Unified Device Architecture) is a parallel computing platform developed by NVIDIA.

CUDA allows:
- General-purpose GPU programming
- Massive parallel execution
- Faster scientific computations

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

A thread is smallest execution unit.

Each thread computes:
```text
One matrix element
```

---

# Block

A block contains multiple threads.

Threads inside same block:
- Execute together
- Share resources

---

# Grid

A grid is collection of blocks.

Entire CUDA kernel runs as grid.

---

# Header File

```cpp
#include <stdio.h>
```

Used for input and output functions.

---

# Matrix Size Definition

```cpp
#define N 4
```

Defines:
```text
Matrix dimension = 4 × 4
```

---

# CUDA Kernel Function

```cpp
__global__ void matrixMul(int A[N][N],
                          int B[N][N],
                          int C[N][N])
```

This is CUDA kernel function.

---

# What is `__global__`?

`__global__` means:
- Function executes on GPU
- Function is called from CPU

Kernel functions execute in parallel.

---

# Kernel Parameters

| Parameter | Purpose |
|-----------|----------|
| `A` | First matrix |
| `B` | Second matrix |
| `C` | Result matrix |

---

# Thread Row Calculation

```cpp
int row = threadIdx.y;
```

Gets row index of thread.

---

# Thread Column Calculation

```cpp
int col = threadIdx.x;
```

Gets column index of thread.

---

# Why Thread Indices are Used?

Each GPU thread computes:
```text
One element of result matrix
```

Example:

| Thread | Computes |
|--------|-----------|
| (0,0) | C[0][0] |
| (0,1) | C[0][1] |
| (1,0) | C[1][0] |

---

# Sum Variable

```cpp
int sum = 0;
```

Stores multiplication result for one matrix element.

---

# Matrix Multiplication Loop

```cpp
for (int k = 0; k < N; k++)
```

Traverses row and column elements.

---

# Matrix Multiplication Formula

:contentReference[oaicite:0]{index=0}

---

# Multiplication Operation

```cpp
sum += A[row][k] * B[k][col];
```

Performs:
- Multiplication
- Accumulation

for one output element.

---

# Store Result

```cpp
C[row][col] = sum;
```

Stores computed matrix element.

---

# Main Function

```cpp
int main()
```

Program execution starts here.

---

# Host Matrices

```cpp
int A[N][N], B[N][N], C[N][N];
```

Matrices stored in CPU memory.

---

# Matrix Initialization

```cpp
A[i][j] = i + j;
B[i][j] = i * j;
```

Initializes matrix values.

---

# Device Matrix Pointers

```cpp
int (*d_A)[N],
    (*d_B)[N],
    (*d_C)[N];
```

Pointers for GPU memory.

---

# Why `d_` Prefix?

`d_` means:
```text
Device Memory
```

Stored on GPU.

---

# GPU Memory Allocation

```cpp
cudaMalloc((void**)&d_A,
           sizeof(int) * N * N);
```

Allocates memory on GPU.

---

# Why `cudaMalloc()` Needed?

CPU and GPU use separate memory spaces.

GPU memory must be allocated separately.

---

# Copy Host to Device

```cpp
cudaMemcpy(d_A,
           A,
           sizeof(int) * N * N,
           cudaMemcpyHostToDevice);
```

Transfers matrix from CPU → GPU.

---

# Why Data Transfer Needed?

GPU cannot directly access CPU memory.

Data must be copied before computation.

---

# Thread Configuration

```cpp
dim3 threadsPerBlock(N, N);
```

Creates:
```text
N × N threads
```

Example:
```text
4 × 4 = 16 threads
```

---

# Why 2D Thread Structure Used?

Matrix is two-dimensional.

2D thread arrangement maps naturally to matrix elements.

---

# Kernel Launch

```cpp
matrixMul<<<1, threadsPerBlock>>>
(d_A, d_B, d_C);
```

Launches CUDA kernel.

---

# CUDA Launch Syntax

```cpp
<<<blocks, threads>>>
```

Here:
- 1 block used
- N × N threads used

---

# GPU Parallel Execution

All threads execute simultaneously.

Each thread computes:
```text
One output matrix element
```

---

# Copy Result Back

```cpp
cudaMemcpy(C,
           d_C,
           sizeof(int) * N * N,
           cudaMemcpyDeviceToHost);
```

Transfers result from GPU → CPU.

---

# Display Output

```cpp
printf("%d ", C[i][j]);
```

Prints final result matrix.

---

# Free GPU Memory

```cpp
cudaFree(d_A);
cudaFree(d_B);
cudaFree(d_C);
```

Releases GPU memory.

---

# Why Memory Freeing Important?

Prevents:
- Memory leaks
- GPU resource wastage

---

# CUDA Execution Flow

```text
CPU → Initialize Matrices
CPU → Allocate GPU Memory
CPU → Copy Data to GPU
GPU → Execute Kernel
GPU → Perform Matrix Multiplication
GPU → Copy Result to CPU
CPU → Display Output
```

---

# HPC Concepts Used in This Program

| HPC Concept | Used In |
|-------------|----------|
| Parallel Computing | GPU thread execution |
| Massive Parallelism | Multiple threads |
| GPU Computing | CUDA kernel execution |
| Multithreading | Many GPU threads |
| Shared Processing | GPU cores work together |
| Scalability | Efficient for large matrices |

---

# Why Matrix Multiplication is Parallel?

Each output matrix element:
- Independent of others
- Can be computed separately

Example:

```text
C[0][0]
C[0][1]
C[1][0]
```

All can execute simultaneously.

---

# Advantages of CUDA Matrix Multiplication

- Faster execution
- Better GPU utilization
- Massive parallelism
- Efficient for large matrices
- Reduced execution time

---

# Limitations

- Requires NVIDIA GPU
- CUDA Toolkit installation needed
- Separate memory management
- Programming complexity

---

# CUDA Compilation Command

```bash
nvcc matrix_mul.cu -o matrix_mul
```

---

# Run Command

```bash
./matrix_mul
```

---

# Important Viva Questions

## 1. What is CUDA?

CUDA is a GPU parallel computing platform developed by NVIDIA.

---

## 2. Why CUDA is used?

To utilize GPU for faster computations.

---

## 3. What is matrix multiplication?

Combining two matrices to produce third matrix.

---

## 4. Why matrix multiplication is suitable for CUDA?

Because output elements can be computed independently.

---

## 5. What is CUDA kernel?

A GPU function executed in parallel.

---

## 6. What is thread in CUDA?

Smallest execution unit.

---

## 7. What is block in CUDA?

Group of threads.

---

## 8. What is grid in CUDA?

Collection of blocks.

---

## 9. What is cudaMalloc()?

Allocates memory on GPU.

---

## 10. What is cudaMemcpy()?

Transfers data between CPU and GPU.

---

## 11. Why GPU is faster for matrix multiplication?

Because many matrix elements are computed simultaneously.

---

## 12. What is massive parallelism?

Execution of thousands of operations together.

---

# Final Conclusion

This CUDA program demonstrates Matrix Multiplication using GPU-based parallel computing.

CUDA enables:
- Massive parallel execution
- Faster matrix operations
- Better hardware utilization

This experiment helps understand:
- CUDA programming
- GPU architecture
- Matrix multiplication
- Kernel execution
- Thread organization
- HPC acceleration techniques

Matrix multiplication is an ideal HPC application because computations can be divided among thousands of GPU threads for high-speed execution.