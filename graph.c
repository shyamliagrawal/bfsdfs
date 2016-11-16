#include<stdlib.h>
#include"stack.h"
#include"queue.h"
#include"graph.h"
#define MALLOC(p,s)	p = malloc(s); if(p == NULL) {perror("malloc"); exit(1);}
#define YES 1
#define NO 2
void put_graph(graph *gptr) {	
	int n ,a, b, i;	
	printf("Number of vertices : ");
	scanf("%d", &gptr->v);
	MALLOC(gptr->nodes, gptr->v * sizeof(listptr));
	for(i = 0; i < gptr->v; i++)
		gptr->nodes[i] = NULL;	
	printf("Enter number of edges : ");
	scanf("%d", &n);
	printf("Enter the edges in format : node1-node2\n");
	listptr ap, bp;
	for(i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		a = a-1;
		b = b-1;
		MALLOC(ap, sizeof(listnode));
		MALLOC(bp, sizeof(listnode));
		ap->node = b;
		ap->link = gptr->nodes[a];
		gptr->nodes[a] = ap;
		bp->node = a;
		bp->link = gptr->nodes[b];
		gptr->nodes[b] = bp;
	}
}
void get_graph(graph g) {
	int i;
	printf("Number of vertices : %d\nAdjancy List : \n", g.v);
	listptr temp; 	
	for(i = 0; i < g.v; i++) {
		printf("%3d", i + 1);
		temp = g.nodes[i];
		while(temp != NULL) {
			printf(" -->%3d", temp->node + 1);
			temp = temp->link;
		}
		putchar('\n');
	}
}
void del_graph(graph *gptr){
	int i;
	listptr temp, next;
	for(i = 0; i < gptr->v; i++) {
		temp = gptr->nodes[i];
		while(temp != NULL) {
			next = temp->link;
			free(temp);
			temp = next;
		}
	}
	free(gptr->nodes);

}
int bfs(graph g) {
	int i, v, *visited, count = 0;
	listptr temp;
	MALLOC(visited, g.v * sizeof(int));
	for(i = 1; i < g.v; i++)
		visited[i] = NO;
	queue q;
	initq(&q);
	printf("1");
	enqueue(&q, 0);
	visited[0] = YES;
	v = 0;
	count++;
	while(count < g.v) {
		for(temp = g.nodes[v]; temp != NULL; temp = temp->link) 
			if(visited[temp->node] == NO) {
				printf("-->%d", temp->node + 1);
				count++;
				enqueue(&q, temp->node);
				visited[temp->node] = YES; 
			}
		v = dequeue(&q);
		if(v == -1) {
			putchar('\n');
			for(i = 1; i < g.v; i++)
				if(visited[i] == NO) {
					printf("-->%d", i + 1);
					count++;
					visited[i] = YES;
					v = i; 
					break;
				}
		}	
	}
	return 0;
}
int dfs(graph g) {
	int i, v, *visited, count = 0;
	listptr temp;
	MALLOC(visited, g.v * sizeof(int));
	for(i = 1; i < g.v; i++)
		visited[i] = NO;
	stack s;
	init(&s);
	printf("1");
	push(&s, 0);
	visited[0] = YES;
	v = 0;
	count++;
	while(count < g.v && v != -1) {
		for(temp = g.nodes[v]; temp != NULL; temp = temp->link) 
			if(visited[temp->node] == NO) {
				v = temp->node;
				printf("-->%d", v + 1);
				count++;
				push(&s, v);
				visited[v] = YES;
				break;
			}
		if(temp == NULL)
			v = pop(&s);	
		if(v == -1) {
			putchar('\n');
			for(i = 1; i < g.v; i++)
				if(visited[i] == NO) {
					printf("-->%d", i + 1);
					count++;	
					push(&s, i);
					visited[i] = YES;
					v = i; 
					break;
				}
		}			
	}
	return 0;
}
