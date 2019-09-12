#include<stdio.h>

#include<stdlib.h>

#include<time.h>

int i,j,k,n,a=0;

void ordern()
{
    for(i=0;i<n;i++)
		a++;

}


void ordern2()
{

    for(i=0;i<n;i++)
    
	for(j=0;j<n;j++)
		a++;

}


void ordern3()
{
    
	for(i=0;i<n;i++)
    
		for(j=0;j<n;j++)
   
			 for(k=0;k<n;k++)
				a++;

}


int order2n(int n)
{

	if(n==0)
    return 0;

    			else if(n==1)
    return 1;


	return (order2n(n-1)+order2n(n-2));

}
void orderlogn()
{
    
	for(i=1;i<n;)
   
		 i=2*i;

}


void main()
{
    
	scanf("%d",&n);
   
	clock_t start1,end1;

	double time1;
 
   
    
	start1=clock();
    
	ordern();
    
	end1=clock()-start1;
    
	time1=(double)end1/CLOCKS_PER_SEC;
    
	printf("%f\n",time1);

    
    
	start1=clock();
    
	ordern2();
    
	end1=clock()-start1;
    
	time1=(double)end1/CLOCKS_PER_SEC;
    
	printf("%f\n",time1);
 
   
    
	start1=clock();
    
	ordern3();
    
	end1=clock()-start1;
    
	time1=(double)end1/CLOCKS_PER_SEC;
    
	printf("%f\n",time1);
  
  
    
	start1=clock();
    
	orderlogn();
    
	end1=clock()-start1;
    
	time1=(double)end1/CLOCKS_PER_SEC;
    
	printf("%f\n",time1);
  
  
  
	start1=clock();
    
	order2n(n);
    
	end1=clock()-start1;
    
	time1=(double)end1/CLOCKS_PER_SEC;
    
	printf("%f\n",time1);

}
