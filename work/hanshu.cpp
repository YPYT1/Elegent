#include <cstdio>
#include<stdlib.h>
#ifdef _WIN32
#include <windows.h>

#endif
#ifndef STUDY_HANSHU_H

struct NODE {
    int data;
    struct NODE *next;
};
struct Llist {
    NODE *head; // 操作的数据
    void Init(); // 初始化：就是给变量赋初值
    void TailCreate(int n); // 尾插法
    void Traverse(); // 遍历
    //销毁线性表  -第四次作业
    void Destroy();
    //取第i个位置上的数据并保存在e中，若第i个结点存在返回true，并把第i个结点的值保存在e中，若不存在第i个结点则返回false
    bool Getelem(int &e, int i);
    //无序查找，返回结点的值为x的第一个结点的地址，无值为x的结点，则返回空（NULL).
    NODE* Unsortfind(int x);
};


// 初始化链表
void Llist::Init() {
    head = (struct NODE *) malloc(sizeof(NODE));
    head->next = NULL; // 初始化头结点
}

// 尾插法创建链表
void Llist::TailCreate(int n) {
    if (n <= 0) return;

    int i, x;
    char buffer[100];  // 用于存储输入
    NODE *q, *p;
    q = head;  // 尾指针

    for (i = 0; i < n; i++) {
        p = (NODE *) malloc(sizeof(NODE));
        printf("请输入第%d个节点的值：", i + 1);

        // 使用 fgets 获取输入，并用 sscanf 解析整数
        while (1) {
            if (fgets(buffer, sizeof(buffer), stdin) == NULL || sscanf(buffer, "%d", &x) != 1) {
                printf("输入错误，请输入整数。\n");
                continue;  // 重新请求输入
            }
            break;  // 输入正确，退出循环
        }

        p->data = x;
        p->next = NULL;
        q->next = p;
        q = p;
    }
}

// 遍历输出链表
void Llist::Traverse() {
    NODE *p = head->next;
    if (p == NULL) {
        printf("链表为空\n");
        return;
    }
    while (p != NULL) {
        printf("%d", p->data);
        if (p->next != NULL) {
            printf(" ");  // 如果不是最后一个节点，输出一个空格
        }
        p = p->next;
    }
    printf("\n");  // 所有输出完成后再换行
}

NODE *Llist::Unsortfind(int x) {
    NODE *current = head->next;
    while (current !=NULL){
        if (current->data == x){
            return current;
        }
        current = current->next;
    }
    return NULL;
}
bool Llist::Getelem(int &e, int i) {
    NODE* p = head->next;
    int j= 1;
    while (p!=NULL && j<i){
        p = p->next;
        j++;
    }
    if (p!=NULL && j ==i){
        e= p->data;
        return true;
    }
    return false;
}
void Llist::Destroy() {
    NODE *current  = head->next;
    NODE *nextNode;
    while (current!=NULL){
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    head->next = NULL;
    free(head);
    printf("链表已销毁。\n");
}
#endif // STUDY_HANSHU_H

int main() {
/*#ifdef _WIN32
    SetConsoleOutputCP(65001); // 设置控制台输出为UTF-8
#endif*/
    Llist ls;
    ls.Init();
    printf("创建链表\n");

    ls.TailCreate(5);
    printf("链表内容: ");
    ls.Traverse();

    int findValue;
    char buffer[100];  // 用于存储输入

    printf("请输入要查找的值：");
    // 使用 fgets 读取输入并用 sscanf 解析整数
    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL || sscanf(buffer, "%d", &findValue) != 1) {
            printf("输入错误，请输入整数。\n");
            printf("请输入要查找的值：");
            continue;  // 重新请求输入
        }
        break;  // 输入正确，退出循环
    }

    NODE *foundNode = ls.Unsortfind(findValue);
    if (foundNode != NULL) {
        printf("找到值为 %d 的节点，节点地址为: %p\n", foundNode->data, (void *) foundNode);
    } else {
        printf("未找到值为 %d 的节点\n", findValue);
    }
    int index, element;
    printf("要查找节点的位置：");
    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL || sscanf(buffer, "%d", &index) != 1) {
            printf("输入错误，请输入整数。\n");
            printf("请输入要查找的节点位置：");
            continue;
        }
        break;
    }
    if (ls.Getelem(element,index)){
        printf("第%d个节点的值是：%d\n", index, element);
    } else {
        printf("没有找到第%d个节点\n", index);
    }
    ls.Destroy();
    return 0;
}

