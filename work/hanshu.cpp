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
    NODE *head; // ����������
    void Init(); // ��ʼ�������Ǹ���������ֵ
    void TailCreate(int n); // β�巨
    void Traverse(); // ����
    //�������Ա�  -���Ĵ���ҵ
    void Destroy();
    //ȡ��i��λ���ϵ����ݲ�������e�У�����i�������ڷ���true�����ѵ�i������ֵ������e�У��������ڵ�i������򷵻�false
    bool Getelem(int &e, int i);
    //������ң����ؽ���ֵΪx�ĵ�һ�����ĵ�ַ����ֵΪx�Ľ�㣬�򷵻ؿգ�NULL).
    NODE* Unsortfind(int x);
};


// ��ʼ������
void Llist::Init() {
    head = (struct NODE *) malloc(sizeof(NODE));
    head->next = NULL; // ��ʼ��ͷ���
}

// β�巨��������
void Llist::TailCreate(int n) {
    if (n <= 0) return;

    int i, x;
    char buffer[100];  // ���ڴ洢����
    NODE *q, *p;
    q = head;  // βָ��

    for (i = 0; i < n; i++) {
        p = (NODE *) malloc(sizeof(NODE));
        printf("�������%d���ڵ��ֵ��", i + 1);

        // ʹ�� fgets ��ȡ���룬���� sscanf ��������
        while (1) {
            if (fgets(buffer, sizeof(buffer), stdin) == NULL || sscanf(buffer, "%d", &x) != 1) {
                printf("�������������������\n");
                continue;  // ������������
            }
            break;  // ������ȷ���˳�ѭ��
        }

        p->data = x;
        p->next = NULL;
        q->next = p;
        q = p;
    }
}

// �����������
void Llist::Traverse() {
    NODE *p = head->next;
    if (p == NULL) {
        printf("����Ϊ��\n");
        return;
    }
    while (p != NULL) {
        printf("%d", p->data);
        if (p->next != NULL) {
            printf(" ");  // ����������һ���ڵ㣬���һ���ո�
        }
        p = p->next;
    }
    printf("\n");  // ���������ɺ��ٻ���
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
    printf("���������١�\n");
}
#endif // STUDY_HANSHU_H

int main() {
/*#ifdef _WIN32
    SetConsoleOutputCP(65001); // ���ÿ���̨���ΪUTF-8
#endif*/
    Llist ls;
    ls.Init();
    printf("��������\n");

    ls.TailCreate(5);
    printf("��������: ");
    ls.Traverse();

    int findValue;
    char buffer[100];  // ���ڴ洢����

    printf("������Ҫ���ҵ�ֵ��");
    // ʹ�� fgets ��ȡ���벢�� sscanf ��������
    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL || sscanf(buffer, "%d", &findValue) != 1) {
            printf("�������������������\n");
            printf("������Ҫ���ҵ�ֵ��");
            continue;  // ������������
        }
        break;  // ������ȷ���˳�ѭ��
    }

    NODE *foundNode = ls.Unsortfind(findValue);
    if (foundNode != NULL) {
        printf("�ҵ�ֵΪ %d �Ľڵ㣬�ڵ��ַΪ: %p\n", foundNode->data, (void *) foundNode);
    } else {
        printf("δ�ҵ�ֵΪ %d �Ľڵ�\n", findValue);
    }
    int index, element;
    printf("Ҫ���ҽڵ��λ�ã�");
    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL || sscanf(buffer, "%d", &index) != 1) {
            printf("�������������������\n");
            printf("������Ҫ���ҵĽڵ�λ�ã�");
            continue;
        }
        break;
    }
    if (ls.Getelem(element,index)){
        printf("��%d���ڵ��ֵ�ǣ�%d\n", index, element);
    } else {
        printf("û���ҵ���%d���ڵ�\n", index);
    }
    ls.Destroy();
    return 0;
}

