#include <stdio.h>
#include <cuda.h>

//Cuda error checking - non mandatory
void cudaCheckError() {
 cudaError_t e=cudaGetLastError();
 if(e!=cudaSuccess) {
   printf("Cuda failure %s:%d: '%s'\n",__FILE__,__LINE__,cudaGetErrorString(e));
   exit(0); 
 }
}

//GPU kernel SAXPY operation
__global__
void saxpy(int n, float a, float *x, float *y) {
    int i = blockIdx.x*blockDim.x + threadIdx.x;
    if (i < n) y[i] = a*x[i] + y[i];
}

//CPU SAXPY Operation
void saxpy_host(int n, float a, float *x, float *y) {
    for (int i = 0; i < n; ++i)
        y[i] = a*x[i] + y[i];
}

int main(void) {
    // Num of elements
    int N = 1000;
    //Block size and number
    int block_size, block_no;
    //Vectors operators
    float *x, *y, *d_x, *d_y;
    x = (float*)malloc(N*sizeof(float));
    y = (float*)malloc(N*sizeof(float));

    block_size = 256; //threads per block
    block_no = (N)/block_size; //Numm of blocks

    //Work definition
    dim3 dimBlock(block_size, 1, 1);
    dim3 dimGrid(block_no, 1, 1);

    for (int i = 0; i < N; i++) {
        x[i] = 1.0f;
        y[i] = 2.0f;
    }

    //Escalar operator
    float a = 2.0f;

    printf("Allocating device memory on host..\n");
    //GPU memory allocation
    cudaMalloc(&d_x, N*sizeof(float)); 
    cudaMalloc(&d_y, N*sizeof(float));

    printf("Copying to device..\n");
    cudaMemcpy(d_x, x, N*sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(d_y, y, N*sizeof(float), cudaMemcpyHostToDevice);

    //SAXPY on CUDA
    clock_t start_d=clock();

    printf("Doing GPU saxpy\n");
    saxpy<<<block_no,block_size>>>(N, a, d_x, d_y);
    cudaCheckError();

    //Wait for kernel call to finish
    cudaThreadSynchronize();

    clock_t end_d = clock();

    printf("Doing CPU saxpy\n");
    clock_t start_h = clock();
    saxpy_host(N, a, x, y);
    clock_t end_h = clock();

    //Time computing
    double time_d = (double)(end_d-start_d)/CLOCKS_PER_SEC;
    double time_h = (double)(end_h-start_h)/CLOCKS_PER_SEC;

    //Copying data back to host, this is a blocking call
    cudaMemcpy(y, d_y, N*sizeof(float), cudaMemcpyDeviceToHost);
    printf("n = %d \t GPU time = %fs \t CPU time = %fs\n", N, time_d, tim_h);

    //Free GPU memory
    cudaFree(d_x);
    cudaFree(d_y);
    free(x);
    free(y);

    return 0;
}