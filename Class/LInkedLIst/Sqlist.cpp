#include <cstdlib>
#include <ctime>
#include "Sqlist.h"
#include "Sequential_List.h"

int main() {
    struct Sqlist la, lb, lc;
    lb.Init();
    lc.Init();
    la.Init();
    int i, x;
    srand((unsigned) time(0));
    for (i = 0; i < MaxSize; i++) {
        x = rand() % 4;
        la.Insert(i, x);
    }
    for (i = 0; i < la.length; i++) {
        x = rand() % 13;
        lb.Traverse();
    }
    la.Traverse();
    lb.Traverse();
    Jjiaojie(la,lb,lc);
    lc.Traverse();
    return 0;
}
