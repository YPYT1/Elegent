#include <cstdlib>
#include <ctime>
#include "maopao.h"
#include "Sequential_List.h"

int main() {
    Sqlist la;      // 初始化线性表对象
    la.Init();      // 初始化线性表

    // 随机生成一些数据插入线性表
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        int value = rand() % 100;   // 生成0到99之间的随机数
        la.Insert(i, value);        // 在末尾插入数据
    }

    printf("Before sorting:\n");
    la.Traverse();   // 输出排序前的线性表
    // 使用快速排序
    printf("Sorting using Insertion Sort:\n");
    QuickSort(la, 0, la.length - 1);
//    InsertSort(la);
    la.Traverse();   // 输出插入排序后的线性表

    return 0;
}

