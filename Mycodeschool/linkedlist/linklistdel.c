#include <stdio.h>
#include <malloc.h>

typedef struct Node Node;
struct Node {
    int data;
    struct Node *next;
};
struct Node *head = NULL;

void HeadInsert(int data) {
    struct Node *temp = (Node *) malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    temp->next = head;
    head = temp;
};

void TailInsert(int data) {
    struct Node *temp = (Node *) malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
    } else {
        struct Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }
};

void Print() {
    struct Node *current = head;
    int isFrist = 1;
    while (current != NULL) {
        if (isFrist) {
            printf("%d", current->data);
            isFrist = 0;
        } else {
            printf(" %d", current->data);
        }
        current = current->next;
    }
    printf("\n");
};

void Delete(int n) {
    struct Node *temp = head;
    if (n == 1) {
        head = head->next;
        free(temp);
        return;
    }
    struct Node *prev = NULL;
    for (int i = 1; i < n; i++) {
        prev = temp;
        temp = temp->next;
        if (temp->next == NULL) {
            printf("The node number is out of range.\n");
            return;
        }
    }
    prev->next = temp->next;
    free(temp);
    Print();
};

//迭代器方式实现
void Rollback() {
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev; // NULL
        prev = current;
        current = next;
    }
    head = prev;
};

//递归反转函数
struct Node* ReverseRecursive(struct Node *head) {
    if (head == NULL || head->next == NULL)return head;
    // Recursive call to reverse the rest of the list
    struct Node *newHead = ReverseRecursive(head->next);
    // Adjust pointers
    head->next->next = head;
    head->next = NULL;

    // Return new head
    return newHead;
};
struct Node* ReverseRecursive2(struct Node *head) {
    if (head == NULL || head->next == NULL)return head;
    // Recursive call to reverse the rest of the list
    struct Node *newHead = ReverseRecursive(head->next);
    // Adjust pointers
    head->next->next = head;
    head->next = NULL;

    // Return new head
    return newHead;
};
//递归打印辅助函数
void PrintRecursiveHelp(struct Node *current, int frist) {
    if (current == NULL)return;
    if (frist) {
        printf("%d", current->data);
    } else {
        printf(" %d", current->data);
    }
    PrintRecursiveHelp(current->next, 0);
}

//递归打印函数
void PrintRecursive(struct Node *current) {
    PrintRecursiveHelp(head, 1);
//    printf("\n");
};

int main() {
    TailInsert(1);
    TailInsert(2);
    TailInsert(3);
    TailInsert(4);
    TailInsert(5);

    printf("Original List: ");
    PrintRecursive(head);

    // Reverse the list recursively
    head = ReverseRecursive(head);

    printf("Reversed List: ");
    PrintRecursive(head);

    return 0;
}
