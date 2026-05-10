# Matrix Multiplication using CUDA C

---

# 📌 Aim

To implement Matrix Multiplication using CUDA C and understand GPU-based parallel computation.

---

# 🎯 Objective

Students should be able to:

- Understand CUDA programming
- Implement Matrix Multiplication using CUDA
- Understand GPU parallel execution
- Learn CUDA memory management
- Execute CUDA programs in CUDA environment
- Understand HPC concepts using GPU computing

---

# 📖 Theory

# What is CUDA?

CUDA (Compute Unified Device Architecture) is a parallel computing platform and programming model developed by NVIDIA.

CUDA allows developers to use NVIDIA GPUs for general-purpose parallel computing.

Normally:
- CPU performs sequential computation

Using CUDA:
- GPU performs thousands of operations simultaneously

---

# Why CUDA is Important?

Modern GPUs contain:
- Thousands of processing cores
- Massive parallel execution capability

CUDA uses these GPU cores for:
- Scientific simulations
- Matrix operations
- Machine learning
- Artificial intelligence
- Image processing
- High Performance Computing (HPC)

---

# CPU vs GPU

| CPU | GPU |
|-----|-----|
| Few powerful cores | Thousands of lightweight cores |
| Sequential execution | Parallel execution |
| Better for logic operations | Better for mathematical operations |
| Slower for large matrix operations | Faster for large matrix operations |

---

# CUDA Architecture

CUDA uses:

- Threads
- Blocks
- Grids

---

# Thread

A thread is smallest execution unit in CUDA.

Each thread performs one computation.

For matrix multiplication:
- One thread computes one matrix element.

---

# Block

A block is a collection of threads.

Threads in same block:
- Execute together
- Share resources

---

# Grid

A grid is collection of blocks.

Entire CUDA kernel executes as grid of blocks.

---

# CUDA Programming Model

CUDA follows:
```text
Host → Device Model
```

| Component | Description |
|------------|-------------|
| Host | CPU execution |
| Device | GPU execution |

---

# What is Matrix Multiplication?

Matrix multiplication combines two matrices to produce a third matrix.

---

# Example

Matrix A:

```text
1 2
3 4
```

Matrix B:

```text
5 6
7 8
```

Result Matrix C:

```text
19 22
43 50
```

---

# Formula for Matrix Multiplication

:contentReference[oaicite:0]{index=0}

---

# Why Matrix Multiplication is Suitable for CUDA?

Each output matrix element can be computed independently.

Example:

```text
C[0][0]
C[0][1]
C[1][0]
C[1][1]
```

All elements can be calculated simultaneously.

This makes matrix multiplication ideal for GPU parallelism.

---

# Sequential Matrix Multiplication

In CPU execution:
- Matrix elements computed one by one
- Execution becomes slow for large matrices

Time Complexity:

:contentReference[oaicite:1]{index=1}

---

# Parallel Matrix Multiplication

In CUDA:
- Thousands of GPU threads execute simultaneously
- Each thread computes one output element

This significantly improves performance.

---

# Steps for Matrix Multiplication using CUDA

# Step 1: Matrix Initialization

Matrices are created and initialized.

Example:

```cpp
A[i][j] = value;
B[i][j] = value;
```

---

# Step 2: Memory Allocation

Memory allocated on:
- Host (CPU)
- Device (GPU)

---

# Host Memory Allocation

CPU memory allocated using:

```cpp
malloc()
```

or normal arrays.

---

# Device Memory Allocation

GPU memory allocated using:

```cpp
cudaMalloc()
```

---

# Why Separate Memory Needed?

CPU and GPU have separate memory spaces.

Data must be copied between them.

---

# Step 3: Data Transfer

Input matrices copied from CPU → GPU.

CUDA function used:

```cpp
cudaMemcpy()
```

---

# Data Transfer Directions

| Transfer Type | Meaning |
|---------------|----------|
| HostToDevice | CPU → GPU |
| DeviceToHost | GPU → CPU |

---

# Step 4: Kernel Launch

CUDA kernel launched using:

```cpp
kernel<<<blocks, threads>>>();
```

Kernel executes on GPU.

---

# What is CUDA Kernel?

A kernel is GPU function executed by multiple threads simultaneously.

Each thread computes:
- One matrix element

---

# Thread Index Calculation

CUDA thread index:

```cpp
int row = blockIdx.y * blockDim.y + threadIdx.y;
int col = blockIdx.x * blockDim.x + threadIdx.x;
```

