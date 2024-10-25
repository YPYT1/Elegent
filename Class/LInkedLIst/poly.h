#ifndef STUDY_POLY_H
#define STUDY_POLY_H

#include <cstdlib>
#include <stdio.h>
#include <iostream>

using namespace std;

struct shuju {
    float xishu;
    int zhishu;
};
struct Pnode {
    shuju data;
    Pnode *next;
};

struct Poly {
    Pnode *head;

    void Init();//初始化让head指向头节点
    void createpoly(int n);//有n项的多项式，这里没有同类项，按升幂来创建
    void Traverse();

    void Add(Poly &la, Poly &lb);

    void Sub(Poly &la, Poly &lb);

    void Add2(Poly &la, Poly &lb, Poly &lc);

    void Add3(Poly &polyA, Poly &polyB, Poly &resultPoly);

    void Mul(Poly la, Poly lb, Poly &lc);
};

void Poly::Init() {
    head = (Pnode *) malloc(sizeof(Pnode));
    head->next = NULL;
}

//按尾插法创建
void Poly::createpoly(int n) {
    Pnode *rear = head;
    for (int i = 0; i < n; i++) {
        Pnode *s = new Pnode;
        printf("请输入第 %d 项的系数: ", i);
        scanf("%f", &s->data.xishu);
        printf("请输入第 %d 项的指数: ", i);
        scanf("%d", &s->data.zhishu);
        s->next = nullptr;
        rear->next = s;
        rear = s;
    }
}



// 遍历并打印多项式
void Poly::Traverse() {
    Pnode *p = head->next;
    bool first = true;
    while (p) {
        if (p->data.xishu != 0) {
            if (!first) {
                printf(" + ");
            }
            printf("%.2fx^%d", p->data.xishu, p->data.zhishu);
            first = false;
        }
        p = p->next;
    }
    if (first) {
        printf("0");
    }
    printf("\n");
}


void Poly::Add(Poly &la, Poly &lb) {
    Pnode *p1 = la.head->next; // la 的第一个节点
    Pnode *p2 = lb.head->next; // lb 的第一个节点
    Pnode *p = head = (Pnode *) malloc(sizeof(Pnode)); // 初始化结果多项式的头节点
    p->next = NULL;
    Pnode *tail = p; // 用于跟踪结果多项式的尾部

    while (p1 != NULL && p2 != NULL) {
        Pnode *newNode = (Pnode *) malloc(sizeof(Pnode));
        if (p1->data.zhishu < p2->data.zhishu) {
            newNode->data = p2->data;
            p2 = p2->next;
        } else if (p1->data.zhishu > p2->data.zhishu) {
            newNode->data = p1->data;
            p1 = p1->next;
        } else {
            newNode->data.xishu = p1->data.xishu + p2->data.xishu;
            newNode->data.zhishu = p1->data.zhishu;
            p1 = p1->next;
            p2 = p2->next;
        }
        newNode->next = NULL;
        tail->next = newNode; // 将新节点加入到结果多项式
        tail = newNode; // 更新尾部
    }

    // 添加剩余的项
    while (p1 != NULL) {
        Pnode *newNode = (Pnode *) malloc(sizeof(Pnode));
        newNode->data = p1->data;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
        p1 = p1->next;
    }

    while (p2 != NULL) {
        Pnode *newNode = (Pnode *) malloc(sizeof(Pnode));
        newNode->data = p2->data;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
        p2 = p2->next;
    }
}

void Poly::Add2(Poly &la, Poly &lb, Poly &lc) {
    if (lb.head->next == NULL)return;
    Pnode *pa, *pb, *qa, *qb;
    pa = lb.head;
    pb = pa->next;
    qa = lb.head->next;
    qb = qa->next;
    for (; qb != NULL && qb != NULL;) {
        if (pb->data.zhishu < qa->data.zhishu) {
            pa = pb;
            pb = pb->next;
        } else if (pb->data.zhishu < qa->data.zhishu) {
            float a = pb->data.xishu + qa->data.xishu;
            if (a == 0) {
                pa->next = pb->next;
                free(pb);
                pb = pa->next;
                qa = qb;
                qb = qb->next;
            } else {
                pb->data.xishu = a;
                pa = pb;
                pb = pb->next;
                free(qa);
                qa = pb;
                qb = qb->next;
            }
        } else {
            qa->next = pb;
            pa->next = qa;
            pa = qa;
            qa = qb;
            qb = qb->next;
        }
        if (pb == NULL)pa->next = qa;
        if (qb == NULL) {
            for (; pb != NULL;) {
                if (pb->data.xishu < qa->data.xishu) {
                    pa = pb;
                    pb = pb->next;
                } else if (pb->data.xishu == qa->data.xishu) {
                    float b = pb->data.xishu + qa->data.xishu;
                    if (b == 0) {
                        pa->next = pb->next;
                        free(pb);
                        free(qa);
                    } else {
                        pb->data.xishu = b;
                        free(qa);
                        break;
                    }
                } else {
                    qa->next = pb;
                    pa->next = qa;
                    break;
                }
            }
        }
        if (pb == NULL) pa->next = qa;
    }
}

