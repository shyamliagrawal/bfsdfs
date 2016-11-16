#include"queue.h"
#include<stdio.h>
void initq(queue *qp) {
	qp->front = -1;
	qp->end = -1;
}
int dequeue(queue *qp) {
	if(qp->front == qp->end)
		return -1;
	qp->front = (qp->front+1)%MAX_QUEUE;
	return(qp->a[qp->front]);
	return 0;
}
int enqueue(queue *qp, int n) {
	qp->end = (qp->end+1)%MAX_QUEUE;
	if(qp->front == qp->end)
		return -1;
	qp->a[qp->end] = n;
	return 0;
}
