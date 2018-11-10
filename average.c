/**
 * @file	average.c
 * @brief	POJ 1004
 */
#include <stdio.h>

int main(void)
{
	double tmp,average;
	int i;
	for(i=0,average=0;i<12;i++){
		scanf("%lf",&tmp);
		average+=tmp;
	}
	average/=12;
	printf("$%.2lf\n",average);
	return 0;
}
