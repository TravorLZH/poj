/**
 * @file	filemap.c
 * @brief	POJ 1057
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	XEND	'#'
#define	XFIN	'*'
#define	XFILE	'f'
#define	XDIR	'd'
#define	XCLOSE	']'

struct xfile {
	char name[128];
	struct xfile *next;
};

/* Input Buffer */
char buf[BUFSIZ];
int set=0;
int indent=0;

void do_indents(void)
{
	int i=indent;
	while(i--){
		printf("|     ");
	}
	fflush(stdout);
}

/* Add file to file list */
void append(struct xfile *f,char *stuff)
{
	if(f->next){
		append(f->next,stuff);
		return;
	}
	if(f->name[0]!='\0'){
		/* Create new node if not exists */
		f->next=(struct xfile*)malloc(sizeof(struct xfile));
		f->next->next=NULL;
		if(strcmp(stuff,f->name)<0){
			strcpy(f->next->name,f->name);
		}else{
			f=f->next;
		}
	}
	/* Store the content */
	strcpy(f->name,stuff);
}

/* Print everything */
void print_stuff(struct xfile *f)
{
	if(f->name[0]=='\0'){
		return;
	}
	do_indents();
	puts(f->name);
	if(f->next){
		print_stuff(f->next);
	}
}

/* NOTE: This frees the input argument as well */
void destroy(struct xfile *f)
{
	if(f->next){
		destroy(f->next);
	}
	free(f);
}


int handle_dir(int root)
{
	int ret=0;
	struct xfile *files=(struct xfile*)malloc(sizeof(struct xfile));
	files->name[0]='\0';
	files->next=NULL;
	indent++;
scan:	gets(buf);
	if(buf[0]==XEND){
		destroy(files);
		exit(0);
	}
	if(root){
		set++;
		if(set>1){
			putchar('\n');
		}
		printf("DATA SET %d:\n",set);
		puts("ROOT");
		root=0;
	}
	switch(buf[0]){
	case XFIN:
		ret=1;
		goto out;
	case XCLOSE:
		goto out;
	case XDIR:
		do_indents();
		puts(buf);
		if(handle_dir(0)){
			ret=1;
			goto out;
		}
		break;
	case XFILE:
		append(files,buf);
		break;
	}
	goto scan;
out:	indent--;
	print_stuff(files);
	destroy(files);
	return ret;
}

int main(void)
{
loop:
	handle_dir(1);
	goto loop;
	return 0;
}
