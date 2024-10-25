#include "stack.h"

int main() {
    Lstack lstack; // ������ջʵ��
    lstack.Init(); // ��ʼ����ջ

    // ������ջ
    printf("��ջ����:\n");
    for (int i = 1; i <= 5; i++) {
        if (lstack.push(i)) {
            printf("�ɹ���ջ: %d\n", i);
        } else {
            printf("��ջʧ��: %d\n", i);
        }
    }

    // ������ջ
    printf("��ǰ��ջԪ��: ");
    lstack.Traverse();

    // ��ȡջ��Ԫ��
    SElemType topElem;
    if (lstack.getTopElem(topElem)) {
        printf("ջ��Ԫ��: %d\n", topElem);
    } else {
        printf("��ջΪ�գ��޷���ȡջ��Ԫ�ء�\n");
    }

    // ���Գ�ջ
    printf("��ջ����:\n");
    SElemType popped;
    while (lstack.pop(popped)) {
        printf("�ɹ���ջ: %d\n", popped);
    }

    // ���ձ�����ջ
    printf("��ջ�����ջԪ��: ");
    lstack.Traverse();

    // ������ջ���ͷ��ڴ�
    lstack.Destroy();

    return 0;
}
