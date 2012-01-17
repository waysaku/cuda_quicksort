#include <stdio.h>
#include <stdlib.h>

#define LENG 1024 

int main()
{
    long len = LENG * LENG ;
    long i, tmp, r, ary[len];

    srand( (unsigned)time(NULL));

    for( i = 0; i < len; i++) {
	ary[i] = i + 1;
    }


    for( i = 0; i < len - 1; i++) {
	r = rand() % (len - i) + i;
	tmp = ary[i];
	ary[i] = ary[r];
	ary[r] = tmp;
    }

    /*
    for( i = 0; i < len; i++) {
	printf("%2d\n", ary[i]);
    }
    */

    
    for(i = 0; i < ary[i]; i++) {

    }
    return 0;
}

long qs(long ary[]) {
    long i, j;

    long ary_cnt = sizeof(ary) / sizeof(ary[0]);
    long harf = (ary_cnt / 2) - 1;
    long datum = ary[harf];

    long previous[harf], next[harf];
    long pre_cnt = 0;
    long next_cnt = 0;

    long result_ary[ary_cnt];

    for(i = 0; i < ary_cnt; i++) {
	if(ary[i] > datum) {
	    next[next_cnt] = ary[i];
	    next_cnt++;
	}else {
	    previous[pre_cnt] = ary[i];
	    pre_cnt++;
	}
    }

    for(i = 0; i < harf; i++) {
	result_ary[i] = previous[i];
    }
    result_ary[i++] = datum;

    for(j = 0; j < harf; j++) {
	result_ary[i + j] = next[j];
    }

    return result_ary;
}