---

# Explanation of CUDA Variables

| Variable | Purpose |
|----------|----------|
| `threadIdx.x` | Thread number in x-direction |
| `threadIdx.y` | Thread number in y-direction |
| `blockIdx.x` | Block number in x-direction |
| `blockIdx.y` | Block number in y-direction |
| `blockDim.x` | Threads per block in x-direction |
| `blockDim.y` | Threads per block in y-direction |

---

# Matrix Element Computation

Each thread calculates:

```text
One element of result matrix
```

Example:

| Thread | Computes |
|--------|-----------|
| Thread 1 | C[0][0] |
| Thread 2 | C[0][1] |
| Thread 3 | C[1][0] |

---

# Step 5: Device Synchronization

CUDA function:

```cpp
cudaDeviceSynchronize()
```

Ensures:
- All GPU threads complete execution

before moving further.

---

# Step 6: Data Retrieval

Result matrix copied back from GPU → CPU.

Using:

```cpp
cudaMemcpy()
```

---

# Step 7: Memory Deallocation

GPU memory released using:

```cpp
cudaFree()
```

CPU memory released using:

```cpp
free()
```

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

# HPC Concepts Used

| HPC Concept | Explanation |
|-------------|-------------|
| Parallel Computing | Multiple operations execute simultaneously |
| GPU Computing | Computation using GPU |
| Massive Parallelism | Thousands of threads execute together |
| Multithreading | Multiple GPU threads |
| Scalability | Better performance for large matrices |
| Shared Processing | GPU cores work simultaneously |

---

# Why CUDA is Used Instead of Normal C++?

Normal C++:
- Executes sequentially on CPU
- Slower for large matrix operations

CUDA:
- Uses GPU parallelism
- Much faster for mathematical computations

Matrix multiplication involves:
- Large repetitive computations
- Independent calculations

Hence CUDA is preferred in HPC.

---

# Advantages of CUDA Matrix Multiplication

- Faster execution
- Massive parallelism
- Better GPU utilization
- Efficient for large matrices
- Reduced execution time

---

# Limitations

- Requires NVIDIA GPU
- CUDA Toolkit installation required
- Memory transfer overhead
- More complex programming model

---

# CUDA Compilation

CUDA compiler:

```bash
nvcc
```

---

# Compile Command

```bash
nvcc matrix_mul.cu -o matrix_mul
```

---

# Run Command

```bash
./matrix_mul
```

---

# CUDA Environment Setup

# Step 1: Install CUDA Toolkit

Download from NVIDIA website.

Includes:
- CUDA compiler
- Libraries
- GPU drivers

---

# Step 2: Configure Environment Variables

Set:
- PATH
- LD_LIBRARY_PATH

---

# Step 3: Write CUDA Program

Programs saved with:

```text
.cu
```

extension.

---

# Step 4: Compile CUDA Program

Using:

```bash
nvcc
```

---

# Step 5: Execute Program

Run executable file.

---

# Real World Applications

CUDA Matrix Multiplication used in:

- Artificial Intelligence
- Deep Learning
- Neural Networks
- Scientific Simulations
- Image Processing
- Computer Vision
- Big Data Analytics
- HPC applications

---

# Performance Measurement

Important CUDA performance metrics:

- Execution Time
- Speedup
- Throughput
- GPU Utilization

---

# Speedup Formula

:contentReference[oaicite:2]{index=2}

---

# Efficiency Formula

:contentReference[oaicite:3]{index=3}

---

# Important Viva Questions

## 1. What is CUDA?

CUDA is a parallel computing platform developed by NVIDIA.

---

## 2. Why CUDA is used?

To utilize GPU for parallel computations.

---

## 3. What is matrix multiplication?

Combining two matrices to produce third matrix.

---

## 4. Why matrix multiplication is suitable for CUDA?

Because each output element can be computed independently.

---

## 5. What is CUDA kernel?

A function executed on GPU.

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

## 11. What is nvcc?

CUDA compiler provided by NVIDIA.

---

## 12. What is massive parallelism?

Execution of thousands of operations simultaneously.

---

# Conclusion

CUDA Matrix Multiplication demonstrates GPU-based parallel computing for large mathematical computations.

CUDA enables:
- Massive parallel execution
- Faster matrix operations
- Better hardware utilization

This experiment helps understand:
- CUDA architecture
- GPU programming
- Matrix multiplication
- Kernel execution
- Thread organization
- High Performance Computing concepts