#include <stdlib.h>
#include <stdio.h>

#define MaxSize 1000
typedef int SElemType; // 栈元素类型，可以根据需要修改

// 链栈节点定义
struct NODE {
    SElemType data;
    NODE *next;
};

// 链栈定义
struct Lstack {
    NODE *top;
    void Init(); // 初始化
    bool isEmpty(); // 判断是否为空
    bool push(SElemType x); // 将x入栈
    bool pop(SElemType &e); // 将出栈数据保存在e中
    bool getTopElem(SElemType &e); // 取出栈顶元素
    void Traverse(); // 输出
    void Destroy(); // 销毁栈
};

// 初始化链栈
void Lstack::Init() {
    top = (NODE *)malloc(sizeof(NODE));
    if (top != NULL) {
        top->next = NULL;
    }
}

// 判断链栈是否为空
bool Lstack::isEmpty() {
    return top->next == NULL;
}

// 入栈操作（头插法）
bool Lstack::push(SElemType x) {
    NODE *s = (NODE *)malloc(sizeof(NODE));
    if (s == NULL) {
        // 内存分配失败
        return false;
    }
    s->data = x;
    s->next = top->next;
    top->next = s;
    return true;
}

// 出栈操作
bool Lstack::pop(SElemType &e) {
    if (isEmpty()) return false;
    NODE *s = top->next;
    e = s->data;
    top->next = s->next;
    free(s);
    return true;
}

// 获取栈顶元素
bool Lstack::getTopElem(SElemType &e) {
    if (isEmpty()) return false;
    e = top->next->data;
    return true;
}

// 遍历输出栈元素
void Lstack::Traverse() {
    NODE *current = top->next;
    while (current != NULL) {
        printf("%5d", current->data);
        current = current->next;
    }
    printf("\n");
}

// 销毁链栈，释放所有节点
void Lstack::Destroy() {
    NODE *current = top;
    while (current != NULL) {
        NODE *temp = current;
        current = current->next;
        free(temp);
    }
    top = NULL;
}

// 顺序栈定义
typedef struct {
    SElemType data[MaxSize];
    int top; // 记录栈顶元素位置
    void Init(); // 初始化
    bool Isempty(); // 判断是否为空
    bool Isfull(); // 判断是否已满
    bool push(SElemType x); // 将x入栈
    bool Pop(SElemType &e); // 将出栈数据保存在e中
    bool GetTopElem(SElemType &e); // 取出栈顶元素
    void Traverse(); // 输出
} SqStack;

// 初始化顺序栈
void SqStack::Init() {
    top = -1;
}

// 判断顺序栈是否为空
bool SqStack::Isempty() {
    return top == -1;
}

// 判断顺序栈是否已满
bool SqStack::Isfull() {
    return top == MaxSize - 1;
}

// 入栈操作
bool SqStack::push(SElemType x) {
    if (Isfull()) return false;
    data[++top] = x;
    return true;
}

// 出栈操作
bool SqStack::Pop(SElemType &e) {
    if (Isempty()) return false;
    e = data[top--];
    return true;
}

// 获取栈顶元素
bool SqStack::GetTopElem(SElemType &e) {
    if (Isempty()) {
        return false;
    }
    e = data[top];
    return true;
}

// 遍历输出栈元素
void SqStack::Traverse() {
    int i = top;
    while (i >= 0) {
        printf("%5d", data[i]);
        i--;
    }
    printf("\n");
}
