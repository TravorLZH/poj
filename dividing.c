/**
 * @file	divide.c
 * @brief	POJ 1014
 */
#include <stdio.h>

int stuff[7];	// For convenienc, we start from ONE
int flag;

int divisible(int half,int cur,int max)
{
	int i;
	int try;
	if(cur==half){
		flag=1;
	}
	if(flag){
		return flag;
	}
	for(i=max;i>=1;i--){
		try=cur+i;
		if(stuff[i]==0){
			continue;
		}
		if(try<=half){
			stuff[i]--;
			divisible(half,try,i);
			if(flag){
				break;
			}
		}
	}
	return flag;
}

int main(void)
{
	int i,n=0;
	int sum;
	int div;
	while(1){
		sum=0;
		for(i=1;i<=6;i++){
			scanf("%d",&stuff[i]);
			sum+=i*stuff[i];
		}
		if(!sum){
			break;
		}
		printf("Collection #%d:\n",++n);
		if(sum%2){
			div=0;
		}else{
			flag=0;
			div=divisible(sum/2,0,6);
		}
		if(div){
			puts("Can be divided.");
		}else{
			puts("Can't be divided.");
		}
		putchar('\n');
	}
	return 0;
}
