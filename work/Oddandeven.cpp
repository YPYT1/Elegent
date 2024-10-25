#include <cstdio>

#define MaxSize 50

// �������Ա�ṹ��
struct Sqlist {
    int data[MaxSize];  // ����������
    int length;  // ��¼���Ա��е����ݳ���
    void Init();  // ��ʼ�����Ա�
    void Traverse();  // ������������Ա�
    bool Insert(int i, int x);  // �������
    bool Isfull() const {  // �ж����Ա��Ƿ�����
        return length == MaxSize;
    }
};

void Oddandevent(Sqlist &la);

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
    Sqlist la;
    la.Init();

    // �����������
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

    // ���ԭʼ���Ա�
    printf("ԭʼ���Ա�:\n");
    la.Traverse();

    // ���� Oddandevent ����������ż����
    Oddandevent(la);

    // �������������Ա�
    printf("������ǰ��ż���ں�����Ա�:\n");
    la.Traverse();

    return 0;
}

void Oddandevent(Sqlist &la) {
    int odd[MaxSize], even[MaxSize]; // ����������ʱ���飬�ֱ���������ż��
    int oddCount = 0, evenCount = 0;

    // �������Ա���������ż���ֱ�����Ӧ����ʱ����
    for (int i = 0; i < la.length; i++) {
        if (la.data[i] % 2 != 0) {
            odd[oddCount++] = la.data[i];  // �������� odd ����
        } else {
            even[evenCount++] = la.data[i];  // ż������ even ����
        }
    }

    // ����������д�����Ա��ǰ�벿��
    for (int i = 0; i < oddCount; i++) {
        la.data[i] = odd[i];
    }

    // ��ż��д�����Ա�ĺ�벿��
    for (int i = 0; i < evenCount; i++) {
        la.data[oddCount + i] = even[i];
    }
}