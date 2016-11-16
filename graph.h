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
void input_graph(graph*);//get graph input from user and sace in graph
void print_graph(graph);//get from structure and put on standard output
void del_graph(graph*);
int bfs(graph);
int dfs(graph);
