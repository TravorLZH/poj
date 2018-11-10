/**
 * @file	webnav.c
 * @brief	POJ 1057
 */
#include <stdio.h>
#include <string.h>

char back[64][100];
char forw[64][100];
int a=0;
int b=0;

int main(void)
{
	char cmd[16];
	char url[64];
	strcpy(back[0],"http://www.acm.org/");
loop:	scanf("%s",cmd);
	switch(cmd[0]){
	case 'Q':
		return 0;
	case 'V':
		scanf("%s",url);
		strcpy(back[++a],url);
		b=0;
		break;
	case 'B':
		if(a==0){
			puts("Ignored");
			goto loop;
		}
		strcpy(forw[++b],back[a--]);
		break;
	case 'F':
		if(b==0){
			puts("Ignored");
			goto loop;
		}
		strcpy(back[++a],forw[b--]);
		break;
	}
	puts(back[a]);
	goto loop;
	return 0;
}
