#include <stdio.h>
#include<math.h>
#include<stdlib.h>
int main() {
	int count,choice,first=0;
	FILE *p1;
	p1=fopen("temp1.txt","w");
	printf("enter number of numbers to be generated\n");
	scanf("%d",&count);
	printf("enter your choice. 1.ascending order 2.descending order 3.random order\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:	while(count>0){
		    		first=first+((rand()%count));
	    			fprintf(p1,"%d\n",first);
	    			count--;
			}
			break;
		case 2:first=count;
			while(count>0){
	    			first=first-((rand()%count));
	    			fprintf(p1,"%d\n",first);
	    			count--;
			}
			break;
		case 3:while(count>0){
	    			fprintf(p1,"%d\n",rand()%count);
	    			count--;
	
			}
			break;
		default:printf("can't you see the choices given?\n");
			break;
	}
	fclose(p1);
	return 0;
}