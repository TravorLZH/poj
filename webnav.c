/**
 * @file	webnav.c
 * @brief	POJ 1057
 */
#include <stdio.h>
#include <string.h>

char sites[101][71]={"http://www.acm.org/"};
char cmd[8];

int main(void)
{
	int i=0;
loop:	scanf("%s",cmd);
	switch(*cmd){
	case 'Q':
		return 0;
	case 'V':
		scanf("%s",sites[++i]);
		sites[i+1][0]='\0';
		break;
	case 'B':
		i--;
		if(i<0){
			puts("Ignored");
			i++;
			goto loop;
		}
		break;
	case 'F':
		i++;
		if(sites[i][0]=='\0'){
			puts("Ignored");
			i--;
			goto loop;
		}
		break;
	}
	puts(sites[i]);
	goto loop;
	return 0;
}
