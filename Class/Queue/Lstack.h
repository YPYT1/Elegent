#include <iostream>    // 包含标准输入输出头文件
#include <stdexcept>   // 包含std::out_of_range的头文件

struct Node {
    int data;
    Node* next;
};

class Lstack {
private:
    Node* top;

public:
    Lstack() {
        top = nullptr;
    }

    ~Lstack() {
        while (!IsEmpty()) {
            Pop();
        }
    }

    void Push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    int Pop() {
        if (IsEmpty()) {
            throw std::out_of_range("Stack is empty!");
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    bool IsEmpty() {
        return top == nullptr;
    }
};
