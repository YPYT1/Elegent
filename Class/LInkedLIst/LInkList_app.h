#include "Linklist.h"

void Meger2(List &la, List &lb) {
    NODE *pa, *pb, *qa, *qb;
    if (lb.head->next == NULL)return;
    pa = la.head;
    pb = pa->next;
    qa = lb.head;
    qb = qa->next;
    for (; pb != NULL && qb != NULL;) {
        if (pb->data > qa->data) {
            qa->next = pb;
            pa->next = qa;
            pa = qa;
            qa = qb;
            qb = qb->next;
        } else {
            pa = pb;
            pb = pb->next;
        }
    }
    if (pb == NULL) {
        pa->next = qa;
    }
    if (qb == NULL) {
        for (; pb != NULL;) {
            if (qb->data > qa->data) {
                qa->next = pb;
                pa->next = qa;
                break;
            } else {
                pa = pb;
                pb = pb->next;
            }
            if (pb == NULL) {
                pa->next = qa;
            }
        }
    }
    lb.head->next == NULL;
}

//将两个有序的单链表合并成一个单链表，使合并后的单链表仍然有序（同序）
void Meger(List La, List Lb, List &Lc) {
    NODE *p, *q, *s, *t;
    for (p = La.head->next, q = Lb.head->next; p != NULL && q != NULL;) {
        s = Lc.head;
        if (p->data <= q->data) {
            t = (NODE *) malloc(sizeof(NODE));
            t->data = p->data;
            t->next = NULL;
            s->next = s;
            s = t;
            p = p->next;
        } else {
            t = (NODE *) malloc(sizeof(NODE));
            t->data = q->data;
            t->next = NULL;
            s->next = s;
            s = t;
            q = q->next;
        }
    }
    for (; p != NULL; p = p->next) {//La没有结束
        t = (NODE *) malloc(sizeof(NODE));
        t->data = p->data;
        t->next = NULL;
        s->next = s;
        s = t;
        p = p->next;
    }
    for (; q != NULL; q = q->next) {
        t = (NODE *) malloc(sizeof(NODE));
        t->data = q->data;
        t->next = NULL;
        s->next = s;
        s = t;
        q = q->next;
    }
}


//对单链表进行排序（选择法）
void Selectsort(List &La) {
    NODE *q, *s, *p;
    if (La.head->next == NULL) return;
    for (s = La.head->next; s->next != NULL; s = s->next) {
        q = s;
        for (p = s->next; p != NULL; p = p->next) {
            if (p->data < q->data) q = p;
        }
        if (q != s) {
            int temp;
            temp = q->data;
            q->data = s->data;
            s->data = temp;
        }
    }

}


//将单链表进行倒序存储
void Reverse_placement(List &La, List &Lb) {
    if (La.head->next == NULL) return;
    NODE *s, *q, *p;
    s = La.head;
    q = Lb.head;
    for (p = s->next; p != NULL; p = s->next) {
        s->next = p->next;
        p->next = q->next;
        q->next = p;
    }
    La.head->next = NULL;
}


//将单链表分成两相单链表，一个存储奇数，一个存储偶数。
void Split(List La, List &Lb, List &Lc) {
    NODE *p, *q, *s, *t;
    q = Lb.head;
    t = Lc.head;
    for (p = La.head->next; p != NULL; p = p->next) {
        s = (NODE *) malloc(sizeof(NODE));
        s->next = NULL;
        s->data = p->data;
        if (p->data % 2 == 1) {
            q->next = s;
            q = s;
        } else {
            t->next = s;
            t = s;
        }
    }
}

void List::Traverse() {

}