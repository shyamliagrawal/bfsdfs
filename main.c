#include"graph.h"
int main() {
	graph g;
	put_graph(&g);
	get_graph(g);
	printf("\nBreadth First Search : \n");
	bfs(g);
	printf("\n\nDepth First Search : \n");
	dfs(g);
	putchar('\n');
	putchar('\n');
	del_graph(&g);
	return 0;
}