void Poly::Add3(Poly &polyA, Poly &polyB, Poly &resultPoly) {
    // 如果多项式 B 为空，直接将 polyA 复制到结果中
    if (polyB.head->next == NULL) {
        while (polyA.head->next != NULL) {
            Pnode *newNode = (Pnode *)malloc(sizeof(Pnode));
            newNode->data = polyA.head->next->data;
            newNode->next = resultPoly.head->next; // 在结果多项式头插
            resultPoly.head->next = newNode;
            polyA.head->next = polyA.head->next->next; // 移动到下一个节点
        }
        return;
    }

    Pnode *currentA = polyA.head->next; // polyA 的当前节点
    Pnode *currentB = polyB.head->next; // polyB 的当前节点
    Pnode *tail = resultPoly.head; // 用于构建结果多项式的尾部

    // 遍历两个多项式
    while (currentA != NULL && currentB != NULL) {
        Pnode *newNode = (Pnode *)malloc(sizeof(Pnode));

        if (currentA->data.zhishu < currentB->data.zhishu) {
            // polyA 的指数小于 polyB 的指数
            newNode->data = currentA->data; // 复制 polyA 的项
            currentA = currentA->next; // 移动到 polyA 的下一个节点
        } else if (currentA->data.zhishu > currentB->data.zhishu) {
            // polyA 的指数大于 polyB 的指数
            newNode->data = currentB->data; // 复制 polyB 的项
            currentB = currentB->next; // 移动到 polyB 的下一个节点
        } else {
            // 指数相同，系数相加
            newNode->data.xishu = currentA->data.xishu + currentB->data.xishu;
            newNode->data.zhishu = currentA->data.zhishu; // 指数保持不变
            currentA = currentA->next; // 移动到 polyA 的下一个节点
            currentB = currentB->next; // 移动到 polyB 的下一个节点
        }

        // 只添加系数非零的项
        if (newNode->data.xishu != 0) {
            newNode->next = NULL; // 新节点的下一个指针设置为 NULL
            tail->next = newNode; // 将新节点连接到结果多项式的末尾
            tail = newNode; // 更新尾指针
        } else {
            free(newNode); // 如果系数为零，释放新节点的内存
        }
    }

    // 将 polyA 中剩余的项添加到结果多项式
    while (currentA != NULL) {
        Pnode *newNode = (Pnode *)malloc(sizeof(Pnode));
        newNode->data = currentA->data;
        newNode->next = NULL;
        tail->next = newNode; // 将新节点连接到结果多项式的末尾
        tail = newNode; // 更新尾指针
        currentA = currentA->next; // 移动到下一个节点
    }

    // 将 polyB 中剩余的项添加到结果多项式
    while (currentB != NULL) {
        Pnode *newNode = (Pnode *)malloc(sizeof(Pnode));
        newNode->data = currentB->data;
        newNode->next = NULL;
        tail->next = newNode; // 将新节点连接到结果多项式的末尾
        tail = newNode; // 更新尾指针
        currentB = currentB->next; // 移动到下一个节点
    }
}


void Poly::Mul(Poly la, Poly lb, Poly &lc) {
    lc.Init();
    for (Pnode *pa = la.head->next; pa != nullptr; pa = pa->next) {
        for (Pnode *pb = lb.head->next; pb != nullptr; pb = pb->next) {
            Poly tempPoly;
            tempPoly.Init();

            Pnode *newNode = new Pnode;
            newNode->data.xishu = pa->data.xishu * pb->data.xishu;
            newNode->data.zhishu = pa->data.zhishu + pb->data.zhishu;
            newNode->next = nullptr;

            tempPoly.head->next = newNode;

            Poly resultTemp;
            resultTemp.Init();
            Add3(lc, tempPoly, resultTemp);

            // 释放 lc 的内存
            while (lc.head->next) {
                Pnode *temp = lc.head->next;
                lc.head->next = temp->next;
                delete temp;
            }

            // 将 resultTemp 赋值给 lc
            lc.head->next = resultTemp.head->next;
            resultTemp.head->next = nullptr;
        }
    }
}

#endif //STUDY_POLY_H
