#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void main()
{
	int i,n;
	printf("print a number\n");
	scanf("%d",&n);
	FILE *p1, *p2;
	p1=fopen("temp1.txt","w");
	for(i=0;i<n;i++){
		fprintf(p1,"%d",rand());
	}
	p2=fopen("temp2.txt","w");
	char c=getc(p1);
	while(c!='\0'){
		putc(c,p2);
	}
}
