#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-declarations"

#ifndef STUDY_LINKEDLIST_H
#define STUDY_LINKEDLIST_H

struct Node {
    int data;
    struct Node *next;
};
struct Node *head;

/*struct Node {
    int data;
    struct Node *next;
};
struct Node *head;
void Print() {
    struct Node* temp = head;
    printf("List is:");
    while (temp != NULL){
        printf("%d",temp ->data);
        temp = temp -> next;
        printf("\n");
    }
    printf("\n");
}

void Insert(int x) {
    Node *temp = (Node *) malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
}*/

void Insert(int x) {
    Node *temp = (Node *) malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    temp->next = head;
    head = temp;
}

void Print() {
    Node *temp = head;
    printf("List is:");
    while (temp != NULL) {
        printf("%2d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Delete(int n) {
    struct Node *temp1 = head;

}

#endif //STUDY_LINKEDLIST_H
#pragma clang diagnostic pop