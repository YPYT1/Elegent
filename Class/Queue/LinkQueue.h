#ifndef STUDY_LINKQUEUE_H
#define STUDY_LINKQUEUE_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct qNODE{
    int data;           // �ڵ�洢������
    struct qNODE* next; // ָ����һ���ڵ��ָ��
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
// ��ʼ������
void Squeue::Init() {
    front = rear = NULL;
    size = 0;
}

// �������Ƿ�Ϊ��
bool Squeue::Isempty() {
    return (front == NULL);
}

// ��Ӳ���
bool Squeue::Enterqueue(int x) {
    // ����һ���½ڵ�
    qNODE* newNode = (qNODE*)malloc(sizeof(qNODE));
    if (!newNode) {
        printf("�ڴ����ʧ�ܡ�\n");
        return false;
    }
    newNode->data = x;
    newNode->next = NULL;

    if (Isempty()) {
        // ����Ϊ�գ��½ڵ�ͬʱ��ͷ��β
        front = rear = newNode;
    }
    else {
        // ���½ڵ����ӵ���ǰβ�ڵ�
        rear->next = newNode;
        rear = newNode; // ����βָ��
    }
    size++; // ���¶��г���
    return true;
}

// ���Ӳ���
bool Squeue::Outqueue(int &e) {
    if (Isempty()) {
        printf("����Ϊ�գ��޷����ӡ�\n");
        return false;
    }

    // �ݴ浱ǰͷ�ڵ�
    qNODE* temp = front;
    e = front->data; // ��ȡͷ�ڵ������
    front = front->next; // ����ͷָ��

    if (front == NULL) {
        // ���б�Ϊ�գ�����βָ��
        rear = NULL;
    }

    free(temp); // �ͷű��Ƴ��Ľڵ��ڴ�
    size--; // ���¶��г���
    return true;
}

// ��ȡ��ͷԪ��
bool Squeue::Getheadlem(int &e) {
    if (Isempty()) {
        printf("����Ϊ�գ���ͷԪ�ء�\n");
        return false;
    }
    e = front->data;
    return true;
}

// ��ȡ���г���
int Squeue::Len() {
    return size;
}

// ��������
void Squeue::Traverse() {
    if (Isempty()) {
        printf("����Ϊ�ա�\n");
        return;
    }
    qNODE* current = front;
    printf("����Ԫ��: ");
    while (current != NULL) {
        printf("%5d", current->data);
        current = current->next;
    }
    printf("\n");
}

#endif //STUDY_LINKQUEUE_H