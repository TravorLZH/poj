/**
 * @file	hangover.c
 * @brief	POJ 1003
 */
#include <stdio.h>

int lookup(float distance)
{
	float tmp=0.0f;
	int n=2;
	while(tmp<distance)
		tmp+=1.0f/n++;
	return n-2;
}

int main(void)
{
	float tmp;
parse:
	scanf("%f",&tmp);
	if(tmp==0.0f)
		return 0;
	printf("%d card(s)\n",lookup(tmp));
	goto parse;
}
