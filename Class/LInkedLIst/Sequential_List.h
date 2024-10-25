#ifndef SEQUENTIAL_LIST_H
#define SEQUENTIAL_LIST_H

#include <cstdio>
 // 确保可以使用 bool 类型

#define MaxSize 15

struct Sqlist {
    int data[MaxSize];  // 操作的数据
    int length;  // 记录线性表中的数据长度

    void Init();  // 初始化线性表

    void Traverse();  // 遍历并输出线性表

    bool Insert(int i, int x);  // 插入操作

    bool Delete(int i, int &e);  // 删除操作

    bool Getelem(int i, int &e);  // 获取指定位置的数据并保存在e中

    void ModifyValue(int oldValue, int newValue);  // 将表中值为oldValue的所有数据改为newValue

    void ModifyAtIndex(int index, int value);  // 将指定位置的数替换为value

    int Seek(int x);  // 查找线性表中值为x的数据并返回下标，没有时返回-1

    bool Isfull();  // 判断线性表是否已满

    bool Isempty();  // 判断线性表是否为空

    int Count(int x);  // 统计线性表中值为x的数据个数
};

void Sqlist::Init() {
    length = 0;  // 初始化长度为0
}

bool Sqlist::Insert(int i, int x) {
    // 检查插入条件
    if (i < 0 || i > length || Isfull()) {
//        printf("Insertion failed at index %d\n", i);
        return false;
    }
    // 移动数据，腾出插入位置
    for (int k = length - 1; k >= i; k--) {
        data[k + 1] = data[k];
    }
    data[i] = x;  // 插入数据
    length++;  // 更新长度
    //printf("Inserted %d at index %d\n", x, i);  // 添加调试信息
    return true;
}

bool Sqlist::Delete(int i, int &e) {
    // 检查删除条件
    if (i < 0 || i >= length || Isempty()) {
        return false;
    }
    e = data[i];  // 保存被删除的元素
    // 移动数据，填补空位
    for (int k = i; k < length - 1; k++) {
        data[k] = data[k + 1];
    }
    length--;  // 更新长度
    return true;
}

bool Sqlist::Getelem(int i, int &e) {
    // 检查取值条件
    if (i >= 0 && i < length) {
        e = data[i];  // 返回第i个位置的元素
        return true;
    }
    return false;
}

void Sqlist::ModifyValue(int oldValue, int newValue) {
    // 将所有值为oldValue的元素替换为newValue
    for (int i = 0; i < length; i++) {
        if (data[i] == oldValue) {
            data[i] = newValue;
        }
    }
}

void Sqlist::ModifyAtIndex(int index, int value) {
    // 将指定位置的元素修改为value
    if (index >= 0 && index < length) {
        data[index] = value;
    }
}

int Sqlist::Seek(int x) {
    // 查找值为x的元素并返回其下标
    for (int i = 0; i < length; i++) {
        if (data[i] == x) {
            return i;
        }
    }
    return -1;  // 没有找到则返回-1
}

bool Sqlist::Isfull() {
    // 判断线性表是否已满
    return length == MaxSize;
}

bool Sqlist::Isempty() {
    // 判断线性表是否为空
    return length == 0;
}

int Sqlist::Count(int x) {
    // 统计线性表中值为x的元素个数
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (data[i] == x) {
            count++;
        }
    }
    return count;
}

void Sqlist::Traverse() {
    // 遍历并输出线性表中的元素
    for (int i = 0; i < length; i++) {
        printf("x = %d\n", data[i]);
//        printf("x = %5d\n", data[i]);
    }
//    printf("\n");
}

#endif  // SEQUENTIAL_LIST_H
