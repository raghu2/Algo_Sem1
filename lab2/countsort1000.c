#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main(){
	int i,j,choice;
	FILE *p1,*p2;
	p1=fopen("temp2.txt","r");
	p2=fopen("temp4.txt","w");
	 int A[1000],C[1000];
		int B[10]={0};
			for(i=0;i<1000;i++){
				fscanf(p1,"%d",A[i]);
				B[A[i]-1]++;
			}
		for(i=1;i<10;i++){
			B[i]=B[i]+B[i-1];
		}
		for(i=999;i>=0;i--){
			C[B[A[i]-1]-1]=A[i];
			B[A[i]-1]--;	
		}
		printf("\n");
		for(i=0;i<1000;i++){
			fprintf(p2,"%d",C[i]);
		}
}
