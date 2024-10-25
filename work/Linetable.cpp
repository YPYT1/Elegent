#include <stdio.h>
#define MaxSize 50

// �������Ա�ṹ��
struct Sqlist {
    int data[MaxSize];  // ����������
    int length;  // ��¼���Ա��е����ݳ���
    void Init();  // ��ʼ�����Ա�
    void Traverse();  // ������������Ա�
    bool Insert(int i, int x);  // �������
    bool Isfull() {  // �ж����Ա��Ƿ�����
        return length == MaxSize;
    }
};

// ��������
void Deduplication(Sqlist &la);
void Union(Sqlist &la, Sqlist &lb, Sqlist &lc);

// ���Ա�ĳ�ʼ��
void Sqlist::Init() {
    length = 0;  // ��ʼ������Ϊ0
}

// �������Ա����
void Sqlist::Traverse() {
    for (int i = 0; i < length; i++) {
        printf("\tx = %d", data[i]);
    }
    printf("\n");
}

// �������
bool Sqlist::Insert(int i, int x) {
    if (i < 0 || i > length || Isfull()) {
        return false;
    }
    // �ƶ����ݣ��ڳ�����λ��
    for (int k = length - 1; k >= i; k--) {
        data[k + 1] = data[k];
    }
    data[i] = x;  // ��������
    length++;  // ���³���
    return true;
}

int main() {
    Sqlist la, lb, lc;  // �������Ա���
    la.Init();  // ��ʼ������ la
    lb.Init();  // ��ʼ������ lb
    lc.Init();  // ��ʼ������ lc

    // ������ la ����һЩ����
    la.Insert(0, 10);
    la.Insert(1, 20);
    la.Insert(2, 30);
    la.Insert(3, 40);
    la.Insert(4, 50);
    la.Insert(5, 20);  // �ظ�Ԫ��
    la.Insert(6, 30);  // �ظ�Ԫ��

    // ������ lb ����һЩ����
    lb.Insert(0, 30);
    lb.Insert(1, 40);
    lb.Insert(2, 50);
    lb.Insert(3, 60);
    lb.Insert(4, 70);
    lb.Insert(5, 30);  // �ظ�Ԫ��
    lb.Insert(6, 40);  // �ظ�Ԫ��

    printf("ԭʼ����la:\n");
    la.Traverse();
    // ȥ��
    Deduplication(la);
    printf("����laȥ�غ�:\n");
    la.Traverse();

    printf("ԭʼ����lb:\n");
    lb.Traverse();
    Deduplication(lb);
    printf("����lbȥ�غ�:\n");
    lb.Traverse();

    // �󲢼�
    Union(la, lb, lc);
    printf("la��lb�󲢼���:\n");
    lc.Traverse();

    return 0;
}

// ȥ�غ���
void Deduplication(Sqlist &la) {
    for (int i = 0; i < la.length - 1; i++) {
        for (int j = i + 1; j < la.length; j++) {
            if (la.data[i] == la.data[j]) {
                // �ҵ��ظ���Ԫ�أ�ɾ����
                for (int k = j; k < la.length - 1; k++) {
                    la.data[k] = la.data[k + 1];  // �������Ԫ����ǰ�ƶ�
                }
                la.length--;
                j--;
            }
        }
    }
}

// ��������
void Union(Sqlist &la, Sqlist &lb, Sqlist &lc) {
    // �Ƚ����� la ��Ԫ�ظ��Ƶ� lc ��
    for (int i = 0; i < la.length; i++) {
        lc.Insert(i, la.data[i]);
    }

    // �������� lb�������� lc �е�Ԫ�ز��뵽 lc ��
    for (int i = 0; i < lb.length; i++) {
        bool found = false;
        for (int j = 0; j < lc.length; j++) {
            if (lb.data[i] == lc.data[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            lc.Insert(lc.length, lb.data[i]);  // ���벻�ظ���Ԫ��
        }
    }
    Deduplication(lc);
}
