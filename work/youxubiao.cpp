#include <stdio.h>

#define MAX_SIZE 100  // ����˳������󳤶�

// �ϲ���������˳���ʹ�ϲ����˳�����Ȼ����
void merge(int list1[], int len1, int list2[], int len2, int mergedList[]) {
    int i = 0, j = 0, k = 0;

    // ��˳���������е�Ԫ�ط���ϲ���ı���
    while (i < len1 && j < len2) {
        if (list1[i] <= list2[j]) {
            mergedList[k++] = list1[i++];
        } else {
            mergedList[k++] = list2[j++];
        }
    }

    // ��ʣ���Ԫ�����η���ϲ���ı���
    while (i < len1) {
        mergedList[k++] = list1[i++];
    }
    while (j < len2) {
        mergedList[k++] = list2[j++];
    }
}

int main() {
    int list1[MAX_SIZE], list2[MAX_SIZE], mergedList[MAX_SIZE * 2];
    int len1, len2, i;

    // �����һ������˳���
    printf("�������һ������˳���ĳ���: ");
    scanf("%d", &len1);
    printf("�������һ������˳����Ԫ��: ");
    for (i = 0; i < len1; i++) {
        scanf("%d", &list1[i]);
    }

    // ����ڶ�������˳���
    printf("������ڶ�������˳���ĳ���: ");
    scanf("%d", &len2);
    printf("������ڶ�������˳����Ԫ��: ");
    for (i = 0; i < len2; i++) {
        scanf("%d", &list2[i]);
    }

    // �ϲ�����˳���
    merge(list1, len1, list2, len2, mergedList);

    // ����ϲ����˳���
    printf("�ϲ��������˳���Ϊ: ");
    for (i = 0; i < len1 + len2; i++) {
        printf("%d ", mergedList[i]);
    }
    printf("\n");

    return 0;
}
