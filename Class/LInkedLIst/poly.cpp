#include <stdio.h>
#include "poly.h"  // 假设您的多项式类定义在 poly.h 文件中

int main() {
    Poly polyA, polyB, resultPoly;
    polyA.Init();
    polyB.Init();
    resultPoly.Init();

    // 创建多项式A
    printf("创建多项式A:\n");
    polyA.createpoly(3);  // 创建4项的多项式
    printf("多项式A: ");
    polyA.Traverse();

    // 创建多项式B
    printf("\n创建多项式B:\n");
    polyB.createpoly(3);  // 创建3项的多项式
    printf("多项式B: ");
    polyB.Traverse();

    // 执行加法运算
    printf("\n计算A + B:\n");
    polyA.Add3(polyA, polyB, resultPoly);
    printf("结果: ");
    resultPoly.Traverse();
/*
    // 测试特殊情况：相同指数项相加为零
    Poly polyC, polyD, resultCD;
    polyC.Init();
    polyD.Init();
    resultCD.Init();

    // 创建多项式C: 3x^2 + 5x^3
    Pnode *nodeC1 = new Pnode{{3, 2}, nullptr};  // 使用 shuju 替代 Data
    Pnode *nodeC2 = new Pnode{{5, 3}, nullptr};  // 使用 shuju 替代 Data
    polyC.head->next = nodeC1;
    nodeC1->next = nodeC2;

    // 创建多项式D: -3x^2 + 2x^4
    Pnode *nodeD1 = new Pnode{{-3, 2}, nullptr}; // 使用 shuju 替代 Data
    Pnode *nodeD2 = new Pnode{{2, 4}, nullptr};  // 使用 shuju 替代 Data
    polyD.head->next = nodeD1;
    nodeD1->next = nodeD2;

    printf("\n测试特殊情况：\n");
    printf("多项式C: ");
    polyC.Traverse();
    printf("多项式D: ");
    polyD.Traverse();

    printf("计算C + D:\n");
    polyC.Add3(polyC, polyD, resultCD);
    printf("结果: ");
    resultCD.Traverse();

    // 测试空多项式情况
    Poly emptyPoly;
    emptyPoly.Init();
    Poly resultEmpty;
    resultEmpty.Init();

    printf("\n测试空多项式：\n");
    printf("计算A + 空多项式:\n");
    polyA.Add3(polyA, emptyPoly, resultEmpty);
    resultEmpty.Traverse(); // 输出结果*/

    return 0;
}
