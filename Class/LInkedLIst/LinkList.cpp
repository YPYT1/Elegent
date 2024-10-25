
#include <ctime>
#include "LinkList.h"

int main(){
    srand((unsigned) time(NULL));
    List la;
    la.Init();
//    la.TailCreate(15);
    la.HeadCreate(15);
    la.Traverse();
    return 0;
}