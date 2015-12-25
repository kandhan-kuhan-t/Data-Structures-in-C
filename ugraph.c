#include<stdio.h>
#include<stdlib.h>
struct adjListNode{
	int node;
	struct adjListNode *next;
};

struct adjList{
	struct adjList *head;
};

struct graph{
	int vertices;
	struct adjList *array;
};

struct adjListNode *createNewNode(int node){
	struct adjListNode *newNode = (struct adjListNode*)malloc(sizeof(struct adjListNode));
	newNode->node = node;
	newNode->next = NULL;
	return newNode;
}

struct graph *createNewGraph(int vertices){
	struct graph *newGraph = (struct graph*)malloc(sizeof(struct graph));
	newGraph->vertices = vertices;
	newGraph->array = (struct adjList*)malloc(vertices * sizeof(struct adjList));
	int i;
	for(i=0; i<vertices; i++){
		newGraph->array[i].head = NULL;
}
	return newGraph;
}
void addEdge(struct graph *graph, int src, int dest){
	struct adjListNode *newNode = createNewNode(dest);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;

	newNode = createNewNode(src);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
}

void printGraph(struct graph *graph){
	int i;
	for(i=0; i<graph->vertices; i++){
		struct adjListNode *crawl = graph->array[i].head;
		printf("Adjacency list of vertex %d\n Head ",i);
	while(crawl){
			printf(" -> %d",crawl->node);
			crawl = crawl->next;
			}
		printf("\n");
		}
}

int main()
{
	int vertices = 5;
	struct graph *graph = createNewGraph(vertices);
	addEdge(graph, 0, 1);
    	addEdge(graph, 0, 4);
    	addEdge(graph, 1, 2);
    	addEdge(graph, 1, 3);
    	addEdge(graph, 1, 4);
    	addEdge(graph, 2, 3);
    	addEdge(graph, 3, 4);
	printGraph(graph);
	return 0;
}		
