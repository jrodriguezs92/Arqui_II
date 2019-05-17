#include <stdio.h>
#include <cuda.h>

int *a, *b;  // host data
int *c, *c2;  // results

//Cuda error checking - non mandatory
void cudaCheckError() {
 cudaError_t e=cudaGetLastError();
 if(e!=cudaSuccess) {
   printf("Cuda failure %s:%d: '%s'\n",__FILE__,__LINE__,cudaGetErrorString(e));
   exit(0); 
 }
}

//GPU kernel Matrix product
__global__
void vecMul(int *A,int *B,int *C,int N){
    int row = blockIdx.y*blockDim.y+threadIdx.y;
    int col = blockIdx.x*blockDim.x+threadIdx.x;

    if (row < N && col < N) {
        int tmpSum = 0.0f;
        for (int i = 0; i < N; i++) {
            tmpSum += A[row * N + i] * B[i * N + col];
        }
        C[row * N + col] = tmpSum;
    }
}

int main(int argc,char **argv)
{
    printf("Begin \n");
    int n=4;
    int size  = n*n;

    //Number of blocks
    int nBytes = size*sizeof(int);
    //Block size and number
    int block_size, block_no;

    //memory allocation	
    a = (int *) malloc(nBytes);
    b = (int *) malloc(nBytes);
    c = (int *) malloc(nBytes);
    c2 = (int *) malloc(nBytes);

    int *a_d,*b_d,*c_d;
    block_size = 16; //threads per block
    block_no = size/block_size;
    
    //Work definition
    dim3 dimBlock(block_size, 1, 1);
    dim3 dimGrid(block_no, 1, 1);

    // Data filling

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            a[i*n+j] = i;
            b[i*n+j] = j;
        }
    }

    printf("Allocating device memory on host..\n");
   //GPU memory allocation
    cudaMalloc((void **) &a_d, size*sizeof(int));
    cudaMalloc((void **) &b_d, size*sizeof(int));
    cudaMalloc((void **) &c_d, size*sizeof(int));

    printf("Copying to device..\n");
    cudaMemcpy(a_d, a, size*sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(b_d, b, size*sizeof(int), cudaMemcpyHostToDevice);

    clock_t start_d=clock();
    printf("Doing GPU Vector add\n");
    vecMul<<<block_no,block_size>>>(a_d, b_d, c_d, n);
    cudaCheckError();

    //Wait for kernel call to finish
    cudaThreadSynchronize();

    clock_t end_d = clock();

    //Time computing
    double time_d = (double)(end_d-start_d)/CLOCKS_PER_SEC;

    printf("n = %d \t GPU time = %fs \n", size, time_d);

    //Free GPU memory
    cudaFree(a_d);
    cudaFree(b_d);
    cudaFree(c_d);
    return 0;
}