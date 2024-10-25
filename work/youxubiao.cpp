#include <stdio.h>

#define MAX_SIZE 100  // 定义顺序表的最大长度

// 合并两个有序顺序表，使合并后的顺序表依然有序
void merge(int list1[], int len1, int list2[], int len2, int mergedList[]) {
    int i = 0, j = 0, k = 0;

    // 按顺序将两个表中的元素放入合并后的表中
    while (i < len1 && j < len2) {
        if (list1[i] <= list2[j]) {
            mergedList[k++] = list1[i++];
        } else {
            mergedList[k++] = list2[j++];
        }
    }

    // 将剩余的元素依次放入合并后的表中
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

    // 输入第一个有序顺序表
    printf("请输入第一个有序顺序表的长度: ");
    scanf("%d", &len1);
    printf("请输入第一个有序顺序表的元素: ");
    for (i = 0; i < len1; i++) {
        scanf("%d", &list1[i]);
    }

    // 输入第二个有序顺序表
    printf("请输入第二个有序顺序表的长度: ");
    scanf("%d", &len2);
    printf("请输入第二个有序顺序表的元素: ");
    for (i = 0; i < len2; i++) {
        scanf("%d", &list2[i]);
    }

    // 合并两个顺序表
    merge(list1, len1, list2, len2, mergedList);

    // 输出合并后的顺序表
    printf("合并后的有序顺序表为: ");
    for (i = 0; i < len1 + len2; i++) {
        printf("%d ", mergedList[i]);
    }
    printf("\n");

    return 0;
}
