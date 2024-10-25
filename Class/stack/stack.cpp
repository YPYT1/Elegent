#include "stack.h"

int main() {
    Lstack lstack; // 创建链栈实例
    lstack.Init(); // 初始化链栈

    // 测试入栈
    printf("入栈测试:\n");
    for (int i = 1; i <= 5; i++) {
        if (lstack.push(i)) {
            printf("成功入栈: %d\n", i);
        } else {
            printf("入栈失败: %d\n", i);
        }
    }

    // 遍历链栈
    printf("当前链栈元素: ");
    lstack.Traverse();

    // 获取栈顶元素
    SElemType topElem;
    if (lstack.getTopElem(topElem)) {
        printf("栈顶元素: %d\n", topElem);
    } else {
        printf("链栈为空，无法获取栈顶元素。\n");
    }

    // 测试出栈
    printf("出栈测试:\n");
    SElemType popped;
    while (lstack.pop(popped)) {
        printf("成功出栈: %d\n", popped);
    }

    // 最终遍历链栈
    printf("出栈后的链栈元素: ");
    lstack.Traverse();

    // 销毁链栈，释放内存
    lstack.Destroy();

    return 0;
}
