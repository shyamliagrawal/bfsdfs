#include"graph.h"
int main() {
	graph g;
	input_graph(&g);
	print_graph(g);
	printf("\nBreadth First Search : \n");
	bfs(g);
	printf("\n\nDepth First Search : \n");
	dfs(g);
	putchar('\n');
	del_graph(&g);
	return 0;
}
