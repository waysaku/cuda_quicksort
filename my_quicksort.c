#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENG 10




void to_rondom(long *ary, long len)
{
    long i, tmp, r;
    srand( (unsigned)time(NULL));
    for( i = 0; i < len - 1; i++) {
	r = rand() % (len - i) + i;
	tmp = ary[i];
	ary[i] = ary[r];
	ary[r] = tmp;
    }
}


long partition(long *ary, long start, long end)
{
    long pivot = ary[start];
    int i = start;
    int j = end + 1;

    do{i++;} while(ary[i] <= pivot && i < end);
    do{j--;} while(ary[j] > pivot);

    while(i < j) 
    {
	long over = ary[i];
	ary[i] = ary[j];
	ary[j] = over;

	do{i++;} while(ary[i] <= pivot && i < end);
	do{j--;} while(ary[j] > pivot);
    }
    long s = ary[start];
    ary[start] = ary[j];
    ary[j] = s;
    return j;
}

void quicksort(long *ary, long start, long end)
{
    if(start < end)
    {
	long j = partition(ary, start, end);
	quicksort(ary, start, j - 1);
	quicksort(ary, j + 1, end);
    }
}

int main()
{
    long i, tmp, r;
    long ary[100000000] = {};

    long len = sizeof(ary) / sizeof(ary[0]);

    for( i = 0; i < len; i++) {
	ary[i] = i + 1;
    }


    to_rondom(ary, len);
    /*
    for( i = 0; i < len; i++) {
	printf("%2d\n", ary[i]);
    }

    printf("----------------------\n");
    */

    clock_t t = clock();
    quicksort(ary, 0, len - 1);
    printf( "%lf\n", (double)( clock() - t ) / CLOCKS_PER_SEC ) ;
    
    for( i = 0; i < len; i++) {
	printf("%2d\n", ary[i]);
    }

    return 0;
}
