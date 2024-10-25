#ifndef STUDY_QUEUE_H
#define STUDY_QUEUE_H

#include <stdio.h>

#define MaxSize 110

typedef struct  qNODE{

};
struct Squeue {
    int data[MaxSize];
    int real, front;

    void Init();

    bool Isempty();

    bool Isfull();

    bool Enterqueue(int x);

    bool Outqueue(int &e);

    bool Getheadlem(int &e);

    int Len();

    void Traverse();
};

bool Squeue::Isempty() {
    if (real == front) return true;
    return false;
}

void Squeue::Init() {
    front = real = MaxSize - 1;
}

bool Squeue::Isfull() {
    if (Len() == MaxSize - 1) return true;
    return false;
}

bool Squeue::Enterqueue(int x) {
    if (Isfull() == true)return false;
    real = (real + 1) % MaxSize;
    data[real] = x;
    return true;
}

bool Squeue::Outqueue(int &e) {
    if (Isempty() == true)return false;
    front = (front + 1) % MaxSize;
    e = data[front];
    return true;
}

bool Squeue::Getheadlem(int &e) {
    if (Isempty() == true) return false;
    e = data[(front + 1) % MaxSize];
    return true;
}

int Squeue::Len() {
    return (real - front + MaxSize) % MaxSize;
}

void Squeue::Traverse() {
    int i;
    for (i = (front + 1) % MaxSize; i - 1 != real; i = (i + 1) % MaxSize) {
        printf("%5d", data[i]);
    }
    printf("\n");
}

#endif //STUDY_QUEUE_H
