#include <stdio.h>
#include <cutil.h>

__global__ void cuda_kernel(float* device_data, float* device_out_data)
{
	int tid = threadIdx.x;
	int t = tid * 2;
	device_out_data[tid] = t;
}

int main(int argc, char** argv)
{
	CUT_DEVICE_INIT(argc, argv);

	float* host_data = (float*)malloc(sizeof(float) * 1024);
	for(int i = 0; i < 1024; i++) {
	    host_data[i] = i;
	}

	float* device_data;
	cudaMalloc((void**)&device_data, sizeof(float) * 1024);
	cudaMemcpy(device_data, host_data, sizeof(float) * 1024, cudaMemcpyHostToDevice);

	float* device_out_data;
	cudaMalloc((void**)&device_out_data, sizeof(float) * 1024);

	dim3 grid(8, 8);
	dim3 threads(4, 4);

	cuda_kernel<<< grid, threads, sizeof(float) * 1024 >>>(device_data, device_out_data);
}


