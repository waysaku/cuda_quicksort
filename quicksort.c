#include <stdio.h>
#include <stdlib.h>

#define LENG 10



long* qs(long ary[], long result_ary[]) {
    long i, j;

    long ary_cnt = sizeof(ary) / sizeof(ary[0]);
    long harf = (ary_cnt / 2) - 1;
    long pivot = ary[0];
    
    long previous[harf], next[harf];
    
    long pre_cnt = 0;
    long next_cnt = 0;


    for(i = 0; i < ary_cnt; i++) {
	if(ary[i] > pivot) {
	    next[next_cnt] = ary[i];
	    next_cnt++;
	}else {
	    previous[pre_cnt] = ary[i];
	    pre_cnt++;
	}
    }

    long compress_previous[pre_cnt], compress_next[next_cnt];
    for(i = 0; i < pre_cnt; i++) {
	compress_previous[i] = previous[i];
    }
    for(i = 0; i < next_cnt; i++) {
	compress_next[i] = next[i];
    }


    long re_previous[pre_cnt], re_next[next_cnt];
    if(pre_cnt > 1) {
        qs(compress_previous, re_previous);
    }else {
	*re_previous = *compress_previous;
    }
    if(next_cnt > 1) {
        qs(compress_next, re_next);
    }else {
	*re_next = *compress_next;
    }
            

    long *re_previous_p = re_previous;
    while(*re_previous_p != 0) {
	result_ary[i] = *re_previous_p;
	*re_previous_p++;
    }

    result_ary[i++] = pivot;

    long *re_next_p = re_next;
    while(*re_next_p != 0) {
	result_ary[i] = *re_next_p;
	*re_next_p++;
    }


    return result_ary;
}



int main()
{
    long len = LENG;
    long i, tmp, r;
    long ary[len] = {0};
    long result[len]; = {0};

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

    for( i = 0; i < len; i++) {
	printf("%2d\n", ary[i]);
    }

    printf("----------------------\n");
    qs(ary, result);
    
    for( i = 0; i < len; i++) {
	printf("%2d\n", result[i]);
    }

    return 0;
}
