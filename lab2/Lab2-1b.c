#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int i,j,comp=0;
int swapcount=0;
void swap(int *a, int *b){
	swapcount++;
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int A[],int low,int high){
	int pivot=A[low];
	i=low;
	j=low+1;
	comp++;
	while(j<=high){
		comp++;
		if(A[j]<pivot){
			i++;
			swap(&A[i],&A[j]);
		}
		j++;
	}
	swap(&A[i],&A[low]);
	return i;
}
void quicksort(int A[],int low,int high){
	comp++;
	if(low>=high)
		return;
	int pivot=partition(A,low,high);
	quicksort(A,low,pivot-1);
	quicksort(A,pivot+1,high);
}
void main(){
	int n,low=0;
	FILE *p1, *p2,*p3;
	p1=fopen("temp1.txt","r");
	p2=fopen("temp3.txt","w");
	p3=fopen("count.txt","w");
	scanf("%d",&n);
	int A[n];
	int high=n-1;
		for(i=0;i<n;i++){
			fscanf(p1,"%d",&A[i]);
		}
	}
	quicksort(A,low,high);
	for(i=0;i<n;i++){
		fprintf(p2,"%d",A[i]);
	}
	fprintf(p3,"%d\n",comp);
	fprintf(p3,"%d",swapcount);
	fclose(p1);
	fclose(p2);
	fclose(p3);
}
