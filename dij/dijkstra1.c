#include<stdio.h>
#include<stdlib.h>
FILE *inp, *out;
int minindex,min,i,j,u,v,count,nodes;
int distance[15],matrix[15][15],presentset[15];
int mindistance(int distance[],int presentset[]){
        int min=200;
        int minindex;
        for(v=0;v<nodes;v++){
                if(presentset[v]==0 && distance[v]<=min){
                        min=distance[v];
                        minindex=v;
                }
        }
        return minindex;
}
int djikstra(int matrix[15][15],int source){
        for(i=0;i<nodes;i++){
                presentset[i]=0;
                distance[i]=200;
        }
        distance[source]=0;
        for(count=0;count<nodes-1;count++){
                u=mindistance(distance,presentset);
                presentset[u]=1;
                for(v=0;v<nodes;v++){
                        if(!presentset[v]&&matrix[u][v]&&distance[u]!=200&&(distance[u]+matrix[u][v])<distance[v]){
                                distance[v]=distance[u]+matrix[u][v];
                        }
                }
        }
        for(i=0;i<nodes;i++){
                fprintf(out,"%d\t",i);
                fprintf(out,"%d\n",distance[i]);
        }
        return 0;
}
int main(){
        inp=fopen("input1.txt","r");
        out=fopen("output1.txt","w");
        fscanf(inp,"%d",&nodes);
        for(i=0;i<nodes;i++){
			for(j=0;j<nodes;j++){
                        fscanf(inp,"%d",&matrix[i][j]);
                }
        }
        djikstra(matrix,0);
        return 0;
}


