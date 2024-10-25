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

    void Init();//��ʼ����headָ��ͷ�ڵ�
    void createpoly(int n);//��n��Ķ���ʽ������û��ͬ���������������
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

//��β�巨����
void Poly::createpoly(int n) {
    Pnode *rear = head;
    for (int i = 0; i < n; i++) {
        Pnode *s = new Pnode;
        printf("������� %d ���ϵ��: ", i);
        scanf("%f", &s->data.xishu);
        printf("������� %d ���ָ��: ", i);
        scanf("%d", &s->data.zhishu);
        s->next = nullptr;
        rear->next = s;
        rear = s;
    }
}



// ��������ӡ����ʽ
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
    Pnode *p1 = la.head->next; // la �ĵ�һ���ڵ�
    Pnode *p2 = lb.head->next; // lb �ĵ�һ���ڵ�
    Pnode *p = head = (Pnode *) malloc(sizeof(Pnode)); // ��ʼ���������ʽ��ͷ�ڵ�
    p->next = NULL;
    Pnode *tail = p; // ���ڸ��ٽ������ʽ��β��

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
        tail->next = newNode; // ���½ڵ���뵽�������ʽ
        tail = newNode; // ����β��
    }

    // ���ʣ�����
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
    // �������ʽ B Ϊ�գ�ֱ�ӽ� polyA ���Ƶ������
    if (polyB.head->next == NULL) {
        while (polyA.head->next != NULL) {
            Pnode *newNode = (Pnode *)malloc(sizeof(Pnode));
            newNode->data = polyA.head->next->data;
            newNode->next = resultPoly.head->next; // �ڽ������ʽͷ��
            resultPoly.head->next = newNode;
            polyA.head->next = polyA.head->next->next; // �ƶ�����һ���ڵ�
        }
        return;
    }

    Pnode *currentA = polyA.head->next; // polyA �ĵ�ǰ�ڵ�
    Pnode *currentB = polyB.head->next; // polyB �ĵ�ǰ�ڵ�
    Pnode *tail = resultPoly.head; // ���ڹ����������ʽ��β��

    // ������������ʽ
    while (currentA != NULL && currentB != NULL) {
        Pnode *newNode = (Pnode *)malloc(sizeof(Pnode));

        if (currentA->data.zhishu < currentB->data.zhishu) {
            // polyA ��ָ��С�� polyB ��ָ��
            newNode->data = currentA->data; // ���� polyA ����
            currentA = currentA->next; // �ƶ��� polyA ����һ���ڵ�
        } else if (currentA->data.zhishu > currentB->data.zhishu) {
            // polyA ��ָ������ polyB ��ָ��
            newNode->data = currentB->data; // ���� polyB ����
            currentB = currentB->next; // �ƶ��� polyB ����һ���ڵ�
        } else {
            // ָ����ͬ��ϵ�����
            newNode->data.xishu = currentA->data.xishu + currentB->data.xishu;
            newNode->data.zhishu = currentA->data.zhishu; // ָ�����ֲ���
            currentA = currentA->next; // �ƶ��� polyA ����һ���ڵ�
            currentB = currentB->next; // �ƶ��� polyB ����һ���ڵ�
        }

        // ֻ���ϵ���������
        if (newNode->data.xishu != 0) {
            newNode->next = NULL; // �½ڵ����һ��ָ������Ϊ NULL
            tail->next = newNode; // ���½ڵ����ӵ��������ʽ��ĩβ
            tail = newNode; // ����βָ��
        } else {
            free(newNode); // ���ϵ��Ϊ�㣬�ͷ��½ڵ���ڴ�
        }
    }

    // �� polyA ��ʣ�������ӵ��������ʽ
    while (currentA != NULL) {
        Pnode *newNode = (Pnode *)malloc(sizeof(Pnode));
        newNode->data = currentA->data;
        newNode->next = NULL;
        tail->next = newNode; // ���½ڵ����ӵ��������ʽ��ĩβ
        tail = newNode; // ����βָ��
        currentA = currentA->next; // �ƶ�����һ���ڵ�
    }

    // �� polyB ��ʣ�������ӵ��������ʽ
    while (currentB != NULL) {
        Pnode *newNode = (Pnode *)malloc(sizeof(Pnode));
        newNode->data = currentB->data;
        newNode->next = NULL;
        tail->next = newNode; // ���½ڵ����ӵ��������ʽ��ĩβ
        tail = newNode; // ����βָ��
        currentB = currentB->next; // �ƶ�����һ���ڵ�
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

            // �ͷ� lc ���ڴ�
            while (lc.head->next) {
                Pnode *temp = lc.head->next;
                lc.head->next = temp->next;
                delete temp;
            }

            // �� resultTemp ��ֵ�� lc
            lc.head->next = resultTemp.head->next;
            resultTemp.head->next = nullptr;
        }
    }
}

#endif //STUDY_POLY_H
