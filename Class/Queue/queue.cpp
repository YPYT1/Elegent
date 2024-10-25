#include "queue.h"

int main(){
    Squeue q;
    int x;
    q.Init();
    q.Enterqueue(10);
    q.Enterqueue(20);
    q.Enterqueue(30);
    q.Enterqueue(30);
    q.Enterqueue(30);
    q.Traverse();
    q.Getheadlem(x);
    q.Traverse();
    printf("length = %d\n",q.Len());
    return 0;
}