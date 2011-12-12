#include <stdio.h>
#include <assert.h>
__global__ void func(int *data)
{
	int i = threadIdx.x;

	data[i] = data[i] + data[i+32];

	if (i < 16) {
		data[i] = data[i] + data[i+16];
	}
	__syncthreads();
	if (i < 8) {
		data[i] = data[i] + data[i+8];
	}
	__syncthreads();
	if (i < 4) {
		data[i] = data[i] + data[i+8];
	}
	__syncthreads();
	if (i < 2) {
		data[i] = data[i] + data[i+2];
	}
	__syncthreads();
	if (i < 1) {
		data[i] = data[i] + data[i+1];
	}
}
int main()
{
	int *d_data;
	int *data = new int[512];
	cudaMalloc((void**)&d_data, sizeof(int)*512);
	for (int i=0; i<512; i++) {
		data[i] = 3;
	}
	cudaMemcpy(d_data, data, sizeof(int)*512, cudaMemcpyHostToDevice);
	func<<<1,64>>>(d_data);
	cudaMemcpy(data, d_data, sizeof(int)*512, cudaMemcpyDeviceToHost);

	printf("sum = %d\n", data[0]);

	assert(data[0] == 64*3);
}


