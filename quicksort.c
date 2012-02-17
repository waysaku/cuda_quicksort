#include <stdio.h>
#include <stdlib.h>

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

void sort(long *ary, long *result_ary, long ary_len)
{
     long over_ary[ary_len] = {};
     long min_ary[ary_len] = {};

     int i = 0;
     int j = ary_len;


}

int main()
{
    long i, tmp, r;
    long ary[10] = {};
    long result[10] = {};

    long len = sizeof(ary) / sizeof(ary[0]);

    for( i = 0; i < len; i++) {
	ary[i] = i + 1;
    }


    to_rondom(ary, len);
    for( i = 0; i < len; i++) {
	printf("%2d\n", ary[i]);
    }

    printf("----------------------\n");
    sort(ary, result, len);
    //qs(ary, result);
    
    //for( i = 0; i < len; i++) {
//	printf("%2d\n", result[i]);
 //   }

    return 0;
}
