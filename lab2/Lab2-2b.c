#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main(){
	int i,j,choice;
	FILE *p1,*p2;
	p1=fopen("temp2.txt","r");
	p2=fopen("temp4.txt","w");
	printf("enter a choice 1.50 2.100 3.500 4.1000\n");
	scanf("%d",&choice);
	switch(choice){
	case 1: int A[50],C[50];
		int B[10]={0};
		char c=getc(p1);
		while(c!='\0'){
			for(i=0;i<50;i++){
				A[i]=c;
				B[A[i]-1]++;
			}
		}
		for(i=1;i<10;i++){
			B[i]=B[i]+B[i-1];
		}
		for(i=50;i>=0;i--){
			C[B[A[i]-1]-1]=A[i];
			B[A[i]-1]--;	
		}
		printf("\n");
		for(i=0;i<50;i++){
			fprintf(p2,"%d",C[i]);
		}
		break;
	case 2: int A[100],C[100];
		int B[10]={0};
		char c=getc(p1);
		while(c!='\0'){
			for(i=0;i<100;i++){
				A[i]=c;
				B[A[i]-1]++;
			}
		}
		for(i=1;i<10;i++){
			B[i]=B[i]+B[i-1];
		}
		for(i=100;i>=0;i--){
			C[B[A[i]-1]-1]=A[i];
			B[A[i]-1]--;	
		}
		printf("\n");
		for(i=0;i<100;i++){
			fprintf(p2,"%d",C[i]);
		}
		break;
	case 3: int A[500],C[500];
		int B[10]={0};
		char c=getc(p1);
		while(c!='\0'){
			for(i=0;i<500;i++){
				A[i]=c;
				B[A[i]-1]++;
			}
		}
		for(i=1;i<10;i++){
			B[i]=B[i]+B[i-1];
		}
		for(i=500;i>=0;i--){
			C[B[A[i]-1]-1]=A[i];
			B[A[i]-1]--;	
		}
		printf("\n");
		for(i=0;i<500;i++){
			fprintf(p2,"%d",C[i]);
		}
		break;
	case 4: int A[1000],C[1000];
		int B[10]={0};
		char c=getc(p1);
		while(c!='\0'){
			for(i=0;i<1000;i++){
				A[i]=c;
				B[A[i]-1]++;
			}
		}
		for(i=1;i<10;i++){
			B[i]=B[i]+B[i-1];
		}
		for(i=1000;i>=0;i--){
			C[B[A[i]-1]-1]=A[i];
			B[A[i]-1]--;	
		}
		printf("\n");
		for(i=0;i<1000;i++){
			fprintf(p2,"%d",C[i]);
		}
		break;
	default :break;
	}
}