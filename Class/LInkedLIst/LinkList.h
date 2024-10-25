#ifndef STUDY_LINKLIST_H
#define STUDY_LINKLIST_H

#include <cstdlib>
#include <cstdio>

struct NODE {
    int data;
    struct NODE *next;
};

struct List {
    NODE *head;

    void Init();  // 初始化链表
    void TailCreate(int n);

    void HeadCreate(int n);

    void Traverse();  // 遍历并输出线性表
    void Insert(int i, int x);  // 插入操作
    bool Isempty();  // 判断线性表是否为空
    bool Delete(int i, int &e);  // 删除操作

    bool Getelem(int i, int &e);  // 获取指定位置的数据并保存在e中
    void ModifyValue(int oldValue, int newValue);  // 将表中值为oldValue的所有数据改为newValue
    void ModifyAtIndex(int index, int value);  // 将指定位置的数替换为value
    int Seek(int x);  // 查找单链表表中值为x的数据并返回位置，没有时返回-1
    int Count(int x);  // 统计线性表中值为x的数据个数
    void Clear();
};

// 尾插法创建链表
void List::TailCreate(int n) {
    if (n <= 0) return;
    NODE *q = head;
    for (int i = 0; i < n; i++) {
        NODE *p = (NODE *) malloc(sizeof(NODE));
        if (p == NULL) {  // 检查内存分配是否成功
            printf("Memory allocation failed\n");
            return;
        }
        p->data = rand() % 100;  // 生成随机数据
        p->next = NULL;
        q->next = p;
        q = p;
    }
}
void List::Init() {
    head = (struct NODE *) malloc(sizeof(NODE));
    head->data = 0;  // 初始化头节点的数据为0
    head->next = NULL;
}


// 头插法创建链表
void List::HeadCreate(int n) {
    if (n <= 0) return;
    for (int i = 0; i < n; i++) {
        NODE *p = (NODE *) malloc(sizeof(NODE));
        if (p == NULL) {  // 检查内存分配是否成功
            printf("Memory allocation failed\n");
            return;
        }
        p->data = rand() % 100;  // 生成随机数据
        p->next = head->next;
        head->next = p;
    }
}

void List::Insert(int i, int x) {
    NODE *q = (NODE *) malloc(sizeof(NODE));
    q->data = x;
    q->next = NULL;

    // 如果 i <= 0，直接插入到链表头部
    if (i <= 0) {
        q->next = head->next;
        head->next = q;
        return;
    }

    NODE *p = head;
    int j = 0;

    // 找到第i个位置的前驱节点
    for (j = 0; j < i && p->next != NULL; j++) {
        p = p->next;
    }

    // 插入新节点
    q->next = p->next;
    p->next = q;
}


// 判断链表是否为空
bool List::Isempty() {
    return head->next == NULL;
}

// 删除操作
bool List::Delete(int i, int &e) {
    if (i < 0 || Isempty()) {
        return false;
    }
    NODE *p = head;
    NODE *q;

    // 如果删除的是第一个元素
    if (i == 0) {
        q = head->next;
        head->next = q->next;
        e = q->data;
        free(q);
        return true;
    }

    // 找到第i个位置的前驱节点
    for (int j = 0; j < i && p->next != NULL; j++) {
        p = p->next;
    }

    // 如果没有找到合适的位置
    if (p->next == NULL) {
        return false;
    }

    // 删除节点
    q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return true;
}

// 清空链表，释放所有节点
void List::Clear() {
    NODE *p = head->next;
    while (p != NULL) {
        NODE *temp = p;
        p = p->next;
        free(temp);
    }
    head->next = NULL;
}

#endif //STUDY_LINKLIST_H