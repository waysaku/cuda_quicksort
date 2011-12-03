#include <stdio.h>
#include "sharedmem.cuh"

__global__ void cuda002Kernel(float* g_idata, float* g_odata)
{
    SharedMemory<float> smem;
    float* sdata = smem.getPointer();

    const unsigned int tid = threadIdx.x;
    sdata[tid] = g_idata[tid];
    __syncthreads();

    sdata[tid] = (float)2 * sdata[tid];
    __syncthreads();

    g_odata[tid] = sdata[tid];
}
