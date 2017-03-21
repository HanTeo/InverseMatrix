# InverseMatrix
Inverting Matrices in Parallel with Eigen and C++

## Matrix Definition Methodology

- Given 7 numbers choose 4 
- From chosen 4 numbers choose 3
- Combine both selections to form 7 number combination 
- Each row in the matrix is a permutation of the original combination
- Create a `Matrix<float, 7, 7>` matrix from the combinations

## BDD/TDD using Catch

- Single file inclusion that allows a very descriptive syntax to write tests
- Supported out of the box with CLion 2017

## Eigen Explicit Vectorization / Matrix Decomposition (Leveraging SIMD - SSE, AVX512 etc)

- Within-Thread Parallelization due to memory-aligned data structures and ability to utilize SIMD instructions
- Smart matrix decomposition used for inversion calculation i.e. LU and QR

## STL Async for Parallelism

- Running the inversions in parallel without having to explicitly create STL::Thread
- Exception handled concurrency constructs
