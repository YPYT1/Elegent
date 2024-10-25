#include <stdio.h>
#define MaxSize 50

// 声明线性表结构体
struct Sqlist {
    int data[MaxSize];  // 操作的数据
    int length;  // 记录线性表中的数据长度
    void Init();  // 初始化线性表
    void Traverse();  // 遍历并输出线性表
    bool Insert(int i, int x);  // 插入操作
    bool Isfull() {  // 判断线性表是否已满
        return length == MaxSize;
    }
};

// 函数声明
void Deduplication(Sqlist &la);
void Union(Sqlist &la, Sqlist &lb, Sqlist &lc);

// 线性表的初始化
void Sqlist::Init() {
    length = 0;  // 初始化长度为0
}

// 遍历线性表并输出
void Sqlist::Traverse() {
    for (int i = 0; i < length; i++) {
        printf("\tx = %d", data[i]);
    }
    printf("\n");
}

// 插入操作
bool Sqlist::Insert(int i, int x) {
    if (i < 0 || i > length || Isfull()) {
        return false;
    }
    // 移动数据，腾出插入位置
    for (int k = length - 1; k >= i; k--) {
        data[k + 1] = data[k];
    }
    data[i] = x;  // 插入数据
    length++;  // 更新长度
    return true;
}

int main() {
    Sqlist la, lb, lc;  // 声明线性表集合
    la.Init();  // 初始化集合 la
    lb.Init();  // 初始化集合 lb
    lc.Init();  // 初始化集合 lc

    // 给集合 la 插入一些数据
    la.Insert(0, 10);
    la.Insert(1, 20);
    la.Insert(2, 30);
    la.Insert(3, 40);
    la.Insert(4, 50);
    la.Insert(5, 20);  // 重复元素
    la.Insert(6, 30);  // 重复元素

    // 给集合 lb 插入一些数据
    lb.Insert(0, 30);
    lb.Insert(1, 40);
    lb.Insert(2, 50);
    lb.Insert(3, 60);
    lb.Insert(4, 70);
    lb.Insert(5, 30);  // 重复元素
    lb.Insert(6, 40);  // 重复元素

    printf("原始集合la:\n");
    la.Traverse();
    // 去重
    Deduplication(la);
    printf("集合la去重后:\n");
    la.Traverse();

    printf("原始集合lb:\n");
    lb.Traverse();
    Deduplication(lb);
    printf("集合lb去重后:\n");
    lb.Traverse();

    // 求并集
    Union(la, lb, lc);
    printf("la与lb求并集后:\n");
    lc.Traverse();

    return 0;
}

// 去重函数
void Deduplication(Sqlist &la) {
    for (int i = 0; i < la.length - 1; i++) {
        for (int j = i + 1; j < la.length; j++) {
            if (la.data[i] == la.data[j]) {
                // 找到重复的元素，删除它
                for (int k = j; k < la.length - 1; k++) {
                    la.data[k] = la.data[k + 1];  // 将后面的元素往前移动
                }
                la.length--;
                j--;
            }
        }
    }
}

// 并集函数
void Union(Sqlist &la, Sqlist &lb, Sqlist &lc) {
    // 先将集合 la 的元素复制到 lc 中
    for (int i = 0; i < la.length; i++) {
        lc.Insert(i, la.data[i]);
    }

    // 遍历集合 lb，将不在 lc 中的元素插入到 lc 中
    for (int i = 0; i < lb.length; i++) {
        bool found = false;
        for (int j = 0; j < lc.length; j++) {
            if (lb.data[i] == lc.data[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            lc.Insert(lc.length, lb.data[i]);  // 插入不重复的元素
        }
    }
    Deduplication(lc);
}
