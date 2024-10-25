#ifndef STUDY_LINKQUEUE_H
#define STUDY_LINKQUEUE_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct qNODE{
    int data;           // 节点存储的数据
    struct qNODE* next; // 指向下一个节点的指针
}qNODE;

struct Squeue{
    qNODE* front;
    qNODE* rear;
    int size;

    void Init();
    bool Isempty();
    bool Outqueue(int &e);
    bool Enterqueue(int x);
    bool Getheadlem(int &e);
    int Len();
    void Traverse();
    void Destory();
};
// 初始化队列
void Squeue::Init() {
    front = rear = NULL;
    size = 0;
}

// 检查队列是否为空
bool Squeue::Isempty() {
    return (front == NULL);
}

// 入队操作
bool Squeue::Enterqueue(int x) {
    // 创建一个新节点
    qNODE* newNode = (qNODE*)malloc(sizeof(qNODE));
    if (!newNode) {
        printf("内存分配失败。\n");
        return false;
    }
    newNode->data = x;
    newNode->next = NULL;

    if (Isempty()) {
        // 队列为空，新节点同时是头和尾
        front = rear = newNode;
    }
    else {
        // 将新节点链接到当前尾节点
        rear->next = newNode;
        rear = newNode; // 更新尾指针
    }
    size++; // 更新队列长度
    return true;
}

// 出队操作
bool Squeue::Outqueue(int &e) {
    if (Isempty()) {
        printf("队列为空，无法出队。\n");
        return false;
    }

    // 暂存当前头节点
    qNODE* temp = front;
    e = front->data; // 获取头节点的数据
    front = front->next; // 更新头指针

    if (front == NULL) {
        // 队列变为空，更新尾指针
        rear = NULL;
    }

    free(temp); // 释放被移除的节点内存
    size--; // 更新队列长度
    return true;
}

// 获取队头元素
bool Squeue::Getheadlem(int &e) {
    if (Isempty()) {
        printf("队列为空，无头元素。\n");
        return false;
    }
    e = front->data;
    return true;
}

// 获取队列长度
int Squeue::Len() {
    return size;
}

// 遍历队列
void Squeue::Traverse() {
    if (Isempty()) {
        printf("队列为空。\n");
        return;
    }
    qNODE* current = front;
    printf("队列元素: ");
    while (current != NULL) {
        printf("%5d", current->data);
        current = current->next;
    }
    printf("\n");
}

#endif //STUDY_LINKQUEUE_H