#include "Sequential_List.h"

//去除线性表中的重复数据 1 2 2 3 1 2 33 2 变成1 2 3
void del_repeat_elem(Sqlist &la) {
    int i, j, x;
    for (int i = 0; i < la.length - 1; i++) {
        for (j = la.length - 1; j > i; j--) {
            if (la.data[j] == la.data[i]) {
                la.Delete(j, x);
                printf("x=%d", x);
            }
        }
    }
}

//将一个线性表分成两个线性表，一个存储奇数，一个存储偶数
void Sqlst(Sqlist La, Sqlist &Lb, Sqlist &Lc) {
    int i, j, k;
    j = 0;
    k = 0;
    for (i = 0; i < La.length; i++) {
        if (La.data[i] % 2 == 0) {
            Lb.Insert(j++, La.data[i]);
        } else {
            Lc.Insert(k++, La.data[i]);
        }
    }
}

//将线性表的数据元素进行逆置：1 2 3 4
void Reverse_placement(Sqlist &La) {
    int i, j, temp;
    for (i = 0, j = La.length - 1; i < j; i++, j--) {
        temp = La.data[i];
        La.data[i] = La.data[j];
        La.data[j] = temp;
    }
}

//把线性表看成是集合，求两个集合的交集
void Jjiaojie(Sqlist la, Sqlist lb, Sqlist &lc) {
    int i, k = 0, x;
    del_repeat_elem(la);
    la.Traverse();
    del_repeat_elem(lb);
    lb.Traverse();
    for (int i = 0; i < la.length; i++) {
        lb.Seek(la.data[i]);//在lb中查找la.data[i]这个数
        if (x >= 0) {
            lc.Insert(k++, la.data[i]);
        }
    }
}

//交换排序
void Sqwpsort(Sqlist &la) {
    int i, j, temp;
    for (i = 0; i < la.length - 1; i++) {
        for (j = la.length - 1; j < i; j--) {
            if (la.data[j] < la.data[i]) {
                la.data[j] = la.data[i];
                la.data[i] = temp;
            }
        }
    }
}

//选择排序
void Selectorst(Sqlist &la) {
    int i, j, q, temp;
    for (i = 0; i < la.length; i++) {
        q = i;
        for (j = i + 1; j < la.length; j++) {
            if (la.data[j] < la.data[q]) q = j;
        }
        if(q != i){
            temp = la.data[i];
            la.data[i] = la.data[q];
            la.data[q] = temp;
        }
    }
}