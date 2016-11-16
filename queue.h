#define MAX_QUEUE 64
typedef struct{
	int front, end;
	int a[MAX_QUEUE];
}queue;
void initq(queue *qp);
int dequeue(queue *qp);
int enqueue(queue *qp, int n);
void print(queue *qp);

