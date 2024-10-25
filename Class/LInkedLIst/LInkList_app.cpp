#include <ctime>
#include <cstdio>
#include "LinkList_app.h"

// 创建新节点
NODE *createNode(int data) {
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// 初始化链表
void initList(List *list, int arr[], int n) {
    list->head = createNode(0);  // 头节点
    NODE *current = list->head;
    for (int i = 0; i < n; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }
}

int main() {
    // 测试用例1
    List la, lb;

    // 初始化两个有序链表
    int arrA[] = {4, 3, 1, 7};
    int arrB[] = {2, 9, 4, 8};

    initList(&la, arrA, 4);
    initList(&lb, arrB, 4);

    printf("链表A: ");
    la.Traverse();

    printf("链表B: ");
    lb.Traverse();

    // 合并链表
    Meger2(la, lb);

    printf("合并后的链表: ");
    la.Traverse();

    return 0;
}
