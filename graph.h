#include<stdio.h>
typedef struct listnode *listptr;
typedef struct listnode{
	int node;
	listptr link;
}listnode;
typedef struct graph{
	int v;
	listptr *nodes;
}graph;
void put_graph(graph*);
void get_graph(graph);
void del_graph(graph*);
int bfs(graph);
int dfs(graph);
