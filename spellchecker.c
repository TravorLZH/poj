/**
 * @file	spellchecker.c
 * @brief	POJ 1035
 */
#include <stdio.h>
#include <string.h>

/* There will be at most 10000 words in the dictionary */
#define	DICT_WORDS	10000
/* Each one contains 15 characters at most (without NULL-terminator) */
#define	WORD_LENGTH	16

/* Input buffer */
char buf[WORD_LENGTH];

/* Dictionary and words */
char dict[DICT_WORDS][WORD_LENGTH];

/* The logical length for dictionary */
int dicts=0;

int correct(char *word)
{
	int i;
	for(i=0;i<dicts;i++){
		if(!strcmp(dict[i],word)){
			return 1;
		}
	}
	return 0;
}

int replace(char *a,char *b)
{
	int i;
	int x=0;
	int len=strlen(a);
	for(i=0;i<len;i++){
		if(a[i]!=b[i]){
			/* If more than one mistake */
			if(++x>1){
				return 0;
			}
		}
	}
	return 1;
}

int delete(char *a,char *b)
{
	int i,j;
	int x=0;
	int len=strlen(a);
	for(i=0,j=0;i<len;i++){
		if(a[i]!=b[j]){
			/* Same as above */
			if(++x>1){
				return 0;
			}
		}else{
			j++;
		}
	}
	return 1;
}

void do_word(char *word)
{
	int i;
	int len=strlen(word);
	int dlen;
	if(correct(word)){
		printf("%s is correct\n",word);
		return;
	}
	printf("%s: ",word);
	for(i=0;i<dicts;i++){
		dlen=strlen(dict[i]);
		if(dlen==len&&replace(word,dict[i])){
			printf("%s ",dict[i]);
		}else if((len-dlen)==1&&delete(word,dict[i])){
			printf("%s ",dict[i]);
		}else if((len-dlen)==-1&&delete(dict[i],word)){
			printf("%s ",dict[i]);
		}
	}
	putchar('\n');
}

int main(void)
{
scan_dict:
	scanf("%s",buf);
	if(buf[0]!='#'){
		strcpy(dict[dicts++],buf);
		goto scan_dict;
	}
check_words:
	scanf("%s",buf);
	if(buf[0]!='#'){
		do_word(buf);
		goto check_words;
	}
	return 0;
}
