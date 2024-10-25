#include <stdlib.h>

#define STACK_INIT_SIZE 100 // ջ�ĳ�ʼ����
#define STACKINCREMENT 10   // ջ������

typedef int SElemType;      // ջԪ�����ͣ����Ը�����Ҫ�޸�

typedef struct {
    SElemType *base;  // ջ��ָ��
    SElemType *top;   // ջ��ָ��
    int stackSize;    // ջ����
} SqStack;

// ��ʼ��ջ
int InitStack(SqStack *s){
    s->base = (SElemType *) malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if(!s->base)return 0;
    s->top = s->base;
    s->stackSize= STACK_INIT_SIZE;
    return 1;
}