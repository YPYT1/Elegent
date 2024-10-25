#include "LinkQueue.h"

// ���������ڲ���
int main(){
    Squeue q;      // �������ж���
    int x;

    q.Init();      // ��ʼ������

    // ��Ӳ���
    q.Enterqueue(10);
    q.Enterqueue(20);
    q.Enterqueue(30);
    q.Enterqueue(40);
    q.Enterqueue(50);

    // ��������
    q.Traverse();  // ���: ����Ԫ��:   10   20   30   40   50

    // ��ȡ��ͷԪ��
    if(q.Getheadlem(x)){
        printf("��ͷԪ��: %d\n", x); // ���: ��ͷԪ��: 10
    }

    // ���Ӳ���
    if(q.Outqueue(x)){
        printf("����Ԫ��: %d\n", x); // ���: ����Ԫ��: 10
    }

    // �ٴα�������
    q.Traverse();  // ���: ����Ԫ��:   20   30   40   50

    // ��ȡ���г���
    printf("���г��� = %d\n", q.Len()); // ���: ���г��� = 4

    q.Traverse(); // ���: ����Ϊ�ա�

    return 0;
}