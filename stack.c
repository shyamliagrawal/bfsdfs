#include"stack.h"
void init(stack *sp) {
	sp->top = 0;
}
int pop(stack *sp){
	if(!sp->top)
		return -1;
	sp->top--;
	return sp->a[sp->top];
}
int push(stack *sp, int n) {
	if(sp->top == MAX_STACK)	
		return -1;
	sp->a[sp->top++] = n;
	return 0;
}
