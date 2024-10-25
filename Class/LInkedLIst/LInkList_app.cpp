#include <ctime>
#include <cstdio>
#include "LinkList_app.h"

// �����½ڵ�
NODE *createNode(int data) {
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// ��ʼ������
void initList(List *list, int arr[], int n) {
    list->head = createNode(0);  // ͷ�ڵ�
    NODE *current = list->head;
    for (int i = 0; i < n; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }
}

int main() {
    // ��������1
    List la, lb;

    // ��ʼ��������������
    int arrA[] = {4, 3, 1, 7};
    int arrB[] = {2, 9, 4, 8};

    initList(&la, arrA, 4);
    initList(&lb, arrB, 4);

    printf("����A: ");
    la.Traverse();

    printf("����B: ");
    lb.Traverse();

    // �ϲ�����
    Meger2(la, lb);

    printf("�ϲ��������: ");
    la.Traverse();

    return 0;
}
