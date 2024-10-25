#include <stdlib.h>

#define STACK_INIT_SIZE 100 // 栈的初始容量
#define STACKINCREMENT 10   // 栈的增量

typedef int SElemType;      // 栈元素类型，可以根据需要修改

typedef struct {
    SElemType *base;  // 栈底指针
    SElemType *top;   // 栈顶指针
    int stackSize;    // 栈容量
} SqStack;

// 初始化栈
int InitStack(SqStack *s){
    s->base = (SElemType *) malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if(!s->base)return 0;
    s->top = s->base;
    s->stackSize= STACK_INIT_SIZE;
    return 1;
}