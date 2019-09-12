#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
FILE *inp,*out;
struct node {
    int vertex, weight;
    struct node * next;
};
struct vertex
{
	int vertex, dist;
};
struct node * addEdge(struct node * head, int vertex, int weight)
{
    struct node * newNode = (struct node *) calloc(1, sizeof(struct node));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = head;
    return newNode;
}
void heapify(struct vertex minHeap[], int size, int i, int pos[])
{
	struct vertex temp;
    while ((2 * i) <= size) {
        if ((2 * i) + 1 > size) {
			if (minHeap[i].dist > minHeap[2 * i].dist) {
				pos[minHeap[i].vertex] = 2 * i;
				pos[minHeap[2 * i].vertex] = i;
                temp = minHeap[i];
                minHeap[i] = minHeap[2 * i];
                minHeap[2 * i] = temp;
            }
            break;
        }
        if (minHeap[i].dist > minHeap[2 * i].dist || minHeap[i].dist > minHeap[2 * i + 1].dist) {
            if (minHeap[2 * i].dist <= minHeap[(2 * i) + 1].dist) {
                pos[minHeap[i].vertex] = 2 * i;
				pos[minHeap[2 * i].vertex] = i;
                temp = minHeap[2 * i];
                minHeap[2 * i] = minHeap[i];
                minHeap[i] = temp;
                i = 2 * i;
            } else if (minHeap[2 * i].dist > minHeap[(2 * i) + 1].dist) {
                pos[minHeap[i].vertex] = 2 * i + 1;
				pos[minHeap[2 * i + 1].vertex] = i;
                temp = minHeap[(2 * i) + 1];
                minHeap[(2 * i) + 1] = minHeap[i];
                minHeap[i] = temp;
                i = (2 * i) + 1;
            }
        } else {
            break;
        }
    }
}
void buildHeap(struct vertex minHeap[], int size, int pos[])
{
    int i;

    for (i = size / 2; i >= 1; --i) {
        heapify(minHeap, size, i, pos);
    }
}
void decreaseKey(struct vertex minHeap[], struct vertex newNode, int pos[])
{
	minHeap[pos[newNode.vertex]].dist = newNode.dist;
	int i = pos[newNode.vertex];
	struct vertex temp;
    while (i > 1) {
        if (minHeap[i / 2].dist > minHeap[i].dist) {
            pos[minHeap[i].vertex] = i / 2;
			pos[minHeap[i / 2].vertex] = i;
            temp = minHeap[i / 2];
            minHeap[i / 2] = minHeap[i];
            minHeap[i] = temp;
            i = i / 2;
        } else {
            break;
        }
    }
}
struct vertex extractMin(struct vertex minHeap[], int size, int pos[])
{
	pos[minHeap[1].vertex] = size;
	pos[minHeap[size].vertex] = 1;
	struct vertex min = minHeap[1];
	minHeap[1] = minHeap[size];
	--size;
	heapify(minHeap, size, 1, pos);
	return min;
}
void dijkstra(struct node * adjacencyList[], int vertices, int startVertex, int distances[], int parent[])
{
    int i;
    struct vertex minVertex;
    struct vertex priorityQueue[vertices + 1];
    int pos[vertices + 1];
     for (i = 1; i <= vertices; ++i) {
        distances[i] = INT_MAX;
        parent[i] = 0;
        priorityQueue[i].dist = INT_MAX;
        priorityQueue[i].vertex = i;
		pos[i] = priorityQueue[i].vertex;
    }
    distances[startVertex] = 0;
    priorityQueue[startVertex].dist = 0;
    buildHeap(priorityQueue, vertices, pos);
    for (i = 1; i <= vertices; ++i) {
		minVertex = extractMin(priorityQueue, vertices, pos);
		struct node * trav = adjacencyList[minVertex.vertex];
        while (trav != NULL) {
        	int u = minVertex.vertex;
        	int v = trav->vertex;
        	int w = trav->weight;
            if (distances[u] != INT_MAX && distances[v] > distances[u] + w) {
                distances[v] = distances[u] + w;
                parent[v] = u;
                struct vertex changedVertex;
                changedVertex.vertex = v;
                changedVertex.dist = distances[v];
                decreaseKey(priorityQueue, changedVertex, pos);
            }
            trav = trav->next;
        }
    }
}
void printPath(int parent[], int vertex, int startVertex)
{
    if (vertex == startVertex) {
        fprintf(out,"%d\t ", startVertex);
        return;
    } else if (parent[vertex] == 0) {	// current vertex has no parent
    	fprintf(out,"%d\t ", vertex);
    	return;
	}else {
        printPath(parent, parent[vertex], startVertex);
        fprintf(out,"%d ", vertex);
    }
}
int main()
{
	inp=fopen("input.txt","r");
	out=fopen("output.txt","w");
    int vertices, edges, i, j, v1, v2, w, startVertex;
    fscanf(inp,"%d", &vertices);
    fscanf(inp,"%d", &edges);
    struct node * adjacencyList[vertices + 1];	// to use the array as 1-indexed for simplicity
    int distances[vertices + 1];
    int parent[vertices + 1];
    for (i = 0; i <= vertices; ++i) {	// Must initialize your array
        adjacencyList[i] = NULL;
    }
    for (i = 1; i <= edges; ++i) {
        fscanf(inp,"%d %d %d", &v1, &v2, &w);
        adjacencyList[v1] = addEdge(adjacencyList[v1], v2, w);
    }
    fscanf(inp,"%d", &startVertex);
    dijkstra(adjacencyList, vertices, startVertex, distances, parent);
    for (i = 1; i <= vertices; ++i) {
    	fprintf(out,"%d\t", i);
	fprintf(out,"%d\n",distances[i]);
//    	printPath(parent, i, startVertex);
	}
    fclose(out);
fclose(inp);
    return 0;
}
