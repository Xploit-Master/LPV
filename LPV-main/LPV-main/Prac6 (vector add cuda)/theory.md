# CUDA Program for Addition of Two Large Vectors

---

# 📌 Aim

To implement vector addition using CUDA programming and understand parallel execution on GPU architecture.

---

# 🎯 Objective

Students should be able to:

- Understand CUDA programming model
- Perform vector addition using CUDA
- Understand GPU parallel execution
- Learn CUDA memory management
- Execute CUDA programs in CUDA environment
- Compare CPU and GPU computation concepts

---

# 📖 Theory

# What is CUDA?

CUDA (Compute Unified Device Architecture) is a parallel computing platform and programming model developed by NVIDIA.

CUDA allows developers to use the computational power of NVIDIA GPUs for general-purpose processing.

Instead of performing computations only on CPU:
- CUDA executes operations on GPU
- Multiple threads run simultaneously
- Large computations become faster

---

# Why CUDA is Important?

Traditional CPUs:
- Have limited cores
- Execute fewer operations simultaneously

GPUs:
- Contain thousands of cores
- Perform massive parallel computations

CUDA utilizes GPU parallelism for:
- Scientific computing
- Machine learning
- Deep learning
- Image processing
- Data analysis
- High Performance Computing (HPC)

---

# Difference Between CPU and GPU

| CPU | GPU |
|-----|-----|
| Few powerful cores | Thousands of lightweight cores |
| Optimized for sequential tasks | Optimized for parallel tasks |
| Lower parallelism | Massive parallelism |
| Better for control operations | Better for mathematical computations |

---

# CUDA Architecture

CUDA uses GPU architecture consisting of:

- Threads
- Blocks
- Grids

---

# Thread

A thread is the smallest execution unit in CUDA.

Each thread performs operation on one data element.

Example:
- One thread adds one vector element

---

# Block

A block contains multiple threads.

Threads within same block:
- Can cooperate
- Share memory

---

# Grid

A grid is a collection of blocks.

Entire CUDA program executes as grid of blocks.

---

# CUDA Programming Model

CUDA programming follows Host-Device model.

| Component | Description |
|------------|-------------|
| Host | CPU memory and execution |
| Device | GPU memory and execution |

---

# Host and Device Memory

## Host Memory

Normal RAM used by CPU.

---

## Device Memory

GPU memory used for parallel execution.

Data must be copied:
- From Host → Device
- Device → Host

---

# What is Vector Addition?

Vector Addition means adding corresponding elements of two vectors.

Example:

```text
A = [1 2 3 4]
B = [5 6 7 8]
```

Result:

```text
C = [6 8 10 12]
```

---

# Formula for Vector Addition

:contentReference[oaicite:0]{index=0}

---

# Why Vector Addition is Suitable for CUDA?

Each vector element can be computed independently.

Example:

```text
C[0] = A[0] + B[0]
C[1] = A[1] + B[1]
```

All additions can occur simultaneously.

This makes vector addition ideal for GPU parallelism.

---

# Steps for Vector Addition using CUDA

# Step 1: Define Vector Size

Define total number of elements.

Example:

```cpp
int N = 1000;
```

---

# Step 2: Allocate Memory on Host

Memory allocated on CPU.

Example:

```cpp
malloc()
```

Used for:
- Input vectors
- Output vector

---

# Step 3: Initialize Vectors

Vectors filled with values.

Example:

```cpp
A[i] = i;
B[i] = i * 2;
```

---

# Step 4: Allocate Memory on Device

Memory allocated on GPU.

CUDA function used:

```cpp
cudaMalloc()
```

---

# Step 5: Copy Data from Host to Device

Input vectors transferred to GPU memory.

CUDA function used:

```cpp
cudaMemcpy()
```

Direction:

```text
Host → Device
```

---

# Step 6: Launch CUDA Kernel

Kernel executes vector addition on GPU.

Kernel launch syntax:

```cpp
kernel<<<blocks, threads>>>();
```

---

# CUDA Kernel

A kernel is a function executed on GPU.

Each thread computes one vector element.

---

# Thread Index Calculation

CUDA thread index:

```cpp
int i = blockIdx.x * blockDim.x + threadIdx.x;
```

---

# Explanation of Thread Variables

| Variable | Purpose |
|----------|----------|
| `threadIdx.x` | Thread number inside block |
| `blockIdx.x` | Block number |
| `blockDim.x` | Threads per block |

