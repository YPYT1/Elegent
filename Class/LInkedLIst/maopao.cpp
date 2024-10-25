#include <cstdlib>
#include <ctime>
#include "maopao.h"
#include "Sequential_List.h"

int main() {
    Sqlist la;      // ��ʼ�����Ա����
    la.Init();      // ��ʼ�����Ա�

    // �������һЩ���ݲ������Ա�
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        int value = rand() % 100;   // ����0��99֮��������
        la.Insert(i, value);        // ��ĩβ��������
    }

    printf("Before sorting:\n");
    la.Traverse();   // �������ǰ�����Ա�
    // ʹ�ÿ�������
    printf("Sorting using Insertion Sort:\n");
    QuickSort(la, 0, la.length - 1);
//    InsertSort(la);
    la.Traverse();   // ����������������Ա�

    return 0;
}

