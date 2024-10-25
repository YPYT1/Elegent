#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
}Stack;
void initStack(Stack *stack){
    stack->top = -1;
}
int isEmpty(Stack *stack){
    return stack->top == -1;
}
int isFull(Stack *stack){
    return stack->top == MAX -1;
}
void display(Stack* stack){
    if (isEmpty(stack)){
        printf("栈为空\n");
        return;
    }
    printf("栈中元素:");
    for (int i = 0; i <= stack->top; i++) {
        if (i == 0){
            printf("%d",stack->data[i]);
        } else{
            printf(" %d",stack->data[i]);
        }
    }
    printf("\n");
}
void push(Stack* stack,int value){
    if (isFull(stack)){
        printf("栈满，不能再压入元素。\n");
        return;
    }
    stack->data[++(stack->top)] = value;
}
int main(){
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    initStack(stack);
    push(stack,1);
    push(stack,2);
    push(stack,3);
    push(stack,4);
    display(stack);
    free(stack);
    return 0;
}