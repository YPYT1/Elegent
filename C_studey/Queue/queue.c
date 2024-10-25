#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
typedef struct {
    int data[MaxSize];
    int front;
    int real;
} queue;

void initQue(queue *q) {
    q->front = 0;
    q->real = 0;
};

// 判断队列是否为空
int isEmpty(queue *q) {
    return (q->real + 1) % MaxSize == q->front;
}

