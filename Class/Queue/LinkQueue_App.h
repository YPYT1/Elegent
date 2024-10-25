#ifndef STUDY_LINKQUEUE_APP_H
#define STUDY_LINKQUEUE_APP_H
#include "../stack/stack.h"
#include "LinkQueue.h"

//进制转换
//将十进制转换成其他进制数
//如何分离整数部分和小数部分，如y=12.35;int m = y;float x = y-m;
//S装整数部分，Q装小数部分 r是说转换成多少进制用数字表示
//我这里要实现的是转成2进制
// 修正后的 printqueue 函数
void printqueue(Squeue Q){
    qNODE *p;
    for (p = Q.front; p != NULL; p = p->next) {
        switch (p->data) {
            case 15:
                printf("F");
                break;
            case 14:
                printf("E");
                break;
            case 13:
                printf("D");
                break;
            case 12:
                printf("C");
                break;
            case 11:
                printf("B");
                break;
            case 10:
                printf("A");
                break;
            default:
                printf("%d", p->data);
        }
    }
}

// 修正后的 ten_to_other 函数
void ten_to_other(float y, int r, Lstack &S, Squeue &Q){
    int m, k = 7, n;
    float x;
    m = (int)y;       // 取整数部分
    x = y - m;        // 取小数部分
    while (m != 0) {
        n = m % r;
        S.push(n);
        m = m / r;
    }
    while (x != 0.0 && k > 0) {
        x = x * r;
        n = (int)x;
        Q.Enterqueue(n);
        x = x - n;
        k--;
    }
}



#endif //STUDY_LINKQUEUE_APP_H