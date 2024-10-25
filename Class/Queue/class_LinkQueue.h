#ifndef STUDY_CLASS_LINKQUEUE_H
#define STUDY_CLASS_LINKQUEUE_H

struct NODE{
    int data;           // 节点存储的数据
    struct NODE* next; // 指向下一个节点的指针
}NODE;
struct Lqueue{
    struct NODE* front;
    struct NODE* rear;
    bool Getheadelem(int &e);

    int Len();
};

bool Isempyt();

int Lqueue::Len(){
    int k =0;

}
bool Lqueue::Getheadelem(int &e){

}
void Lqueue::Destory(){
    int x;
    for (; Isempyt() == false ; ) {
        Outqueue(x)
    }
}

bool Isempyt() {
    return false;
}

#endif //STUDY_CLASS_LINKQUEUE_H
