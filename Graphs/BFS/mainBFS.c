#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"bfs.h"

int main() {
	int v, e, start;
	Graph* g=(Graph*)malloc(sizeof(Graph));
	printf("No. of vertices: \n");
	scanf("%d", &v);
	init(g,v);
	printf("No. of edges: \n");
	scanf("%d", &e);
	printf("Enter source, destination, weight: \n");
	for(int i=0;i<e;i++){
		int src, dest, wt;
		scanf("%d %d %d", &src, &dest, &wt);
		addEdge(g, src, dest, wt);
	}
	display(g);
	printf("Start Vertex: \n");
	scanf("%d", &start);
	printf("BFS: \n");
	bfs(g, start);
	printf("DFS: \n");
	dfs(g, start);
	for (int i = 0; i < g->v; i++) {
		Node* temp = g->adjList[i];
		while (temp != NULL) {
			Node* toFree = temp;
			temp = temp->next;
			free(toFree);
		}
	}
	free(g->adjList);
	free(g);

}
