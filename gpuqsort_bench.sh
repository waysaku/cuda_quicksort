#nvcc -m64 ./cuda003.cu -lcutil_x86_64 -g -G  -o ./target/cuda003
nvcc -m64 ./gpuqsort_bench.cu -g -G -I/home/yuhsaku/gpuqsort/inc -lcutil_x86_64  -lgpuqsort -L/home/yuhsaku/gpuqsort/lib/linux/static -o gpuqsort_bench

