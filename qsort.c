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


int long_sort( const void * a , const void * b )
{
  if( *(long*)a < *(long*)b ) {
    return -1;
  }
  else
  if(*(long*)a == *(long*)b) {
    return 0;
  }
  return 1;
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
    qsort((void*)ary, len, sizeof(long), long_sort);
    printf( "%lf\n", (double)( clock() - t ) / CLOCKS_PER_SEC ) ;
    
    for( i = 0; i < len; i++) {
	printf("%2d\n", ary[i]);
    }

    return 0;
}
