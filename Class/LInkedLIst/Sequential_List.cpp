#include "Sequential_List.h"
#include <stdio.h>

int main() {
    Sqlist list;
    list.Init();  // 初始化线性表

    // 测试插入
    list.Insert(0, 10);
    list.Insert(1, 20);
    list.Insert(2, 30);

    // 遍历输出线性表
    printf("线性表内容：");
    list.Traverse();

    // 测试查找
    int index = list.Seek(20);
    printf("查找20的位置：%d\n", index);

    // 测试修改
    list.ModifyAtIndex(1, 25);
    printf("修改后的线性表内容：");
    list.Traverse();

    // 测试删除
    int deletedValue;
    list.Delete(1, deletedValue);
    printf("删除后的线性表内容：");
    list.Traverse();

    // 测试统计
    printf("线性表中值为10的元素个数：%d\n", list.Count(10));

    return 0;
}

