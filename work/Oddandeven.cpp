#include <cstdio>

#define MaxSize 50

// 声明线性表结构体
struct Sqlist {
    int data[MaxSize];  // 操作的数据
    int length;  // 记录线性表中的数据长度
    void Init();  // 初始化线性表
    void Traverse();  // 遍历并输出线性表
    bool Insert(int i, int x);  // 插入操作
    bool Isfull() const {  // 判断线性表是否已满
        return length == MaxSize;
    }
};

void Oddandevent(Sqlist &la);

// 线性表的初始化
void Sqlist::Init() {
    length = 0;  // 初始化长度为0
}

// 遍历线性表并输出
void Sqlist::Traverse() {
    for (int i = 0; i < length; i++) {
        printf("\tx = %d", data[i]);
    }
    printf("\n");
}

// 插入操作
bool Sqlist::Insert(int i, int x) {
    if (i < 0 || i > length || Isfull()) {
        return false;
    }
    // 移动数据，腾出插入位置
    for (int k = length - 1; k >= i; k--) {
        data[k + 1] = data[k];
    }
    data[i] = x;  // 插入数据
    length++;  // 更新长度
    return true;
}

int main() {
    Sqlist la;
    la.Init();

    // 插入测试数据
    la.Insert(0, 12);
    la.Insert(1, 7);
    la.Insert(2, 9);
    la.Insert(3, 16);
    la.Insert(4, 25);
    la.Insert(5, 30);
    la.Insert(6, 43);
    la.Insert(7, 50);
    la.Insert(8, 51);
    la.Insert(9, 52);
    la.Insert(10, 53);
    la.Insert(11, 56);

    // 输出原始线性表
    printf("原始线性表:\n");
    la.Traverse();

    // 调用 Oddandevent 函数进行奇偶调整
    Oddandevent(la);

    // 输出调整后的线性表
    printf("奇数在前，偶数在后的线性表:\n");
    la.Traverse();

    return 0;
}

void Oddandevent(Sqlist &la) {
    int odd[MaxSize], even[MaxSize]; // 创建两个临时数组，分别存放奇数和偶数
    int oddCount = 0, evenCount = 0;

    // 遍历线性表，将奇数和偶数分别放入对应的临时数组
    for (int i = 0; i < la.length; i++) {
        if (la.data[i] % 2 != 0) {
            odd[oddCount++] = la.data[i];  // 奇数放入 odd 数组
        } else {
            even[evenCount++] = la.data[i];  // 偶数放入 even 数组
        }
    }

    // 将奇数重新写回线性表的前半部分
    for (int i = 0; i < oddCount; i++) {
        la.data[i] = odd[i];
    }

    // 将偶数写回线性表的后半部分
    for (int i = 0; i < evenCount; i++) {
        la.data[oddCount + i] = even[i];
    }
}