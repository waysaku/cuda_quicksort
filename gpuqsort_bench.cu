#include <stdio.h>
#include <cutil.h>
#include <gpuqsort.h>

void to_rondom(unsigned int *ary, unsigned int len)
{
    unsigned int i, tmp, r;
    srand( (unsigned)time(NULL));
    for( i = 0; i < len - 1; i++) {
	r = rand() % (len - i) + i;
	tmp = ary[i];
	ary[i] = ary[r];
	ary[r] = tmp;
    }
}


int main( int argc, char** argv) 
{
    unsigned int i;
    //long ary[100000000] = {};
    //unsigned int ary[10] = {};
    const unsigned int MEASURES = 5;
    //const unsigned int STARTSIZE = 2<<19;
    const unsigned int STARTSIZE = 100000000;

    unsigned int maxsize = STARTSIZE<<(MEASURES - 1);

    unsigned int* ary = new unsigned int[maxsize];
    unsigned int len = STARTSIZE;

    for( i = 0; i < len; i++) {
	ary[i] = i + 1;
    }
    to_rondom(ary, len);

    /*
    for( i = 0; i < len; i++) {
	printf("%2d\n", ary[i]);
    }
   */ 
    
    double timerValue;
    int threads   = 0;
    int maxblocks = 0;
    int sbsize    = 0;



    clock_t t = clock();
    if(gpuqsort(ary, len, &timerValue, maxblocks, threads, sbsize, 0) != 0)
    {
	printf("Error! (%s)\n",getGPUSortErrorStr());
	exit(1);
    }
    printf( "%lf\n", (double)( clock() - t ) / CLOCKS_PER_SEC ) ;







    
    /*
    for( i = 0; i < len; i++) {
	printf("%2d\n", ary[i]);
    }
    */
    return 0;
}

