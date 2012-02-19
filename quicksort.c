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


long partition(long *ary, long start, long end)
{
    long pivot = ary[start];
    int i = start;
    int j = end;

    while(i < j) 
    {
	while(ary[i] <= pivot && i < j) {i++;}
	while(ary[j] > pivot && j > i) {j--;}

	if(i == j) 
	{
	    //todo
	    break;
	}

	long over = ary[i];
	ary[i] = ary[j];
	ary[j] = over;
	i++;
	j--;
    }
    return i;
}

void quicksort(long *ary, long start, long end)
{
    if(end <= start)
    {
	return;
    }
    long j = partition(ary, start, end);
    quicksort(ary, 0, j);
    quicksort(ary, j, end -1);
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
    quicksort(ary, 0, len - 1);
    
    for( i = 0; i < len; i++) {
	printf("%2d\n", ary[i]);
    }

    return 0;
}
