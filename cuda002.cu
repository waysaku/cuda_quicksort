#include <stdio.h>
#include <cutil.h>
#include "cuda002_kernel.cu"


int main(int argc, char** argv)
{

    CUT_DEVICE_INIT(argc, argv);

    unsigned int timer = 0;
    CUT_SAFE_CALL(cutCreateTimer(&timer));
    CUT_SAFE_CALL(cutStartTimer(timer));

    float* h_idata = (float*) malloc(sizeof(float) * 100);
    for(int i = 0; i < 100; i++)
    {
	h_idata[i] = i;
    }

    float* d_idata;
    CUDA_SAFE_CALL(cudaMalloc((void**) &d_idata, sizeof(float) * 100));
    CUDA_SAFE_CALL(cudaMemcpy(d_idata, h_idata, sizeof(float) * 100, cudaMemcpyHostToDevice));

    float* d_odata;
    CUDA_SAFE_CALL(cudaMalloc((void**) &d_odata, sizeof(float) * 100));

    dim3 grid(1, 1, 1);
    dim3 threads(100, 1, 1);

    cuda002Kernel<<< grid, threads, sizeof(float) * 100 >>>(d_idata, d_odata);

    float* h_odata = (float*) malloc(sizeof(float) * 100);
    CUDA_SAFE_CALL(cudaMemcpy(h_odata, d_odata, sizeof(float) * 100, cudaMemcpyDeviceToHost));

    printf("input data, output data\n");
    for(int i = 0; i < 100; i++)
    {
	printf("%f, %f\n", h_idata[i], h_odata[i]);
    }

    CUT_SAFE_CALL(cutStopTimer(timer));
    printf("Processing time: %f(ms)\n", cutGetTimerValue(timer));
    CUT_SAFE_CALL(cutDeleteTimer(timer));

    free(h_idata);
    free(h_odata);
    CUDA_SAFE_CALL(cudaFree(d_idata));
    CUDA_SAFE_CALL(cudaFree(d_odata));

    CUT_EXIT(argc, argv);


}


