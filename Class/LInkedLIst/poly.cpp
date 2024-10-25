#include <stdio.h>
#include "poly.h"  // �������Ķ���ʽ�ඨ���� poly.h �ļ���

int main() {
    Poly polyA, polyB, resultPoly;
    polyA.Init();
    polyB.Init();
    resultPoly.Init();

    // ��������ʽA
    printf("��������ʽA:\n");
    polyA.createpoly(3);  // ����4��Ķ���ʽ
    printf("����ʽA: ");
    polyA.Traverse();

    // ��������ʽB
    printf("\n��������ʽB:\n");
    polyB.createpoly(3);  // ����3��Ķ���ʽ
    printf("����ʽB: ");
    polyB.Traverse();

    // ִ�мӷ�����
    printf("\n����A + B:\n");
    polyA.Add3(polyA, polyB, resultPoly);
    printf("���: ");
    resultPoly.Traverse();
/*
    // ���������������ָͬ�������Ϊ��
    Poly polyC, polyD, resultCD;
    polyC.Init();
    polyD.Init();
    resultCD.Init();

    // ��������ʽC: 3x^2 + 5x^3
    Pnode *nodeC1 = new Pnode{{3, 2}, nullptr};  // ʹ�� shuju ��� Data
    Pnode *nodeC2 = new Pnode{{5, 3}, nullptr};  // ʹ�� shuju ��� Data
    polyC.head->next = nodeC1;
    nodeC1->next = nodeC2;

    // ��������ʽD: -3x^2 + 2x^4
    Pnode *nodeD1 = new Pnode{{-3, 2}, nullptr}; // ʹ�� shuju ��� Data
    Pnode *nodeD2 = new Pnode{{2, 4}, nullptr};  // ʹ�� shuju ��� Data
    polyD.head->next = nodeD1;
    nodeD1->next = nodeD2;

    printf("\n�������������\n");
    printf("����ʽC: ");
    polyC.Traverse();
    printf("����ʽD: ");
    polyD.Traverse();

    printf("����C + D:\n");
    polyC.Add3(polyC, polyD, resultCD);
    printf("���: ");
    resultCD.Traverse();

    // ���Կն���ʽ���
    Poly emptyPoly;
    emptyPoly.Init();
    Poly resultEmpty;
    resultEmpty.Init();

    printf("\n���Կն���ʽ��\n");
    printf("����A + �ն���ʽ:\n");
    polyA.Add3(polyA, emptyPoly, resultEmpty);
    resultEmpty.Traverse(); // ������*/

    return 0;
}
