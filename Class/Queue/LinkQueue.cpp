#include "LinkQueue.h"

// 主函数用于测试
int main(){
    Squeue q;      // 创建队列对象
    int x;

    q.Init();      // 初始化队列

    // 入队操作
    q.Enterqueue(10);
    q.Enterqueue(20);
    q.Enterqueue(30);
    q.Enterqueue(40);
    q.Enterqueue(50);

    // 遍历队列
    q.Traverse();  // 输出: 队列元素:   10   20   30   40   50

    // 获取队头元素
    if(q.Getheadlem(x)){
        printf("队头元素: %d\n", x); // 输出: 队头元素: 10
    }

    // 出队操作
    if(q.Outqueue(x)){
        printf("出队元素: %d\n", x); // 输出: 出队元素: 10
    }

    // 再次遍历队列
    q.Traverse();  // 输出: 队列元素:   20   30   40   50

    // 获取队列长度
    printf("队列长度 = %d\n", q.Len()); // 输出: 队列长度 = 4

    q.Traverse(); // 输出: 队列为空。

    return 0;
}