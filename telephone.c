/**
 * @file	telephone.c
 * @brief	POJ 1002
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Mapping: A B C D E F G H I J K L M N O P Q R S T U V W X Y Z */
char map[]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
char flag=0;

struct node {
	int val;
	int rep;
	struct node *left;
	struct node *right;
};

struct node *put(struct node *f,int val)
{
	if(f==NULL){
		f=(struct node*)malloc(sizeof(struct node));
		f->val=val;
		f->rep=1;
		f->left=f->right=NULL;
		return f;
	}
	if(f->val==val){
		flag=1;
		f->rep++;
		return f;
	}
	if(f->val>val){
		f->left=put(f->left,val);
		return f;
	}
	f->right=put(f->right,val);
	return f;
}

void print_nodes(struct node *f)
{
	if(f==NULL){
		return;
	}
	print_nodes(f->left);
	if(f->rep>1){
		printf("%03d-%04d %d\n",f->val/10000,f->val%10000,f->rep);
	}
	print_nodes(f->right);
}

void destroy(struct node *f)
{
	if(f==NULL){
		return;
	}
	destroy(f->left);
	destroy(f->right);
	free(f);
}

int parse(char *s)
{
	int i;
	int ret=0;
	int len=strlen(s);
	for(i=0;i<len;i++){
		if(isdigit(s[i])){
			ret=ret*10+s[i]-'0';
		}else if(isalpha(s[i])){
			ret=ret*10+map[s[i]-'A'];
		}
	}
	return ret;
}

int main(void)
{
	char buf[BUFSIZ];
	struct node *stuff=NULL;
	int k;
	scanf("%d",&k);
	getchar();
	for(;k>0;k--){
		gets(buf);
		stuff=put(stuff,parse(buf));
	}
	if(!flag){
		puts("No duplicates.");
	}else{
		print_nodes(stuff);
	}
	destroy(stuff);
	return 0;
}
