//
// Created by Liam on 2024/9/25.
//

#ifndef STUDY_MAOPAO_H
#define STUDY_MAOPAO_H

#include "Sequential_List.h"

void Bubblesort(Sqlist &la) {
    int temp;
    bool sorted;
    for (int i = 0; i < la.length - 1; i++) {
        sorted = true;
        for (int j = 0; j < la.length - i - 1; j++) {
            if (la.data[j] > la.data[j + 1]) {
                temp = la.data[j];
                la.data[j] = la.data[j + 1];
                la.data[j + 1] = temp;
                sorted = false;
            }
        }
        if (sorted == true) break;
    }
}

/*void InsertSort(Sqlist &la) {
    int i, j, temp;
    for (i = 1; i < la.length; i++) {
        temp = la.data[i];
        j = i - 1;
        for (j = i - 1; j < 0 && la.data[j] > temp; j--) {
            la.data[j + 1] = la.data[j];
        }
        la.data[j + 1] = temp;
    }
}*/
void InsertSort(Sqlist &la) {
    int i, j, temp;
    for (i = 1; i < la.length; i++) {   // 从第二个元素开始
        temp = la.data[i];              // 记录当前要插入的元素
        j = i - 1;
        // 找到比 temp 大的元素，向右移动
        while (j >= 0 && la.data[j] > temp) {
            la.data[j + 1] = la.data[j];  // 元素右移
            j--;
        }
        la.data[j + 1] = temp;  // 将 temp 插入到正确位置
    }
}


/*void QuickSort(Sqlist &la, int left, int right) {
    int i, j, temp;
    i = left;
    temp = la.data[i];
    for (i = left; j = right; i < j) {
        for (; j < i && la.data[j] >= temp;) {
            j--;
            la.data[i] = la.data[j];
            for (;  j>i && la.data[i] <temp; ) {
                i++;
                la.data[j] = la.data[i];
            }
        }
    }
    la.data[i] = temp;
    if(left<i-1){
        QuickSort(la,left,i-1);
    }
    if(i+1 < right){
        QuickSort(la,i+1,right);
    }
}*/
void QuickSort(Sqlist &la, int left, int right) {
    if (left >= right) return;  // 基本条件，递归出口

    int i = left, j = right;
    int temp = la.data[left];  // 选择基准元素，通常取最左边的

    while (i < j) {
        // 从右向左找比基准小的元素
        while (i < j && la.data[j] >= temp) {
            j--;
        }
        if (i < j) {
            la.data[i] = la.data[j];  // 将比基准小的元素移到左边
        }

        // 从左向右找比基准大的元素
        while (i < j && la.data[i] <= temp) {
            i++;
        }
        if (i < j) {
            la.data[j] = la.data[i];  // 将比基准大的元素移到右边
        }
    }

    la.data[i] = temp;  // 将基准元素放到最终位置

    // 递归对左右部分进行排序
    QuickSort(la, left, i - 1);
    QuickSort(la, i + 1, right);
}

#endif //STUDY_MAOPAO_H
