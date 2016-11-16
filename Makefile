obj = main.o graph.o queue.o stack.o
bfs_dfs : $(obj)
	cc -o bfs_dfs $(obj)
main.o graph.o : graph.h
stack.o : stack.h
queue.o : queue.h
clean:
	rm $(obj)
