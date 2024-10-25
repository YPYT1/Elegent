//
// Created by Liam on 2024/9/22.
//
#include <cstdio>
#include <cstdlib>
#include "LinkedList.h"

int main() {
    head = NULL;
    printf("How many numbers:");
    int n, i, x;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter a postion\n");
        scanf("%d", &x);
        Insert(x);
    }
    Print();
}



