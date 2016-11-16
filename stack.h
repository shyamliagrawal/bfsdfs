#define MAX_STACK 64
typedef struct{
	int top;
	int a[MAX_STACK];
}stack;
void init(stack *sp);
int pop(stack *sp);
int push(stack *sp, int n);