---

# Step 7: Copy Result Back to Host

Result vector copied from GPU memory to CPU memory.

CUDA function:

```cpp
cudaMemcpy()
```

Direction:

```text
Device → Host
```

---

# Step 8: Free Device Memory

GPU memory released using:

```cpp
cudaFree()
```

---

# Step 9: Free Host Memory

CPU memory released using:

```cpp
free()
```

---

# CUDA Execution Flow

```text
CPU → Allocate Memory
CPU → Copy Data to GPU
GPU → Execute Kernel
GPU → Compute Vector Addition
GPU → Copy Result Back
CPU → Display Output
```

---

# Concept of Parallelism in CUDA

CUDA achieves parallelism by:
- Running thousands of threads simultaneously
- Distributing computations across GPU cores

For vector addition:
- Each thread handles one vector element

---

# HPC Concepts Used

| HPC Concept | Explanation |
|-------------|-------------|
| Parallel Computing | Multiple operations execute simultaneously |
| GPU Computing | Computation using graphics processor |
| Multithreading | Thousands of threads execute together |
| Shared Processing | GPU cores process data together |
| Scalability | Performance improves with larger workloads |
| Massive Parallelism | Large number of simultaneous computations |

---

# Advantages of CUDA

- Very high parallelism
- Faster mathematical computations
- Efficient for large datasets
- Better GPU utilization
- Reduced execution time

---

# Limitations of CUDA

- Requires NVIDIA GPU
- Additional memory transfer overhead
- CUDA-specific programming required
- Limited portability

---

# Sequential vs CUDA Vector Addition

| CPU Execution | CUDA GPU Execution |
|---------------|-------------------|
| Sequential processing | Parallel processing |
| Few cores | Thousands of GPU cores |
| Slower for large vectors | Faster for large vectors |
| Lower throughput | High throughput |

---

# Performance Measurement

Important metrics in CUDA programming:

- Execution Time
- Speedup
- Throughput
- GPU Utilization

---

# Speedup Formula

:contentReference[oaicite:1]{index=1}

---

# Efficiency Formula

:contentReference[oaicite:2]{index=2}

---

# CUDA Environment Setup

# Step 1: Install CUDA Toolkit

Download from NVIDIA official website.

Toolkit includes:
- CUDA compiler
- Libraries
- Debugging tools

---

# Step 2: Configure Environment Variables

Set:
- PATH
- LD_LIBRARY_PATH

---

# Step 3: Write CUDA Program

Programs use `.cu` extension.

Example:

```text
vector_add.cu
```

---

# Step 4: Compile CUDA Program

CUDA compiler:

```bash
nvcc
```

Compile command:

```bash
nvcc vector_add.cu -o vector_add
```

---

# Step 5: Run Program

```bash
./vector_add
```

---

# Real World Applications

CUDA is used in:

- Artificial Intelligence
- Deep Learning
- Scientific simulations
- Weather forecasting
- Image processing
- Video rendering
- Big Data analytics
- High Performance Computing (HPC)

---

# Important Viva Questions

## 1. What is CUDA?

CUDA is a parallel computing platform developed by NVIDIA.

---

## 2. What is GPU computing?

Using GPU for general-purpose computations.

---

## 3. What is vector addition?

Adding corresponding elements of vectors.

---

## 4. Why vector addition is suitable for CUDA?

Because each element can be computed independently.

---

## 5. What is CUDA kernel?

A function executed on GPU.

---

## 6. What is thread in CUDA?

Smallest execution unit in GPU.

---

## 7. What is block in CUDA?

Group of threads.

---

## 8. What is grid in CUDA?

Collection of blocks.

---

## 9. What is cudaMalloc()?

Used to allocate memory on GPU.

---

## 10. What is cudaMemcpy()?

Used to transfer data between CPU and GPU.

---

## 11. What is nvcc?

CUDA compiler provided by NVIDIA.

---

## 12. What is massive parallelism?

Execution of thousands of operations simultaneously.

---

# Conclusion

CUDA enables efficient GPU-based parallel computing for computationally intensive tasks.

Vector addition using CUDA demonstrates:
- GPU parallelism
- CUDA memory management
- Thread-based execution
- HPC acceleration techniques

This experiment helps understand:
- CUDA architecture
- GPU programming
- Parallel execution
- CUDA kernels
- High Performance Computing concepts