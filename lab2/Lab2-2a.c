#include <stdio.h>
#include<math.h>
#include<stdlib.h>
int main() {
	int count,first=0;
	FILE *p2;
	p2=fopen("temp2.txt","w");
	printf("enter number of numbers to be generated\n");
	scanf("%d",&count);
	while(count>0){
	    	fprintf(p2,"%d\n",rand()%10);
	    	count--;
	}
	fclose(p2);
	return 0;
}