//
// Created by Liam on 2024/9/23.
//
#include <stdio.h>
#include "zhizhen.h"

int max(int x, int y) {
    return x > y ? x : y;
}

int main() {
    int (*p)(int, int) = &max;
    int a, b, c, d;
    printf("请输入三个数字:");
    scanf("%d %d %d", &a, &b, &c);
    d = p(p(a, b), c);
    printf("最大的数字是: %d\n", d);
    return 0;
}